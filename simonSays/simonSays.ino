/* Created by 7blink
  7blink.com
  */
  
int input1 = 8;
int input2 = 9;
int input3 = 10;
int input4 = 11;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

int pauseT = 200;

void setup(){
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  Serial.print("Starting");
  digitalWrite(led1, LOW);
}

void pause(int inputnum, int lednum){
  digitalWrite(lednum, HIGH);
  while(digitalRead(inputnum) == HIGH){
    delay(pauseT);
  }
  digitalWrite(lednum, LOW);
}

void buttonPressed(){
  if(digitalRead(input1) == HIGH){
    Serial.print("button1");
    pause(input1, led1);
  }
  if(digitalRead(input2) == HIGH){
    Serial.print("button2");
    pause(input2, led2);
  }
  if(digitalRead(input3) == HIGH){
    Serial.print("button3");
    pause(input3, led3);
  }
  if(digitalRead(input4) == HIGH){
    Serial.print("button4");
    pause(input4, led4);
  }
}
void loop(){
  
  buttonPressed();
}
  
