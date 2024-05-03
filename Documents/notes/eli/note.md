When looking at the buck converter on Jason's example board, saw that the input voltage range did not include 3.7V. Instead of trying to find a buck converter with a low dropout, followed https://www.reddit.com/r/AskElectronics/comments/6d5bcy/33v_regulation_from_a_37v_liion_battery/ to determine that we should move forawrd with a AP2112 LDO.

Redesigned the power circuits on the headset board. LDO was simpler than the buck converter. Also determined that the reverse power protection circuit and the fuse are unnecessary since the ESP32 will not draw more than 600mA of current and the Crazyflie battery connector that I will be using for the connector instead of the skrew connector is not reversible.

Followed https://randomnerdtutorials.com/esp32-cam-access-point-ap-web-server/ as a basic program to test WiFi capabilities of the ESP32-CAM board.
Was successful.

Followed https://randomnerdtutorials.com/esp32-cam-video-streaming-face-recognition-arduino-ide/ to test the camera on the ESP32-CAM board.
Was successful, however this webserver code included many peripheries that are not needed. Will try to simply code to determine how to apply this program to sending the video to another ESP32 instead of just a webserver. 

Found https://github.com/geeksville/Micro-RTSP. The example program ESP32-devcam.ino proved to be useful in determining which functions in the extensive library were useful. Ended up only using OV2640.h.

Found https://github.com/aquaticus/esp32_composite_video_lib for CSV conversion. Tried to install the ESP IDF environment directly but was unsuccessful.

Hunter found https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md. This was a much easier environment for working with the ESP IDF. Was able to load the program successfully, but found that the ESP32S3 Dev board did not have DACs (https://esp32.com/viewtopic.php?t=22740).

Determined that the best chip to go forward with is the ESP32 Wrover. Looking at the datasheet (https://www.espressif.com/sites/default/files/documentation/esp32-wrover-e_esp32-wrover-ie_datasheet_en.pdf), the GPIO_STRAPPING pins are a bit different, but the general peripheries are the same.

After the new dev kit was ordered with the correct chip (and thus a DAC), got the demo library running. Used the HDMI converter to view the output on a monitor in 2070.
