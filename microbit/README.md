# LINE Things Starter for BBC micro:bit

## Requirements
* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* [BBC micro:bit](https://microbit.org/)
* Micro-USB to USB Cable

## Installation
Please ensure you have Arduino IDE installed and the board **disconnected**.

1. Open Arduino IDE
2. Install **[arduino-nRF5](https://github.com/sandeepmistry/arduino-nRF5)** board library on your Arduino IDE
3. Install **[BLEPeripheral](https://github.com/sandeepmistry/arduino-BLEPeripheral)** library on your Arduino IDE
4. Install **[Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)** library on your Arduino IDE
5. Install **[Adafruit_Microbit](https://github.com/adafruit/Adafruit_Microbit)** library on your Arduino IDE

## Setup
1. Connect the **BBC micro:bit** board via Micro-USB cable to your computer
2. Go into Tools -> Board and select **BBC micro:bit** from the list
3. Go into Tools -> SoftDevice and select **S130** from the list
4. Go into Tools -> Programmer and select **CMSIS-DAP** from the list
5. Flash **SoftDevice S130** to your micro:bit according to [arduino-nRF5 README](https://github.com/sandeepmistry/arduino-nRF5#selecting-a-softdevice) procedure
    - If you failed to download SoftDevice .hex, you can download hex manually from [Nordic Website](https://www.nordicsemi.com/Software-and-Tools/Software/S130/Download) and place `s130_nrf51_2.0.1_softdevice.hex` into `~/Library/Arduino15/packages/sandeepmistry/hardware/nRF5/0.6.0/cores/nRF5/SDK/components/softdevice/s130/hex`
6. Under Tools -> Port select the appropriate (BBC micro:bit) device
7. Test uploading to the board by uploading an empty sketch to make sure there are no issues

## Upload
1. From this repository, open **arduino/sample/sample.ino**
2. Change the `USER_SERVICE_UUID` to your generated UUID
3. Upload and Enjoy!
