/* Created by 7blink
  7blink.com
  */
  
int input1 = 8;
int input2 = 9;
int input3 = 10;
int input4 = 11;

int led1 = 13;

int delay = 200;

void setup(){
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);
  
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
  Serial.print("Starting");
  digitalWrite(led1, LOW);
}

void buttonPressed(){
  if(digitalRead(input1) == HIGH){
    Serial.print("button1");
    while(digitalRead(input1) == HIGH){
      delay(delay);
    }
  }
  if(digitalRead(input2) == HIGH){
    Serial.print("button2");
  }
  if(digitalRead(input3) == HIGH){
    Serial.print("button3");
  }
  if(digitalRead(input4) == HIGH){
    Serial.print("button4");
  }
}
void loop(){
  
  buttonPressed();
}
  
