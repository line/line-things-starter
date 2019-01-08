# LINE Things Starter for BBC micro:bit

## 必要なもの・開発環境
* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* [BBC micro:bit](https://microbit.org/ja/)
* Micro USB ケーブル

## インストール方法
Arduino IDE をインストールした後、必ずボードを **接続しないで** 以下の手順を進めてください。

1. Arduino IDE を開きます
2. **[arduino-nRF5](https://github.com/sandeepmistry/arduino-nRF5)** を README の手順に従ってインストールします
3. **[BLEPeripheral](https://github.com/sandeepmistry/arduino-BLEPeripheral)** ライブラリをインストールします
4. **[Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)** ライブラリをインストールします
5. **[Adafruit_Microbit](https://github.com/adafruit/Adafruit_Microbit)** ライブラリをインストールします

## セットアップ
1. **BBC micro:bit** を Micro USB ケーブルを使って PC へ接続してください
2. ツール -> ボード のリストから **BBC micro:bit** を選択してください
3. ツール -> SoftDevice のリストから **S130** を選択してください
4. ツール -> 書込装置 のリストから **CMSIS-DAP** を選択してください
5. [arduino-nRF5 README](https://github.com/sandeepmistry/arduino-nRF5#selecting-a-softdevice) の手順に従って、**SoftDevice S130** をデバイスへ書き込みます
    - SoftDevice の HEX ダウンロードに失敗する場合は、[Nordic のサイト](https://www.nordicsemi.com/Software-and-Tools/Software/S130/Download) から手動でダウンロードして `~/Library/Arduino15/packages/sandeepmistry/hardware/nRF5/0.6.0/cores/nRF5/SDK/components/softdevice/s130/hex` へ `s130_nrf51_2.0.1_softdevice.hex` を配置してください
6. ツール -> シリアルポート で (BBC micro:bit) と表示されたシリアルポートを選択してください
7. テストとして、一度空のスケッチをアップロードしてみましょう。エラーが出ず、問題がなければ次に進んでください

## アップロード
1. このリポジトリの中から **arduino/sample/sample.ino** を開いてください
2. 必要に応じて、`USER_SERVICE_UUID` を生成された Service UUID に変更してください
3. あとは、アップロードして LINE Things Starter をお楽しみください
