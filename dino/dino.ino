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
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, heartChar);
  lcd.createChar(1, cactusChar);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int position = 16; position >= 0; position--){

    lcd.clear();
    if (position <= 3)
    {
      i--;
      lcd.setCursor(3,i);
      lcd.write((byte)0);
    }
    else
    {
      i = 1;
      lcd.setCursor(3,1);
      lcd.write((byte)0);
    }
    lcd.setCursor(position,1);
    lcd.write((byte)1);
    delay(200);
  }
}

