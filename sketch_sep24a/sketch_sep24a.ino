// Menyalakan LED
const int pinLed11 = 11;
const int pinLed12 = 12;
const int pinLed13 = 13;

void setup() {
  pinMode(pinLed12, OUTPUT);
  pinMode(pinLed11, OUTPUT);
  pinMode(pinLed13, OUTPUT);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(pinLed12, HIGH);
    delay(500);
    digitalWrite(pinLed12, LOW);
    delay(500);
  }
  
  digitalWrite(pinLed13, HIGH);
  digitalWrite(pinLed11, HIGH);
  delay(500);
  digitalWrite(pinLed13, LOW);
  digitalWrite(pinLed11, LOW);
  delay(500);
}
