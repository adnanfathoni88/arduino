int lengthClick = 0;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT); // merah
  pinMode(4, OUTPUT); // kuning
  pinMode(5, OUTPUT); // hijau
}

void loop() {
  if(digitalRead(2) == false){

    while (digitalRead(2) == false){}

    lengthClick++;

    if(lengthClick == 1){
      digitalWrite(3, true);
      digitalWrite(4, false);
      digitalWrite(5, false);
    }else if(lengthClick == 2){
      digitalWrite(4, true);
      digitalWrite(3, false);
      digitalWrite(5, false);
    }else if(lengthClick == 3){
      digitalWrite(5, true);
      digitalWrite(4, false);
      digitalWrite(3, false);
    }else if(lengthClick == 4){
      digitalWrite(5, false);
      digitalWrite(4, false);
      digitalWrite(3, false);
      lengthClick = 0;
    }
  }

  delay(20);
}
