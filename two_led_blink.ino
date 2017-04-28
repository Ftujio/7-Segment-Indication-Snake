int num = 1;
int old;
int button = 0;

void setup() {
  int i;
  
  Serial.begin(9600);
  pinMode(12, INPUT);
  
  for(i = 2; i <= 9; i++){
    pinMode(i, OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  int i;
  old = button;
  button = digitalRead(12);

  if(old == !button){
    if(button == 1){
      if(num < 6){
        num = num + 1;
      } else {
        num = 1;  
      }
    }
  }

  Serial.println(num);

  //snake();
  runSnake();
}

void runSnake(){
  int i, k;
  
  for(i = 1; i < 7; i++){
    for(k = 0; k < num; k++){
      digitalWrite(mapNum(i + k), HIGH);
    }

    delay(analogRead(A0));

    for(k = 0; k < num; k++){
      digitalWrite(mapNum(i + k), LOW);
    }
  }
}

int mapNum(int num){
  int val;
  
  switch(num){
    case 1:
      val = 3;
      break;
    case 2:
      val = 4;
      break;
    case 3:
      val = 6;
      break;
    case 4:
      val = 7;
      break;
    case 5:
      val = 8;
      break;
    case 6:
      val = 2;
      break;
  }

  return val;
}
