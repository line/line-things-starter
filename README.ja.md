# LINE Things Starter

LINE Things Developer Trial 向けのサンプルコードです。

LINE Things 対応デバイスを作成するためのファームウェアと、LIFF アプリのコード、サンプル LINE Bot が含まれています。

[English](README.md) | 日本語

## Getting Started

[LINE Things](https://developers.line.biz/ja/docs/line-things/) は、Bluetooth LE に対応した IoT デバイスを LINE のアプリ上で接続し Bot や Web サービスと連携することができるプラットフォームです。

LINE Things を LINE Things Starter のサンプルファームウェアを利用して試すには、以下の準備が必要です。

### Install Firmware

LINE Things Starter を試すには、Bluetooth LE 対応の開発ボードへファームウェアを書き込む必要があります。
LINE Things Starter のファームウェアは、現在以下の6つの開発ボードに対応しています。

- [LINE Things dev board](https://github.com/line/line-things-dev-board)
- [Espressif ESP32-DevKitC](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview)
- [M5Stack （ESP32)](http://m5stack.com/)
- [M5StickC](https://m5stack.com/products/stick-c)
- [Adafruit Feather nRF52 Bluefruit LE - nRF52832](https://www.adafruit.com/product/3406)
- [Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062)
- [BBC micro:bit](https://microbit.org/)
- [Obniz](https://obniz.io/)
- [Puck.js](https://www.puck-js.com/)

それそれ、`line-things-dev-board`, `esp32`, `m5stack`, `m5stick-c`, `nrf52`, `microbit`, `obniz`, `puckjs` のディレクトリの下にファームウェアが格納されています。
詳しくは、それぞれのディレクトリの `README.ja.md` を参照してください。

### Enable LINE Things

以下の QR コードを LINE アプリ上で Scan して LINE Things を有効化してください。

![](https://developers.line.biz/media/line-things/qr_code-311f3503.png)

デバイスの電源を投入すると、`LINE Things Starter (Default Firmware)` というデバイスが検出されます。
デバイスをリンクして、LIFF アプリを開くと LINE Things の LIFF BLE 機能を試すことが出来ます。

## Developer Trial

LINE Things の機能を多くの開発者の方にご利用いただくために、[LINE Things Developer Trial](https://developers.line.biz/ja/docs/line-things/about-line-things-trial/) を無料で公開しています。

LINE Things のために必要なファームウェア開発や LIFF の機能に関するドキュメントは [LINE Developers - LINE Things](https://developers.line.biz/ja/docs/line-things/) で公開されています。

### プロダクト登録と LIFF アプリの作成

Developer Trial を利用して開発を行うには、LIFF アプリの作成と、トライアルプロダクトの登録および GATT Service UUID の発行が必要です。
詳しくは、[LINE Developers](https://developers.line.biz/ja/docs/line-things/) サイトをご覧ください。 

### 自動通信機能

自動通信機能のための LINE bot のサンプルコードも `bot/app.py` に格納されています。
以下のボタンから、Heroku へデプロイすることができます。

[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy)

自動通信の開発には、LINE Messaging API の Webhook の設定と、LINE Things REST API を利用したシナリオセットの登録が必要です。
詳しくは、[bot/README.ja.md](bot/README.ja.md) を参照してください。

### 参考文献

LINE Engineering Blog の以下の記事には、登録手順の解説もあるので参考にしてください。

- [LINE の IoT プラットフォーム LINE Things の Developer Trial を試してみる](https://engineering.linecorp.com/ja/blog/line-things-developer-trial/)
- [LINE Things 自動通信機能がリリースされました & 使い方紹介](https://engineering.linecorp.com/ja/blog/line-things-automatic-communication/)

## License

LINE Things Starter に含まれるコードは、クリエイティブ・コモンズ [CC0](http://creativecommons.org/publicdomain/zero/1.0/) の下で利用可能です。
