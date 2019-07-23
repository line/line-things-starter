# LINE Things Starter

This repository contains sample codes for LINE Things Developer Trial.

LINE Things compatible device example firmware, LIFF app code and LINE bot code are included.

English | [日本語](README.ja.md)

## Getting Started

[LINE Things](https://developers.line.biz/en/docs/line-things/) is a platform that connects Bots and Web services together with IoT devices that are Bluetooth LE enabled.

To start developing for LINE Things using the example code and the sample firmware, the following steps are necessary.

### Installing the Firmware

To start development using the example firmwares, you will need a compatible Bluetooth LE enabled development board.
Currently LINE Things Starter firmwares supports the following 6 development boards

- [LINE Things dev board](https://github.com/line/line-things-dev-board)
- [Espressif ESP32-DevKitC](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview)
- [M5Stack （ESP32)](http://m5stack.com/)
- [M5StickC](https://m5stack.com/products/stick-c)
- [Adafruit Feather nRF52 Bluefruit LE - nRF52832](https://www.adafruit.com/product/3406)
- [Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062)
- [BBC micro:bit](https://microbit.org/)
- [Obniz](https://obniz.io/)
- [Puck.js](https://www.puck-js.com/)

Each firmware is located under `line-things-dev-board`, `esp32`, `m5stack`, `m5stick-c`,`nrf52`, `microbit`, `obniz` and `puckjs` respectively.
For further details, please refer to the `README` file in each directory.

### Enable LINE Things

Please scan the following QR code with LINE to activate LINE Things.

![](https://developers.line.biz/media/line-things/qr_code-311f3503.png)

Upon turning the device on, a device with the name `LINE Things Starter (Default Firmware)` will be detected.
Once the device is connected, the LIFF app can then be launched by selecting the device.
Here you can test all the LIFF BLE functionalities of LINE Things.

## Developer Trial

Developers can try the functions of LINE Things for free with the [LINE Things Developer Trial](https://developers.line.biz/en/docs/line-things/about-line-things-trial/).

Documentation regarding firmware development and LIFF functions for LINE Things are published at [LINE Developers - LINE Things](https://developers.line.biz/en/docs/line-things/).

### Product registration and creating LIFF app

In order to develop for LINE Things using Developer Trial, you will need to create a LIFF app, register a trial product, and issue a GATT Service UUID.
For additional details, please visit the [LINE Developers](https://developers.line.biz/en/docs/line-things/) site.

### Automatic communication

LINE bot sample code for the automatic communication feature is also included in `bot/app.py`.
You can deploy it to Heroku from following button.

[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy)

In order to develop automatic communication, you have to setup webhook for LINE Messaging API and register "Scenario set" by LINE Things REST API.
Please see [bot/README.md](bot/README.md) for details.

### References

Please refer to the following step by step article from LINE Engineering Blog.

- [Trying out LINE’s IoT Platform through LINE Things Developer Trial](https://engineering.linecorp.com/en/blog/line-things-developer-trial/)
- [LINE Things automatic communication](https://engineering.linecorp.com/en/blog/line-things-automatic-communication/)

## License

LINE Things Starter code is licensed under Creative Commons License [CC0](http://creativecommons.org/publicdomain/zero/1.0/).
