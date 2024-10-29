#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int i = 1;
byte heartChar[8] = {
  0b00011,
  0b00010,
  0b00010,
  0b00010,
  0b11111,
  0b01111,
  0b01001,
  0b01001,
};

byte cactusChar[8] = {
  0b00100,
  0b00101,
  0b00101,
  0b10111,
  0b10100,
  0b11100,
  0b00100,
  0b00100,
};

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT); // merah

  lcd.init();
  lcd.backlight();
  lcd.createChar(0, heartChar);
  lcd.createChar(1, cactusChar);
}

void loop() {
  for (int position = 16; position >= 0; position--) {
    lcd.clear();

    // Display heart at (3, 0)
    if (digitalRead(2) == LOW) {
      lcd.setCursor(3, 0);
      lcd.write((byte)0); // Heart character
    }

    // Display cactus only if button is not pressed
    if (digitalRead(2) == HIGH) {
      lcd.setCursor(3, 1);
      lcd.write((byte)1); // Cactus character
    }

    // Move cactus across the second line
    lcd.setCursor(position, 1);
    if (digitalRead(2) == HIGH) {
      lcd.write((byte)1); // Cactus character
    }

    delay(200);
  }
}
