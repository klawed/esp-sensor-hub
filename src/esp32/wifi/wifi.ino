#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    4   // Reset pin # (or -1 if sharing Arduino reset pin)

// Variables for WiFi scanning
int currentAP = 0;
int totalAPs = 0;
int scrollPosition = 0;
unsigned long lastScanTime = 0;
const long scanInterval = 10000;  // Rescan every 10 seconds
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- Touch Pin Configuration ---
// GPIO4 (T0) is used for OLED_RESET, so we exclude it.
// GPIO0 (T1) can be used for BOOT button.
// GPIO2 (T2) can be used for onboard LED.
const int touchPins[] = {T1, T2, T3, T4, T5, T6, T7, T8, T9}; // T1=0, T2=2, T3=15, T4=13, T5=12, T6=14, T7=27, T8=33, T9=32
const int numTouchPins = sizeof(touchPins) / sizeof(touchPins[0]);
#define TOUCH_THRESHOLD 40 // Lower values mean a touch is more likely. Adjust this value.
bool touchDetectedFlag = false; // Flag to indicate if any touch was recently detected
#define MAX_TOUCHED_PINS 5
int touchedPins[MAX_TOUCHED_PINS];
int touchedValues[MAX_TOUCHED_PINS];
int numTouched = 0;

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
  display.println("WiFi & Touch Scan");
  display.println("Initializing...");
  display.display();
  delay(2000);
  
  // Set WiFi to station mode and disconnect from any previous connection
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  // Perform initial scans
  scanNetworks();
  scanI2C();
  scanTouchPins(); // Initial touch scan
}
 
void scanI2C() {
  byte error, address;
  int nDevices;
  Serial.println("Scanning I2C...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found.\n");
  }
  else {
    Serial.println("I2C scan done.\n");
  }
  // delay(5000); // Removed delay to make loop faster
}

void scanTouchPins() {
  touchDetectedFlag = false;
  numTouched = 0;
  for (int i = 0; i < numTouchPins; i++) {
    int touchVal = touchRead(touchPins[i]);
    if (touchVal < TOUCH_THRESHOLD && numTouched < MAX_TOUCHED_PINS) {
      touchedPins[numTouched] = touchPins[i];
      touchedValues[numTouched] = touchVal;
      numTouched++;
      touchDetectedFlag = true;

      Serial.print("Touch detected on Pin: GPIO");
      Serial.print(touchPins[i]); // Print the actual GPIO number
      Serial.print(" (T");
      // Find the T-number. This is a bit manual if not directly mapping.
      // For simplicity, we'll just print GPIO.
      // If you want T-numbers: T0=4, T1=0, T2=2, T3=15, T4=13, T5=12, T6=14, T7=27, T8=33, T9=32
      // This requires a mapping or smarter lookup.
      // For now, let's just identify by GPIO number.
      // You can find the actual T-designation from ESP32 datasheets based on the GPIO.
      int t_num = -1;
      switch(touchPins[i]){
        case 0: t_num = 1; break;
        case 2: t_num = 2; break;
        case 15: t_num = 3; break;
        case 13: t_num = 4; break;
        case 12: t_num = 5; break;
        case 14: t_num = 6; break;
        case 27: t_num = 7; break;
        case 33: t_num = 8; break;
        case 32: t_num = 9; break;
      }
      if (t_num != -1) {
        Serial.print(t_num);
      } else {
        Serial.print("?"); // Should not happen if touchPins array is correct
      }

      Serial.print("), Value: ");
      Serial.println(touchVal);
    }
    // Optional: Print all touch values for calibration
    // Serial.print("Pin GPIO"); Serial.print(touchPins[i]); Serial.print(": "); Serial.println(touchVal);
  }
  // if (touchDetectedFlag) {
  //   Serial.println("Touch scan done (detections found).\n");
  // } else {
  //   Serial.println("Touch scan done (no new detections).\n");
  // }
}


void loop() {
  // Rescan networks periodically
  if (millis() - lastScanTime > scanInterval) {
    scanNetworks();
    scanI2C();
    scanTouchPins(); // Scan touch pins periodically
    lastScanTime = millis();
  }
  
  // Display networks
  displayNetworks();
  
  // Cycle through networks every 2 seconds
  static unsigned long lastDisplayTime = 0;
  if (totalAPs > 0) { // Only cycle if there are APs
    if (millis() - lastDisplayTime > 2000) {
      lastDisplayTime = millis();
      currentAP = (currentAP + 1) % totalAPs;
      scrollPosition = 0; // Reset scroll for new AP
    }
  }
  
  delay(100); // Small delay to reduce flickering
}

