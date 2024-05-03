#include <OV2640.h>
#include <stdint.h>
#include <WiFi.h>
#include <WiFiUdp.h>
WiFiUDP udp;
char packetBuffer[255];
unsigned int localPort = 9999;
const char *ssid = "Griffins iPhone";
const char *password = "Griffin1";


OV2640 cam;

void setup() {
  cam.init(esp32cam_aithinker_config);
  Serial.begin(115200);
  // Connect to Wifi network.
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500); Serial.print(F("."));
  }
  udp.begin(localPort);
  Serial.printf("UDP Client : %s:%i \n", WiFi.localIP().toString().c_str(), localPort);
}

void loop() {
  cam.run();
  int packetSize = udp.parsePacket();
  Serial.print(" Received packet from : "); Serial.println(udp.remoteIP());
  Serial.print(" Size : "); Serial.println(packetSize);
  if (packetSize) {
    int len = udp.read(packetBuffer, 255);
    if (len > 0) packetBuffer[len - 1] = 0;
    Serial.printf("Data : %s\n", packetBuffer);
  }
  Serial.println("\n");
  delay(500);
  Serial.print("[Client Connected] ");
  Serial.println(WiFi.localIP());
  udp.beginPacket("172.20.10.9", localPort);
  Serial.println(cam.getSize());
  char buf[cam.getSize()];
  uint8_t* test = cam.getfb();
  buf[0] = (char) *(test);
  Serial.print(*test);
  //sprintf(buf, "%d", *test);
  udp.printf(buf);
  udp.printf("\r\n");
  udp.endPacket();
}
