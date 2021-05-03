/*
 * Quick and dirty adaption for the M5Stack Atom QR/Barcode scanner 
 * to act as a virtual keyboard
 * Based on the standard Atom QR Example (not many changes
 * 
 * Once a code is scanned the BlueTooth keyboard is typing what ever is scanned
 * and hits the return key afterwards
 * 
 */

/*Press button to scan, serial monitor will print information*/
#include <M5Atom.h>
// including BlueTooth Keyboard library https://github.com/T-vK/ESP32-BLE-Keyboard
#include <BleKeyboard.h>

#define TRIG 23
#define DLED 33

// setting a boolean thats later used for checking if the RETURN_KEY should be pressed or not
bool newCode = false;
// bleKeyboard("Name of Device", "company", Battery%[I just use 100%])
BleKeyboard bleKeyboard("BlueTooth QR Scanner","MasterTuX",100);

void setup() {
  M5.begin(false, false, true);
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 22, 19);
  M5.dis.drawpix(0, 0x00f000);
  pinMode(TRIG, OUTPUT);
  pinMode(DLED, INPUT);
  digitalWrite(TRIG, HIGH);
  bleKeyboard.begin();
  while (!bleKeyboard.isConnected());
}

void loop() {
  M5.update();
  if (digitalRead(39) == LOW) {
    digitalWrite(TRIG, LOW);
  } else {
    digitalWrite(TRIG, HIGH);
  }
  if (digitalRead(DLED) == HIGH) {
    while (Serial2.available() > 0) {
      char ch = Serial2.read();
      // writing char via keyboard
      bleKeyboard.print(ch);
      // define that a new code was scanned 
      newCode = true;
      delay(10);
    }
  }
  if (newCode) {
    // "pressing return"
    bleKeyboard.write(KEY_RETURN);
    // resetting to default
    newCode = false;
  }
}
