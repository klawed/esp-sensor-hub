#!/usr/bin/env python3

import os
import json

# Create output directories
os.makedirs('web', exist_ok=True)

# Create a dummy binary file for testing
# In a real setup, this would be replaced with actual firmware
if not os.path.exists('web/esp32.bin'):
    with open('web/esp32.bin', 'wb') as f:
        # Create a minimal binary just for testing
        f.write(b'\x00' * 1024)

# Create manifest file for ESP Web Tools
manifest = {
    "name": "ESP Sensor Hub",
    "version": "1.0.0",
    "home_assistant_domain": "esphome",
    "new_install_skip_erase": False,
    "builds": [
        {
            "chipFamily": "ESP32",
            "parts": [
                {"path": "esp32.bin", "offset": 0}
            ]
        }
    ]
}

# Write manifest to file
with open('web/esp-webtool-manifest.json', 'w') as f:
    json.dump(manifest, f, indent=2)

# Create simple HTML page with ESP Web Tools
html = """<!DOCTYPE html>
<html>

<head>
  <title>ESP Sensor Hub Installer</title>
  <script type="module">import espWebTools from 'https://cdn.jsdelivr.net/npm/esp-web-tools@9.4.0/+esm'</script>
  <style>
    body {
      font-family: Arial, sans-serif;
      max-width: 800px;
      margin: 0 auto;
      padding: 20px;
      line-height: 1.6;
    }
    h1 {
      color: #333;
    }
    .container {
      border: 1px solid #ddd;
      border-radius: 5px;
      padding: 20px;
      margin-top: 20px;
    }
    .instructions {
      margin-top: 30px;
    }
    .instructions ol {
      margin-left: 20px;
    }
    esp-web-install-button {
      margin: 20px 0;
    }
  </style>
</head>

<body>
  <h1>ESP Sensor Hub Installer</h1>
  
  <div class="container">
    <p>This tool allows you to install the ESP Sensor Hub firmware directly from your browser. No need for Arduino IDE or PlatformIO!</p>
    
    <esp-web-install-button manifest="esp-webtool-manifest.json"></esp-web-install-button>
    
    <div class="instructions">
      <h2>Instructions:</h2>
      <ol>
        <li>Plug your ESP32 board into your computer's USB port</li>
        <li>Click the Install button above</li>
        <li>Select the correct port when prompted</li>
        <li>Wait for the installation to complete</li>
        <li>Disconnect and reconnect your device to start using it</li>
      </ol>
    </div>
  </div>
</body>

</html>"""

# Write HTML to file
with open('web/index.html', 'w') as f:
    f.write(html)

print("ESP Web Tools files generated successfully!")
print("- web/esp32.bin (dummy file for testing)")
print("- web/esp-webtool-manifest.json")
print("- web/index.html")