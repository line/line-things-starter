# 自動通信サンプルボット for LINE Things Starter

LINE Things Starter デバイスが、自身で登録した LINE Things プロダクトの Service UUID できちんと動作することを確認してから先へ進んでください。

## シナリオセットを登録

自動通信を行うためには、まず LINE Things のサーバーにシナリオセットを登録する必要があります。

```sh
$ curl -v -X PUT https://api.line.me/things/v1/products/<YOUR PRODUCT ID>/scenario-set \
-H "Authorization: Bearer <CHANNEL ACCESS TOKEN>" \
-H 'Content-Type:application/json' \
-d '
{
  "autoClose": false,
  "suppressionInterval": 0,
  "scenarios": [{
    "trigger": {	
      "type": "BLE_NOTIFICATION",
      "serviceUuid": "<YOUR SERVICE UUID>",
      "characteristicUuid": "62FBD229-6EDD-4D1A-B554-5C4E1BB29169"
    },
    "actions": []
  }]
}'
```

詳しくは、LINE Things ドキュメントの [自動通信の準備をする](https://developers.line.biz/ja/docs/line-things/prepare-auto-communication/) を参照してください。

## サンプルボットを Heroku へデプロイ

LINE Things プロダクトを登録したチャネルの "LINE_CHANNEL_ACCESS_TOKEN" と "LINE_CHANNEL_SECRET" をデプロイ画面で入力するのを忘れないでください。
[LINE Developers](https://developers.line.biz/) サイトから取得できます。

[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy?template=https://github.com/line/line-things-starter)

## Webhook URL を設定

Heroku のアプリ URL をあなたのチャネルの Webhook URL に設定します。
[LINE Developers](https://developers.line.biz/) から設定します。
URL の末尾に `/callback` を追加し、Webhook を利用するに設定する事を忘れないでください。

![](https://engineering-org.line-apps.com/wp-content/uploads/2019/06/LINE_Things_autoconnect_webhook-1024x331.png)

## Press button!

デバイスのボタンを押してみましょう、メッセージが LINE bot から届くはずです。

メッセージが届かない場合には、シナリオセットを更新するために [デバイス連携画面](https://line.me/R/nv/things/deviceLink) を一度開いてみてください。

## Reference

* [LINE Things 自動通信機能がリリースされました & 使い方紹介 - LINE ENGINEERING](https://engineering.linecorp.com/ja/blog/line-things-automatic-communication/)
