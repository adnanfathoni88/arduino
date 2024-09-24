// menyalakan led
const int pinLed13 = 13;
const int pinLed12 = 12;
const int pinLed11 = 11;

void setup() {
  pinMode(pinLed13, OUTPUT);
  pinMode(pinLed12, OUTPUT);
  pinMode(pinLed11, OUTPUT);
}

void loop() {
  digitalWrite(pinLed13, HIGH);
  delay(100);
  digitalWrite(pinLed13, LOW);
  delay(100);

  digitalWrite(pinLed12, HIGH);
  delay(100);
  digitalWrite(pinLed12, LOW);
  delay(100);

  digitalWrite(pinLed11, HIGH);
  delay(100);
  digitalWrite(pinLed11, LOW);
  delay(100);
}
