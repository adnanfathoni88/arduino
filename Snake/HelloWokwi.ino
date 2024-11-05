#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1107_128X128_1_HW_I2C u8g2(U8G2_R0); // Inisialisasi OLED 128x128, HW I2C

// Ukuran layar dan parameter ular
const int screenWidth = 128;
const int screenHeight = 128;
const int snakeSegmentSize = 5; // Ukuran tiap segmen ular
const int maxSnakeLength = 20;  // Panjang maksimal ular (dalam segmen)

// analog
int HORZ = A0;  // Pin untuk sumbu horizontal (X)
int VERT = A1;  // Pin untuk sumbu vertikal (Y)
int SEL = 2;    // Pin untuk tombol (push button)

struct SnakeSegment {
  int x, y;
};

SnakeSegment snake[maxSnakeLength]; // Array segmen untuk menyimpan posisi ular
int snakeLength = 5;                // Panjang awal ular
int dx = snakeSegmentSize;          // Kecepatan gerak (arah x)
int dy = 0;                         // Kecepatan gerak (arah y)

void setup() {
  // analog
  Serial.begin(9600);
  pinMode(SEL, INPUT_PULLUP);

  u8g2.begin();
  u8g2.setContrast(255);

  // Inisialisasi posisi ular di tengah layar
  for (int i = 0; i < snakeLength; i++) {
    snake[i].x = screenWidth / 2 - i * snakeSegmentSize;
    snake[i].y = screenHeight / 2;
  }

}

void loop() {

  // Membaca nilai analog dari sumbu X dan Y
  int xValue = analogRead(HORZ);
  int yValue = analogRead(VERT);

  int selState = digitalRead(SEL);


  // Menampilkan hasil pembacaan pada Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print("\tY: ");
  Serial.print(yValue);
  Serial.print("\tSEL: ");
  Serial.println(selState);

  delay(100); // Jeda 100 ms untuk memudahkan pembacaan


  // Geser setiap segmen ular ke posisi segmen sebelumnya (memperbarui posisi ular)
  for (int i = snakeLength - 1; i > 0; i--) {
    snake[i].x = snake[i - 1].x;
    snake[i].y = snake[i - 1].y;
  }

  // Gerakkan kepala ular
  snake[0].x += dx;
  snake[0].y += dy;

  // Memastikan ular muncul kembali dari sisi berlawanan jika keluar dari layar
  if (snake[0].x >= screenWidth) snake[0].x = 0;
  if (snake[0].x < 0) snake[0].x = screenWidth - snakeSegmentSize;
  if (snake[0].y >= screenHeight) snake[0].y = 0;
  if (snake[0].y < 0) snake[0].y = screenHeight - snakeSegmentSize;

  // Menggambar ular pada layar OLED
  u8g2.firstPage();
  do {
    for (int i = 0; i < snakeLength; i++) {
      u8g2.drawBox(snake[i].x, snake[i].y, snakeSegmentSize, snakeSegmentSize); // Menggambar tiap segmen sebagai kotak
    }
  } while (u8g2.nextPage());

  // Ubah arah secara acak setiap beberapa langkah (opsional, agar lebih dinamis)
  if (random(10) < 2) {
    int newDirection = random(4);
    if (newDirection == 0 && dx == 0) { dx = snakeSegmentSize; dy = 0; }   // Kanan
    if (newDirection == 1 && dx == 0) { dx = -snakeSegmentSize; dy = 0; }  // Kiri
    if (newDirection == 2 && dy == 0) { dx = 0; dy = snakeSegmentSize; }   // Bawah
    if (newDirection == 3 && dy == 0) { dx = 0; dy = -snakeSegmentSize; }  // Atas
  }

  delay(200); // Kontrol kecepatan ular
}