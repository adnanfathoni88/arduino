#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5
#define PIN_E 6
#define PIN_F 7
#define PIN_G 8
#define PIN_H 9
// #define PIN_DP 9
#define ANGKA_DELAY 1000

const int digits[12][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0, 1}, // 2
  {0, 0, 0, 0, 1, 1, 0, 1}, // 3
  {1, 0, 0, 1, 1, 0, 0, 1}, // 4
  {0, 1, 0, 0, 1, 0, 0, 1}, // 5
  {0, 1, 0, 0, 0, 0, 0, 1}, // 6
  {0, 0, 0, 1, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0, 1}, // 8
  {0, 0, 0, 0, 1, 0, 0, 1},  // 9
  {1, 1, 1, 1, 1, 1, 1, 0},  // 10
  {1, 1, 1, 1, 1, 1, 1, 0},  // f
};

void displayNumber(int num) {
  // if (num < 0 || num > 10) return; // Check for valid digit

  digitalWrite(PIN_A, digits[num][0]);
  digitalWrite(PIN_B, digits[num][1]);
  digitalWrite(PIN_C, digits[num][2]);
  digitalWrite(PIN_D, digits[num][3]);
  digitalWrite(PIN_E, digits[num][4]);
  digitalWrite(PIN_F, digits[num][5]);
  digitalWrite(PIN_G, digits[num][6]);
  digitalWrite(PIN_H, digits[num][7]);
  delay(ANGKA_DELAY);
}


void NIM() {

  displayNumber(5); // Angka 2
  displayNumber(7); // Angka 2
  displayNumber(5); // Angka 2
  displayNumber(8); // Angka 2

  displayNumber(10); // -

  displayNumber(1); // Angka 2
  displayNumber(5); // Angka 2
  displayNumber(9); // Angka 2
  displayNumber(1); // Angka 2

  displayNumber(10); // -

  displayNumber(5); // Angka 2
  displayNumber(8); // Angka 2
  displayNumber(0); // Angka 2
  displayNumber(2); // Angka 2

  displayNumber(10); // -


  displayNumber(5); // Angka 2
  displayNumber(8); // Angka 2
  displayNumber(0); // Angka 2
  displayNumber(3); // Angka 2

  displayNumber(10); // -

  displayNumber(5); // Angka 2
  displayNumber(7); // Angka 2
  displayNumber(8); // Angka 2
  displayNumber(6); // Angka 2

}

void setup() {
  // Initialize pin modes
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_H, OUTPUT);
}

void loop() {
  NIM();
}