void scanNetworks() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Scanning WiFi...");
  display.display();
  
  totalAPs = WiFi.scanNetworks(); // WiFi.scanNetworks will return the number of networks found
  // It's better to clear results before a new scan sometimes if issues occur,
  // but scanNetworks usually handles this.

  if (totalAPs == WIFI_SCAN_FAILED) { // Check for specific failure code
    Serial.println("WiFi Scan failed!");
    totalAPs = 0; // Ensure totalAPs is 0 on failure
  } else if (totalAPs == 0) {
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
      Serial.print("dBm) Enc: ");
      // Get more descriptive encryption type
      switch (WiFi.encryptionType(i)) {
        case WIFI_AUTH_OPEN:            Serial.print("Open"); break;
        case WIFI_AUTH_WEP:             Serial.print("WEP"); break;
        case WIFI_AUTH_WPA_PSK:         Serial.print("WPA_PSK"); break;
        case WIFI_AUTH_WPA2_PSK:        Serial.print("WPA2_PSK"); break;
        case WIFI_AUTH_WPA_WPA2_PSK:    Serial.print("WPA/WPA2_PSK"); break;
        case WIFI_AUTH_WPA2_ENTERPRISE: Serial.print("WPA2_Ent"); break;
        case WIFI_AUTH_WPA3_PSK:        Serial.print("WPA3_PSK"); break; // If supported by your ESP32 core
        case WIFI_AUTH_WPA2_WPA3_PSK:   Serial.print("WPA2/WPA3_PSK"); break; // If supported
        default:                        Serial.print("Unknown"); break;
      }
      Serial.println();
    }
  }
  
  currentAP = 0;
  scrollPosition = 0;
}

void displayNetworks() {
  display.clearDisplay();
  display.setCursor(0,0);

  if (totalAPs == 0) {
    display.println("No networks found");
    // Display touch status if any was detected in the last scanTouchPins cycle
    if (touchDetectedFlag) {
      display.setCursor(SCREEN_WIDTH - 18, 0); // Top right corner
      display.print("T!");
    }
    display.display();
    return;
  }
  
  // Display header
  display.print("WiFi: ");
  display.print(currentAP + 1);
  display.print("/");
  display.println(totalAPs);
  
  // Display current network info
  String ssid = WiFi.SSID(currentAP);
  int rssi = WiFi.RSSI(currentAP);
  String auth;
  switch (WiFi.encryptionType(currentAP)) {
    case WIFI_AUTH_OPEN:            auth = "Open"; break;
    case WIFI_AUTH_WEP:             auth = "WEP"; break;
    case WIFI_AUTH_WPA_PSK:         auth = "WPA"; break;
    case WIFI_AUTH_WPA2_PSK:        auth = "WPA2"; break;
    case WIFI_AUTH_WPA_WPA2_PSK:    auth = "WPA/WPA2"; break;
    case WIFI_AUTH_WPA2_ENTERPRISE: auth = "WPA2-Ent"; break;
    case WIFI_AUTH_WPA3_PSK:        auth = "WPA3"; break;
    case WIFI_AUTH_WPA2_WPA3_PSK:   auth = "WPA2/3"; break;
    default:                        auth = "Unknown"; break;
  }
  
  // Handle scrolling for long SSIDs
  const int maxSsidDisplayLength = 20;
  if (ssid.length() > maxSsidDisplayLength) {
    if (scrollPosition + maxSsidDisplayLength > ssid.length() && ssid.length() > maxSsidDisplayLength) {
        scrollPosition = 0; // Reset scroll if it goes too far or if ssid is just a bit longer
    }
    display.println(ssid.substring(scrollPosition, scrollPosition + maxSsidDisplayLength));
    if (millis() % 700 < 350) { // Slow down scroll update rate
      scrollPosition++;
    }
  } else {
    display.println(ssid);
  }
  
  display.print("RSSI: ");
  display.print(rssi);
  display.println(" dBm");
  
  display.print("Auth: ");
  display.println(auth);
  
  display.print("Bars: ");
  int bars = map(rssi, -90, -40, 0, 5); // Adjusted mapping for RSSI
  bars = constrain(bars, 0, 5);
  for (int i = 0; i < bars; i++) {
    display.print("|");
  }
  display.println(); // New line after bars

  // Display touch status if any was detected in the last scanTouchPins cycle
  if (touchDetectedFlag && numTouched > 0) {
    display.setCursor(SCREEN_WIDTH - 60, 0); // Adjust as needed for your display
    display.print("Touch:");
    for (int i = 0; i < numTouched; i++) {
      display.print(" ");
      display.print(touchedPins[i]);
      display.print("(");
      display.print(touchedValues[i]);
      display.print(")");
    }
  }
  
  display.display();
}