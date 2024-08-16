#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(7,6,9,10,11,12); // Set the LCD address and dimensions
SoftwareSerial bluetooth(2, 3); // RX, TX pins for HC-05

char incomingByte;

void setup() {
  pinMode(2, INPUT_PULLUP);
  lcd.begin(16,2);
 // lcd.setContrast(50);
 // lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    incomingByte = bluetooth.read();
    if (incomingByte == 'A') { // Button pressed on the app
      lcd.clear();
      lcd.print("Come In");
    } else if (incomingByte == 'B') { // Please wait pressed on the app
      lcd.clear();
      lcd.print("Please Wait");
    }
  }
  
  if (digitalRead(2) == LOW) {
    bluetooth.write('P'); // Button press detected, send a message to the app
    delay(1000); // Debounce
  }
}
