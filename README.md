# LINE Things Starter

These are the sample codes for LINE Things Developer Trial.

LINE Things compatible device example firmware and LIFF application code are included.

## Getting Started

[LINE Things](https://developers.line.biz/ja/docs/line-things/) is a platform that connects Bots and Web services together with IoT devices that are Bluetooth LE enabled. 

To start developing for LINE Things using the example code and the sample firmware, the following steps are necessary.

### Installing the Firmware

To start development using the example firmwares, you will need a compatible Bluetooth LE enabled development board.
Currently LINE Things Starter firmwares supports the following 3 development boards

- [Espressif ESP32-DevKitC](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview)
- [M5Stack （ESP32)](http://m5stack.com/)
- [Adafruit Feather nRF52 Bluefruit LE](https://www.adafruit.com/product/3406)
- [BBC micro:bit](https://microbit.org/)

Each firmware is located under、`esp32`, `m5stack`, `nrf52`, `microbit`  respectively.
For further details, please refer to the `README` file in each directory.

### Enable LINE Things

Please scan the following QR code with LINE to activate LINE Things.

![](https://developers.line.biz/media/line-things/qr_code-311f3503.png)

Upon turning the device on, a device with the name `LINE Things Starter (Default Firmware)`  will be detected.
Once the device is connected, the LIFF app can then be launched by selecting the device.
Here you can test all the LIFF BLE functionalities of LINE Things.

## Developer Trial

Documentation regarding the original firmware and LIFF functions for LINE Things are published at [LINE Things Developer Trial](https://developers.line.biz/ja/docs/line-things/about-line-things-trial/).

In order to develop for LINE Things using Developer Trial, you will need to create a LIFF application, register a trial product, and issue a GATT Service UUID.
For additional details, please visit the [LINE Developers](https://developers.line.biz/) site.

Please refer to the following article from LINE Engineering Blog.

- [LINE の IoT プラットフォーム LINE Things の Developer Trial を試してみる](https://engineering.linecorp.com/ja/blog/line-things-developer-trial/)

## License

LINE Things Starter code is licensed under Creative Commons License [CC0](http://creativecommons.org/publicdomain/zero/1.0/).
