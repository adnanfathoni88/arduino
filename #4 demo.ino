unsigned long currTime;
unsigned long lastTimeR = 0;
unsigned long lastTimeY = 0;
unsigned long lastTimeG = 0;

const int pinR = 4;
const int pinY = 5;
const int pinG = 6;

bool onR = false; // red
bool onY = false; // yellow
bool onG = false; // green
bool isActive = false;

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(pinR, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinG, OUTPUT);
}

void onLamp(lamp){}

void loop() {
  currTime = millis();

  // input from string
    String cmd = Serial.readString();
    cmd.trim();

    if (cmd == "ON") {
      isActive = true;
      Serial.println("on");

    } else if (cmd == "OFF") {
      isActive = false;
      Serial.println("off");
      digitalWrite(pinR, LOW);
      digitalWrite(pinY, LOW);
      digitalWrite(pinG, LOW);
    } else if (cmd == "ONR") {
      digitalWrite(pinR, HIGH);
    }else if (cmd == "OFFR") {
      digitalWrite(pinR, LOW);
    }else if (cmd == "ONY") {
      digitalWrite(pinY, HIGH);
    }else if (cmd == "OFFY") {
      digitalWrite(pinY, LOW);
    }else if (cmd == "ONG") {
      digitalWrite(pinG, HIGH);
    }else if (cmd == "OFFG") {
      digitalWrite(pinG, LOW);
    }
  

  if (isActive) {
    // red
    if (currTime - lastTimeR >= 1000) {
      onR = !onR; 
      lastTimeR = currTime;
    }

    // yellow
    if (currTime - lastTimeY >= 2000) {
      onY = !onY; 
      lastTimeY = currTime;
    }

    // green
    if (currTime - lastTimeG >= 3000) {
      onG = !onG; 
      lastTimeG = currTime;
    }

    digitalWrite(pinR, onR);
    digitalWrite(pinY, onY);
    digitalWrite(pinG, onG);
  }  
}
