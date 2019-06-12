// Change this to your generated service UUID
var userServiceUUID = "91E4E176-D0B9-464D-9FE4-52EE3E9F1552";
var writeCharacteristicUUID = "E9062E71-9E62-4BC6-B0D3-35CDCD9B027B";
var notifyCharacteristicUUID = "62FBD229-6EDD-4D1A-B554-5C4E1BB29169";

var psdiServiceUUID = "E625601E-9E55-4597-A598-76018A0D293D";
var psdiCharacteristicUUID = "26E2B12B-85F0-4F3F-9FDD-91D114270E6E";

var userCharacteristics = {};
userCharacteristics[notifyCharacteristicUUID] = {
  value: 0,
  notify: true
};
userCharacteristics[writeCharacteristicUUID] = {
  value: 30,
  writable: true,
  onWrite: function (evt) {
    if (parseInt(evt.data) == 1) {
      LED1.set();
    }
    else if (parseInt(evt.data) === 0) {
      LED1.reset();
    }
  }
};

var psdiCharacteristics = {};
psdiCharacteristics[psdiCharacteristicUUID] = {
  value: NRF.getAddress(),
  readable: true
};

var deviceServices = {};
deviceServices[userServiceUUID] = userCharacteristics;
deviceServices[psdiServiceUUID] = psdiCharacteristics;

// Setup GATT services
NRF.setServices(deviceServices, { uart: false, advertise: [userServiceUUID] });

// Update button state on pressed
setWatch(function () {
  var buttonOnCharacteristic = {};
  buttonOnCharacteristic[notifyCharacteristicUUID] = {
    value: 1,
    notify: true
  };
  var updateButtonON = {};
  updateButtonON[userServiceUUID] = buttonOnCharacteristic;

  // console.log("Button Pressed");
  NRF.updateServices(updateButtonON);
}, BTN, { edge: "rising", debounce: 50, repeat: true });

// Update button state on released
setWatch(function () {
  var buttonOffCharacteristic = {};
  buttonOffCharacteristic[notifyCharacteristicUUID] = {
    value: 0,
    notify: true
  };
  var updateButtonOFF = {};
  updateButtonOFF[userServiceUUID] = buttonOffCharacteristic;

  // console.log("Button Released");
  NRF.updateServices(updateButtonOFF);
}, BTN, { edge: "falling", debounce: 50, repeat: true });
