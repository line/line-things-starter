#include <LBLE.h>
#include <LBLEPeriphral.h>

#define BUTTON_PIN      (6)

int nButtonChanged = 0;
int bOn = 0;
LBLEUuid serviceUuid("91E4E176-D0B9-464D-9FE4-52EE3E9F1552");
LBLEService userService("91E4E176-D0B9-464D-9FE4-52EE3E9F1552");
LBLECharacteristicInt writeCharacteristic("E9062E71-9E62-4BC6-B0D3-35CDCD9B027B", LBLE_WRITE);
LBLECharacteristicInt notifyCharacteristic("62FBD229-6EDD-4D1A-B554-5C4E1BB29169", LBLE_READ | LBLE_WRITE);

LBLEService psdiService("E625601E-9E55-4597-A598-76018A0D293D");
LBLECharacteristicInt psdiCharacteristic("26E2B12B-85F0-4F3F-9FDD-91D114270E6E", LBLE_READ);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  LBLE.begin();
  while (!LBLE.ready()) {
    delay(100);
  }
  LBLEPeripheral.setName("LINE Things Trial MT7697");
  userService.addAttribute(writeCharacteristic);
  userService.addAttribute(notifyCharacteristic);
  LBLEPeripheral.addService(userService);
  
  psdiService.addAttribute(psdiCharacteristic);
  LBLEPeripheral.addService(psdiService);
  
  LBLEPeripheral.begin();
  LBLEAdvertisementData advertisement;
  advertisement.configAsConnectableDevice("LINE Things Trial MT7697",serviceUuid);
  LBLEPeripheral.advertise(advertisement);
  attachInterrupt(BUTTON_PIN, button_press, CHANGE);
  Serial.println("Ready to Connect");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(20);
  if (writeCharacteristic.isWritten()) {
    bOn=writeCharacteristic.getValue();
    if(bOn>0){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED ON");
    }else{      
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED OFF");
    }
  }
  if(nButtonChanged==1){
    nButtonChanged=0;
    int btnValue = digitalRead(BUTTON_PIN);
    notifyCharacteristic.setValue(btnValue);
    LBLEPeripheral.notifyAll(notifyCharacteristic);
    delay(50);
  }
}
void button_press(void){
  Serial.println("====Button Changed");
  nButtonChanged=1;
}
