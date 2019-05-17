# LINE Things Starter for nRF52

## Requirements
* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* Adafruit Feather nRF52 board
  * [Adafruit Feather nRF52 Bluefruit LE - nRF52832](https://www.adafruit.com/product/3406)
  * [Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062)
* Momentary Push Button (Only for nRF52832 board)
* Micro-USB to USB Cable

## Installation
Please ensure you have Arduino IDE installed and the board **disconnected**.

1. Open Arduino IDE
2. Go into **Preferences**
3. Add `https://www.adafruit.com/package_adafruit_index.json` as an 'Additional Board Manager URL'
4. Go to **Boards Manager** from the Tools -> Board menu
5. Search for nRF52 and install **Adafruit nRF52 by Adafruit**.
*Note: Linux users may need to install additional software, please see [here](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/arduino-bsp-setup)*
6. Download and install the [CP2104 driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) (Only for nRF52832 board)

## Setup
1. Connect the **Adafruit Feather nRF52** board via Micro-USB cable to your computer
2. Go into Tools -> Board and select **Adafruit Bluefruit nRF52xxx (840 or 832) Feather** from the list
3. Under Tools -> Port select the appropriate device *ie. COM1, /dev/cu.SLAB_USBtoUART*
4. Test uploading to the board by uploading an empty sketch to make sure there are no issues.

### Adafruit Feather nRF52 Bluefruit LE - nRF52832
The sample project requires a momentary push button to be connected to the development board.
Attach one side to **PIN 7** and the other to **Ground**.

![Refer to the picture](./Button_Connection.png)

### Adafruit Feather nRF52840 Express
Feather nRF52840 board have on-board push button.
Just use `UserSw` button on right side of the board.

## Upload
1. From this repository, open **arduino/starter-nrf52/starter-nrf52.ino**
2. Change the `USER_SERVICE_UUID` to your generated UUID
3. Upload and Enjoy!
