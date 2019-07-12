# A sample bot for LINE Things Starter with automatic communication

Please make sure to confirm that the LINE Things Starter device with your own LINE Things product Service UUID is working fine before doing this.

## Register "Scenario set"

In order for you to have an automatic communication action perform, you first need to register and set a scenario to the LINE Things server prior to usage.

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

For more information, see the LINE Things document, [Prepare to use automatic communication](https://developers.line.biz/en/docs/line-things/prepare-auto-communication/).

## Deploy a sample bot to Heroku

Make sure to enter "LINE_CHANNEL_ACCESS_TOKEN" and "LINE_CHANNEL_SECRET" of the channel of your own LINE Things product on deployment form.
You can get it from [LINE Developers](https://developers.line.biz/en/) site.

[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy?template=https://github.com/line/line-things-starter)

## Setup Webhook URL

Copy your Heroku app URL and set it as the Webhook URL of your channel on the [LINE Developers](https://developers.line.biz/en/) site.
Don’t forget to add the `/callback` path at the end and enable Webhook events.

![](https://engineering-org.line-apps.com/wp-content/uploads/2019/06/LINE_Things_autoconnect_webhook-1024x331.png)

## Press button!

Press a button of your device, then you will get message from LINE bot.

If you can't get a message, you should open [Device Link Screen](https://line.me/R/nv/things/deviceLink) again to refresh scenario set.

## Reference

* [LINE Things automatic communication - LINE ENGINEERING](https://engineering.linecorp.com/en/blog/line-things-automatic-communication/)
