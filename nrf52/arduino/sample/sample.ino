#include <bluefruit.h>

// Device Name: Maximum 30 bytes
#define DEVICE_NAME "LINE Things Trial nRF52"

// User service UUID: Change this to your generated service UUID
#define USER_SERVICE_UUID "91E4E176-D0B9-464D-9FE4-52EE3E9F1552"
// User service characteristics
#define WRITE_CHARACTERISTIC_UUID "E9062E71-9E62-4BC6-B0D3-35CDCD9B027B"
#define NOTIFY_CHARACTERISTIC_UUID "62FBD229-6EDD-4D1A-B554-5C4E1BB29169"

// PSDI Service UUID: Fixed value for Developer Trial
#define PSDI_SERVICE_UUID "E625601E-9E55-4597-A598-76018A0D293D"
#define PSDI_CHARACTERISTIC_UUID "26E2B12B-85F0-4F3F-9FDD-91D114270E6E"

#define BUTTON 11
#define LED1 17

uint8_t userServiceUUID[16];
uint8_t psdiServiceUUID[16];
uint8_t psdiCharacteristicUUID[16];
uint8_t writeCharacteristicUUID[16];
uint8_t notifyCharacteristicUUID[16];

BLEService userService;
BLEService psdiService;
BLECharacteristic psdiCharacteristic;
BLECharacteristic notifyCharacteristic;
BLECharacteristic writeCharacteristic;

volatile int btnAction = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(BUTTON, buttonAction, CHANGE);

  Bluefruit.begin();
  Bluefruit.setName(DEVICE_NAME);

  setupServices();
  startAdvertising();
}

void loop() {
  uint8_t btnRead;

  while (btnAction > 0) {
    btnRead = !digitalRead(BUTTON);
    btnAction = 0;
    notifyCharacteristic.notify(&btnRead, sizeof(btnRead));
    delay(20);
  }
}

void setupServices(void) {
  // Convert String UUID to raw UUID bytes
  strUUID2Bytes(USER_SERVICE_UUID, userServiceUUID);
  strUUID2Bytes(PSDI_SERVICE_UUID, psdiServiceUUID);
  strUUID2Bytes(PSDI_CHARACTERISTIC_UUID, psdiCharacteristicUUID);
  strUUID2Bytes(WRITE_CHARACTERISTIC_UUID, writeCharacteristicUUID);
  strUUID2Bytes(NOTIFY_CHARACTERISTIC_UUID, notifyCharacteristicUUID);

  // Setup User Service
  userService = BLEService(userServiceUUID);
  userService.begin();

  writeCharacteristic = BLECharacteristic(writeCharacteristicUUID);
  writeCharacteristic.setProperties(CHR_PROPS_WRITE_WO_RESP);
  writeCharacteristic.setWriteCallback(write_led_cb);
  writeCharacteristic.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
  writeCharacteristic.setFixedLen(1);
  writeCharacteristic.begin();

  notifyCharacteristic = BLECharacteristic(notifyCharacteristicUUID);
  notifyCharacteristic.setProperties(CHR_PROPS_NOTIFY);
  notifyCharacteristic.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
  notifyCharacteristic.setFixedLen(1);
  notifyCharacteristic.begin();

  // Setup PSDI Service
  psdiService = BLEService(psdiServiceUUID);
  psdiService.begin();

  psdiCharacteristic = BLECharacteristic(psdiCharacteristicUUID);
  psdiCharacteristic.setProperties(CHR_PROPS_READ);
  psdiCharacteristic.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
  psdiCharacteristic.setFixedLen(sizeof(uint32_t) * 2);
  psdiCharacteristic.begin();

  // Set PSDI (Product Specific Device ID) value
  uint32_t deviceAddr[] = { NRF_FICR->DEVICEADDR[0], NRF_FICR->DEVICEADDR[1] };
  psdiCharacteristic.write(deviceAddr, sizeof(deviceAddr));
}

void startAdvertising(void) {
  // Start Advertising
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addService(userService);
  Bluefruit.ScanResponse.addName();
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.start(0);
}

void buttonAction() {
  btnAction++;
}

void write_led_cb(BLECharacteristic& chr, uint8_t* data, uint16_t len, uint16_t offset) {
  int value = *data;
  digitalWrite(LED1, value);
}

// UUID Converter
void strUUID2Bytes(String strUUID, uint8_t binUUID[]) {
  String hexString = String(strUUID);
  hexString.replace("-", "");

  for (int i = 16; i != 0 ; i--) {
    binUUID[i - 1] = hex2c(hexString[(16 - i) * 2], hexString[((16 - i) * 2) + 1]);
  }
}

char hex2c(char c1, char c2) {
  return (nibble2c(c1) << 4) + nibble2c(c2);
}

char nibble2c(char c) {
  if ((c >= '0') && (c <= '9'))
    return c - '0';
  if ((c >= 'A') && (c <= 'F'))
    return c + 10 - 'A';
  if ((c >= 'a') && (c <= 'f'))
    return c + 10 - 'a';
  return 0;
}
