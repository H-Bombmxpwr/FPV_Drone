#include <WiFi.h>

// ===========================
// Enter your WiFi credentials
// ===========================
const char* ssid = "ESP32 Headset Board";
const char* password = "beepboop";

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  WiFi.softAP(ssid, password);
  Serial.print("Wifi IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Do nothing. Everything is done in another task by the web server
  delay(10000);
}
