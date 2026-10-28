# LINE Things Starter - LIFF App

> [!WARNING]
> LINE Things Developer Trial was discontinued on March 31, 2024.
> See the [official announcement](https://developers.line.biz/en/news/2024/05/13/line-things-docs-discontinued/) and [project status](../README.md).
> This sample and the instructions below are retained for historical reference only.
> GitHub Pages hosting for this sample has been discontinued.

This is the sample code of the LIFF App for LINE Things Starter.
The code contains a LIFF application that will work with the Starter firmwares.

## Setup

Ensure you have already created a Developer Trial account and generated a service UUID.
To configure the app, change the `USER_SERVICE_UUID` in `liff.js` to your generated service UUID.

## Publish LIFF App using GitHub Pages

The LIFF application included in this repository can also be hosted by using GitHub Pages. To host your LIFF app, perform the following:

1. Fork this repository on GitHub
2. From GitHub Pages settings, select the "master branch" as the "Source"
3. Set the URL of the published GitHub Pages page following with `liff-app/` as the LIFF endpoint URL.

## Reference

For details on Bluetooth LE plugin API for LINE Things on LIFF, please refer to the following document (English to follow shortly):

https://developers.line.biz/ja/reference/line-things/
