# Webserver Code
## Environment Setup
Follow this [link](https://randomnerdtutorials.com/installing-esp32-arduino-ide-2-0/) to setup the Arduino IDE.

The ESP32 Board is "AI Thinker ESP32-CAM" and the Headset Board is "ESP32 Wrover Module".

## Libraries
Download the [Micro-RTSP](https://github.com/geeksville/Micro-RTSP) repo. Then use Sketch->Include Library->Add .ZIP Library to install the library into your environment.
This library is used for the OV2640.h library that initalizes the camera and reads from the frame buffer.

## Running
video_webserver.ino runs on the ESP32-CAM board and basic_wifi_ap.ino runs on the headset board.

## Accessing the Webserver
Use the SSID and password at the top of either program (these must match) to connect an external computer to the WiFi network. Then go to 192.168.4.2 in a browse to start the webserver and view the camera feed. If you reconfigure the ESP32-CAM board to host its own WiFi, this IP address will change to 192.168.4.1.

# CSV Conversion Code
## Environement Setup
Follow this [link](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md) to setup the ESP IDF environment in Visual Studio Code.

## Libraries
The core library is [esp32_composite_video_lib](https://github.com/aquaticus/esp32_composite_video_lib). The demo library is [here](https://github.com/aquaticus/esp32_composite_video_demo). Download them and then load them through the ESP IDF Visual Studio Extension.

## Running
In order to get the correct demo video, make sure that the app_main(void) function in demo.c calls run_demo_slides();. By default the configurations may run another demo function.

In the Visual Studio Command Palette, use ESP-IDF: Select Port to Use, Set Espressif Device Target, Build your Project, and finally Flash (UART) your Project

# Programming the Boards
## ESP32-CAM
Either use the special programming board for the ESP32-CAM or follow [this tutorial](https://randomnerdtutorials.com/program-upload-code-esp32-cam/) to use a FTDI programmer.

## Headset Board
Use a FTDI programmer. Make sure to solder a connection for RTS since this pin is usually not easily available. Connect the FTDI pins to the programming pins at the bottom of the board, swapping TX and RX (but not RTS or DTR). ![](https://github.com/H-Bombmxpwr/FPV_Drone/blob/main/Documents/images/board_pins.PNG)
