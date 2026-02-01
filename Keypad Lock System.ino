#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27
Servo lockServo;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";   // Set your password here
String input = "";

void setup() {
  lcd.init();
  lcd.backlight();
  lockServo.attach(10);     // Servo on pin 10
  lockServo.write(0);       // Locked position
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == 'C') {
      input = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Cleared. Try now:");
    } else if (key == 'D') {
      lcd.clear();
      if (input == password) {
        lcd.setCursor(0, 0);
        lcd.print("Access Granted");
        lockServo.write(90); // Unlock
        delay(5000);         // Keep unlocked for 5 sec
        lockServo.write(0);  // Lock again
      } else {
        lcd.setCursor(0, 0);
        lcd.print("Access Denied");
      }
      input = "";
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    } else {
      input += key;
      lcd.setCursor(0, 1);
      lcd.print(input);
    }
  }
}
