# Webserver Code
## Environment Setup
Follow this [link](https://randomnerdtutorials.com/installing-esp32-arduino-ide-2-0/) to setup the Arduino IDE.

The ESP32 Board is "AI Thinker ESP32-CAM" and the Headset Board is "ESP32 Wrover Module".

## Libraries
Download the [Micro-RTSP Repo](https://github.com/geeksville/Micro-RTSP). Then use Sketch->Include Library->Add .ZIP Library to install the library into your environment.
This library is used for the OV2640.h library that initalizes the camera and reads from the frame buffer.

# CSV Conversion Code
## Environement Setup
Follow this [link](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md) to setup the ESP IDF environment in Visual Studio Code.

## Libraries
The core library is [esp32_composite_video_lib](https://github.com/aquaticus/esp32_composite_video_lib). The demo library is [here](https://github.com/aquaticus/esp32_composite_video_demo).
