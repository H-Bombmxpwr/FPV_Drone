Followed https://randomnerdtutorials.com/esp32-cam-access-point-ap-web-server/ as a basic program to test WiFi capabilities of the ESP32-CAM board.
Was successful.

Followed https://randomnerdtutorials.com/esp32-cam-video-streaming-face-recognition-arduino-ide/ to test the camera on the ESP32-CAM board.
Was successful, however this webserver code included many peripheries that are not needed. Will try to simply code to determine how to apply this program to sending the video to another ESP32 instead of just a webserver. 

Found https://github.com/geeksville/Micro-RTSP. The example program ESP32-devcam.ino proved to be useful in determining which functions in the extensive library were useful. Ended up only using OV2640.h.

Found https://github.com/aquaticus/esp32_composite_video_lib for CSV conversion. Tried to install the ESP IDF environment directly but was unsuccessful.

Hunter found https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md. This was a much easier environment for working with the ESP IDF. Was able to load the program successfully, but found that the ESP32S3 Dev board did not have DACs (https://esp32.com/viewtopic.php?t=22740).
