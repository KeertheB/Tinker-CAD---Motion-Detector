#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
Servo servoX, servoY;

const int ldrTL = A0, ldrTR = A1, ldrBL = A2, ldrBR = A3;//T=top,B=bottom,L=left,R=right
int posX = 90, posY = 90;//X=horizontal,Y=vertical
const int threshold = 50;//diff in values(max req. for shift in pos.)

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  servoX.attach(9);
  servoY.attach(10);
  servoX.write(posX);
  servoY.write(posY);
  delay(1000);
}

void loop() {
  int tl = analogRead(ldrTL);
  int tr = analogRead(ldrTR);
  int bl = analogRead(ldrBL);
  int br = analogRead(ldrBR);

  int topAvg = (tl + tr) / 2;
  int bottomAvg = (bl + br) / 2;
  int leftAvg = (tl + bl) / 2;
  int rightAvg = (tr + br) / 2;

  int verticalDiff = topAvg - bottomAvg;
  int horizontalDiff = leftAvg - rightAvg;

  String direction = getBrightestDirection(tl, tr, bl, br);

  if (abs(verticalDiff) > threshold) {
    posY += (verticalDiff > 0) ? -1 : 1;
    posY = constrain(posY, 0, 180);
    servoY.write(posY);
  }

  if (abs(horizontalDiff) > threshold) {
    posX += (horizontalDiff > 0) ? -1 : 1;
    posX = constrain(posX, 0, 180);
    servoX.write(posX);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bright: " + direction); 
  lcd.setCursor(0, 1);
  lcd.print("X:" + String(posX) + " Y:" + String(posY)); 

  delay(1000);
}

String getBrightestDirection(int tl, int tr, int bl, int br) {
  int maxVal = max(max(tl, tr), max(bl, br));
  if (tl == maxVal) return "TL";
  if (tr == maxVal) return "TR";
  if (bl == maxVal) return "BL";
  return "BR";
}
