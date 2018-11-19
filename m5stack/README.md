# LINE Things Starter for M5Stack

## Requirements
* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* [M5Stack](http://m5stack.com/)
* USB Type-C to USB Cable

## Installation
Please ensure you have Arduino IDE installed and the board **disconnected**.

1. Open Arduino IDE
2. Go into **Preferences**
3. Add `https://dl.espressif.com/dl/package_esp32_index.json` as an 'Additional Board Manager URL'
4. Go to **Boards Manager** from the Tools -> Board menu
5. Search for esp32 and install **esp32**.
6. Download and install the [CP2104 driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

## Setup
1. Connect the **M5Stack** board via USB Type-C cable to your computer
2. Go into Tools -> Board and select **M5Stack-Core-ESP32** from the list
3. Under Tools -> Port select the appropriate device *ie. COM1, /dev/cu.SLAB_USBtoUART*
4. Test uploading to the board by uploading an empty sketch to make sure there are no issues.

## Upload
1. From this repository, open **arduino/sample/sample.ino**
2. Change the `USER_SERVICE_UUID` to your generated UUID
3. Upload and Enjoy!
