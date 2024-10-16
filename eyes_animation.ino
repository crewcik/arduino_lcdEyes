#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte eyeOpen[8] = {
  B00100,
  B01010,
  B10101,
  B10101,
  B01010,
  B00100,
  B00000,
  B00000
};

byte eyeBlink[8] = {
  B00000,
  B00000,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

byte eyeHalfOpen[8] = {
  B00000,
  B00000,
  B01010,
  B10101,
  B10101,
  B01110,
  B00000,
  B00000
};

byte eyeClosed[8] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000
};

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, eyeOpen);
  lcd.createChar(1, eyeBlink);
  lcd.createChar(2, eyeHalfOpen);
  lcd.createChar(3, eyeClosed);

  lcd.setCursor(4, 1); 
  lcd.print("Merhaba!");

  delay(2000); 
  
  lcd.clear();

  lcd.setCursor(5, 0);
  lcd.write(byte(0)); 
  lcd.setCursor(10, 0);
  lcd.write(byte(0)); 
}

void loop() {
  blinkEyes();
  moveEyesLeft();
  moveEyesRight();
}

void blinkEyes() {
  lcd.setCursor(5, 0);
  lcd.write(byte(2)); 
  lcd.setCursor(10, 0);
  lcd.write(byte(2));
  delay(300);

  lcd.setCursor(5, 0);
  lcd.write(byte(3)); 
  lcd.setCursor(10, 0);
  lcd.write(byte(3)); 
  delay(300);

  lcd.setCursor(5, 0);
  lcd.write(byte(1)); 
  lcd.setCursor(10, 0);
  lcd.write(byte(1)); 
  delay(200);

  lcd.setCursor(5, 0);
  lcd.write(byte(3)); 
  lcd.setCursor(10, 0);
  lcd.write(byte(3)); 
  delay(300);

  lcd.setCursor(5, 0);
  lcd.write(byte(2)); 
  lcd.setCursor(10, 0);
  lcd.write(byte(2));
  delay(300);

  lcd.setCursor(5, 0);
  lcd.write(byte(0)); 
  lcd.setCursor(10, 0);
  lcd.write(byte(0)); 
  delay(2000);
}

void moveEyesLeft() {
  for (int i = 5; i > 2; i--) {
    lcd.setCursor(i, 0);
    lcd.write(byte(0)); 
    lcd.setCursor(i + 5, 0);
    lcd.write(byte(0)); 
    delay(300);

    lcd.setCursor(i + 1, 0);
    lcd.print(" ");
    lcd.setCursor(i + 6, 0);
    lcd.print(" ");
  }
}

void moveEyesRight() {
  for (int i = 2; i < 5; i++) {
    lcd.setCursor(i, 0);
    lcd.write(byte(0));
    lcd.setCursor(i + 5, 0);
    lcd.write(byte(0)); 
    delay(300);

    lcd.setCursor(i - 1, 0);
    lcd.print(" ");
    lcd.setCursor(i + 4, 0);
    lcd.print(" ");
  }
}
