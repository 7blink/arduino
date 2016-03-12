/* Created by 7blink
  7blink.com
  */
  
int input1 = 8;
int input2 = 9;
int input3 = 10;
int input4 = 11;
int inputArray[4] = {input1, input2, input3, input4};

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int disPin[4] = {led1, led2, led3, led4};

int solution[100];
int player[100];
int level;

boolean gamePlay;
boolean inputYet;

int pauseT = 200;
int disDelay = 200;



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
  
  randomSeed(analogRead(0));
}

void pause(int inputnum, int lednum){
  digitalWrite(lednum, HIGH);
  while(digitalRead(inputnum) == HIGH){
    delay(pauseT);
  }
  digitalWrite(lednum, LOW);
  delay(pauseT);
}

void gameSetup(){
 for (int i = 0; i < 100; i++){
  solution[i] = random(3);
  player[i] = 0;
  Serial.print(solution[i]);
 } 
 level = 0;
 gamePlay = true;
}


void mainLoop(){
  while(gamePlay){
    displayLevel();
    
    inputYet = false;
    while(!inputYet){
     buttonPressed(); 
    }
    
    if(solution[level]==player[level]){
     success(); 
    }
  }
}

void displayLevel(){
 for(int i = 0; i<= level; i++){
  digitalWrite(disPin[solution[i]], HIGH);
  delay(disDelay);
  digitalWrite(disPin[solution[i]], LOW);
  delay(disDelay);
 } 
}

void buttonPressed(){
  if(digitalRead(input1) == HIGH){
    Serial.print("button1");
    pause(input1, led1);
    player[level] = 0;
    inputYet = true;
  }
  if(digitalRead(input2) == HIGH){
    Serial.print("button2");
    pause(input2, led2);
    player[level] = 1;
    inputYet = true;
  }
  if(digitalRead(input3) == HIGH){
    Serial.print("button3");
    pause(input3, led3);
    player[level] = 2;
    inputYet = true;
  }
  if(digitalRead(input4) == HIGH){
    Serial.print("button4");
    pause(input4, led4);
    player[level] = 3;
    inputYet = true;
  }
}

void success(){
 for(int k=0; k<3; k++){
  for(int l=0; l<4; l++){
   digitalWrite(disPin[l], HIGH); 
   delay(100);
   digitalWrite(disPin[l], LOW);
   delay(100);
  }
 } 
}

void loop(){
  
  gameSetup();
  
  mainLoop();
}
  
