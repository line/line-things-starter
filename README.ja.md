# LINE Things Starter

LINE Things Developer Trial 向けのサンプルコードです。

LINE Things 対応デバイスのファームウェアと、LIFF アプリのコードが含まれています。

## Getting Started

[LINE Things](https://developers.line.biz/ja/docs/line-things/) は、Bluetooth LE に対応した IoT デバイスを LINE のアプリ上で接続し Bot や Web サービスと連携することができるプラットフォームです。

LINE Things を LINE Things Starter の初期ファームウェアを利用して試すには、以下の準備が必要です。

### Install Firmware

LINE Things Starter を試すには、Bluetooth LE 対応の開発ボードへファームウェアを書き込む必要があります。
LINE Things Starter のファームウェアは、現在以下の3つの開発ボードに対応しています。

- [Espressif ESP32-DevKitC](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview)
- [M5Stack （ESP32)](http://m5stack.com/)
- [Adafruit Feather nRF52 Bluefruit LE](https://www.adafruit.com/product/3406)
- [BBC micro:bit](https://microbit.org/)

それそれ、`esp32`, `m5stack`, `nrf52`, `microbit` のディレクトリの下にファームウェアが格納されています。
詳しくは、それぞれのディレクトリの `README` を参照してください。

### Enable LINE Things

以下の QR コードを LINE アプリ上で Scan して LINE Things を有効化してください。

![](https://developers.line.biz/media/line-things/qr_code-311f3503.png)

デバイスの電源を投入すると、`LINE Things Starter (Default Firmware)` というデバイスが検出されます。
デバイスをリンクして、LIFF アプリを開くと LINE Things の LIFF BLE 機能を試すことが出来ます。

## Developer Trial

LINE Things では、オリジナルファームウェアと LIFF アプリの開発ができる機能を [LINE Things Developer Trial](https://developers.line.biz/ja/docs/line-things/about-line-things-trial/)
 として公開しています。

Developer Trial を利用して開発を行うには、LIFF アプリの作成と、トライアルプロダクトの登録および GATT Service UUID の発行が必要です。
詳しくは、LINE Developers サイトをご覧ください。

LINE Engineering Blog の以下の記事も参考にしてください。

- [LINE の IoT プラットフォーム LINE Things の Developer Trial を試してみる](https://engineering.linecorp.com/ja/blog/line-things-developer-trial/)

## License

LINE Things Starter に含まれるコードは、[CC0](http://creativecommons.org/publicdomain/zero/1.0/) の下で利用可能です。
