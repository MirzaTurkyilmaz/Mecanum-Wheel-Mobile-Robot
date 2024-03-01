// MYSS Mecanum Mobile Robot


int IN_11 = 4;
int IN_12 = 2;
int IN_13 = 5;
int IN_14 = 7;
int IN_21 = 8;
int IN_22 = 11;
int IN_23 = 13;
int IN_24 = 12;

int ENA = 3;
int ENB = 6;
int ENC = 9;
int END = 10;

int command;             //Int to store app command state.
boolean state = 1;



void stopRobot() {
  
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, LOW);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, LOW);
  
  digitalWrite(IN_24, LOW);
  digitalWrite(IN_23, LOW);
  
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_21, LOW);

//  analogWrite (ENA, 150);
//  analogWrite (ENB, 150);
//  analogWrite (ENC, 150);
//  analogWrite (END, 150);

}

void back() {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
 
  digitalWrite(IN_24, HIGH);
  digitalWrite(IN_23, LOW);
  
  digitalWrite(IN_22, HIGH);
  digitalWrite(IN_21, LOW);
  
  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}

void forward () {
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);

  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);
  
  digitalWrite(IN_24, LOW);
  digitalWrite(IN_23, HIGH);
 
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_21, HIGH);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
 
}
void left() {
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  
  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
  
  digitalWrite(IN_24, LOW);
  digitalWrite(IN_23, HIGH);
  
  digitalWrite(IN_22, HIGH);
  digitalWrite(IN_21, LOW);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}
void right() {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  
  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);

  digitalWrite(IN_24, HIGH);
  digitalWrite(IN_23, LOW);
 
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_21, HIGH);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}
void superleft () {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  
  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);

  digitalWrite(IN_24, LOW);
  digitalWrite(IN_23, HIGH);

  digitalWrite(IN_22, HIGH);
  digitalWrite(IN_21, LOW);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}
void superright () {
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
 
  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
 
  digitalWrite(IN_24, HIGH);
  digitalWrite(IN_23, LOW);
 
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_21, HIGH);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);

}
void forwardright () {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, LOW);

  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);

  digitalWrite(IN_24, LOW);
  digitalWrite(IN_23, LOW);

  digitalWrite(IN_22, LOW);
  digitalWrite(IN_21, HIGH);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}
void forwardleft () {
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  
  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, LOW);
  
  digitalWrite(IN_24, LOW);
  digitalWrite(IN_23, HIGH);
 
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_21, LOW);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}
void backleft () {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, LOW);
 
  digitalWrite(IN_24, HIGH);
  digitalWrite(IN_23, LOW);
  
  digitalWrite(IN_22, LOW);
  digitalWrite(IN_21, LOW);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}
void backright () {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, LOW);
  
  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
  
  digitalWrite(IN_24, LOW);
  digitalWrite(IN_23, LOW);
  
  digitalWrite(IN_22, HIGH);
  digitalWrite(IN_21, LOW);

  analogWrite (ENA, 200);
  analogWrite (ENB, 255);
  analogWrite (ENC, 180);
  analogWrite (END, 170);
  
}
void setup() {
  Serial.begin (9600);
  
  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);
  pinMode(IN_14, OUTPUT);

  pinMode(IN_21, OUTPUT);
  pinMode(IN_22, OUTPUT);
  pinMode(IN_23, OUTPUT);
  pinMode(IN_24, OUTPUT);

   
}
// MYSS Mecanum Mobile Robot

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    if (command == 'X') {
      state = 1;
    } else if (command == 'x') {
      state = 0;
    }
    if (command == 'B') {
      back();
    } else if (command == 'F') {
      forward();
    } else if (command == 'R' && state == 1) {
      superright ();
    } else if (command == 'L' && state == 1) {
      superleft ();
    } else if (command == 'R' && state == 0) {
      right ();
    } else if (command == 'L' && state == 0) {
      left ();
    } else if (command == 'G') {
      forwardleft ();
    } else if (command == 'I') {
      forwardright ();
    } else if (command == 'H') {
      backright ();
    } else if (command == 'J') {
      backleft ();
    }  else {
      stopRobot();
    }
  }
}

// MYSS Mecanum Mobile Robot
