#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Variables for WiFi scanning
int currentAP = 0;
int totalAPs = 0;
int scrollPosition = 0;
unsigned long lastScanTime = 0;
const long scanInterval = 10000;  // Rescan every 10 seconds

void setup() {
  Serial.begin(115200);
  
  // Initialize OLED with I2C address 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("WiFi Scanner");
  display.println("Initializing...");
  display.display();
  delay(2000);
  
  // Set WiFi to station mode and disconnect from any previous connection
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  // Perform initial scan
  scanNetworks();
}

void loop() {
  // Rescan networks periodically
  if (millis() - lastScanTime > scanInterval) {
    scanNetworks();
    lastScanTime = millis();
  }
  
  // Display networks
  displayNetworks();
  
  // Cycle through networks every 2 seconds
  static unsigned long lastDisplayTime = 0;
  if (millis() - lastDisplayTime > 2000) {
    lastDisplayTime = millis();
    currentAP = (currentAP + 1) % totalAPs;
    scrollPosition = 0;
  }
  
  delay(100); // Small delay to reduce flickering
}

void scanNetworks() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Scanning WiFi...");
  display.display();
  
  // WiFi.scanNetworks will return the number of networks found
  totalAPs = WiFi.scanNetworks();
  if (totalAPs == -1) {
    display.println("Scan failed!");
    display.display();
    return;
  }
  
  Serial.println("Scan complete");
  if (totalAPs == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print(totalAPs);
    Serial.println(" networks found");
    for (int i = 0; i < totalAPs; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(") ");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
    }
  }
  
  currentAP = 0;
  scrollPosition = 0;
}

void displayNetworks() {
  if (totalAPs == 0) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("No networks found");
    display.display();
    return;
  }
  
  display.clearDisplay();
  display.setCursor(0,0);
  
  // Display header
  display.print("Networks: ");
  display.print(currentAP + 1);
  display.print("/");
  display.println(totalAPs);
  
  // Display current network info
  String ssid = WiFi.SSID(currentAP);
  int rssi = WiFi.RSSI(currentAP);
  String auth = (WiFi.encryptionType(currentAP) == WIFI_AUTH_OPEN ? "Open" : "Secured";
  
  // Handle scrolling for long SSIDs
  if (ssid.length() > 20) {
    if (scrollPosition >= ssid.length() - 16) {
      scrollPosition = 0;
    }
    display.println(ssid.substring(scrollPosition, scrollPosition + 16));
    scrollPosition++;
  } else {
    display.println(ssid);
  }
  
  display.print("Signal: ");
  display.print(rssi);
  display.println(" dBm");
  
  display.print("Security: ");
  display.println(auth);
  
  // Display signal strength indicator
  display.print("Strength: ");
  int bars = map(rssi, -100, -50, 0, 5); // Convert RSSI to 0-5 bars
  bars = constrain(bars, 0, 5);
  for (int i = 0; i < bars; i++) {
    display.print("|");
  }
  
  display.display();
}