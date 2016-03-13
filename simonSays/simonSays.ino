/* Created by 7blink
  7blink.com
  */
  
//Global Variables
//Declare inputs
int input1 = 8;
int input2 = 9;
int input3 = 10;
int input4 = 11;

//Declare output leds
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int disPin[4] = {led1, led2, led3, led4};

//Array to store the computer solution
//And the player inputs
int solution[100];
int player[100];

//Variable to keep track of current level
//and current entry of the player input.
int level;
int entry;

//Gameplay boolean lets the game continue.
//If false, it sets up a new game
//InputYet checks if the player presses a button
//Else it will continue looping until the player does.
boolean gamePlay;
boolean inputYet;

//Button press pause
//And LED display pause.
int pauseT = 10;
int disDelay = 200;



void setup(){
  //Set the pins to input
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);
  
  //Set the output pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  //RNG set from unused analog noise.
  randomSeed(analogRead(4));
}

//gameSetup() sets up a new game
//and sets all variables back to defaults
void gameSetup(){
  
  //For solution[] set 100 random non repeating numbers.
 for (int i = 0; i < 100; i++){
  solution[i] = random(4);
  
  if(i>0){
    //If the number is a repeat of the last one
    //retry until it is a new number
    while(solution[i] == solution[i-1]){
      solution[i] = random(4);
    }
  }
  
  //Set the player's array to zeros
  player[i] = 0;
 } 
 
 //Set the level to zero
 //then gamePlay to true to start the game
 level = 0;
 gamePlay = true;
}

//mainLoop is the main game loop.
//If gameplay is false, it will exit the loop
void mainLoop(){
  while(gamePlay){
    displayLevel();
    
    //Loop to take the player's input
    //from zero through the current number of displayed LEDs
    for(entry=0; entry<=level; entry++){
      
      //Loop through until the player presses a button
      inputYet = false;
      while(!inputYet){
       buttonPressed();
      }
      
      //If any of the buttons don't match, break out of for loop
      if(solution[entry] != player[entry]){
        entry = level+1;
        break;
      }
    }
    
    //If every entry matches solution, increase level;
    if(correct()){
     success(); 
     level++;
    }
    
    //Else end current game.
    else{
    gamePlay = false;
    failure();
    }
  }
}

//Loop to check each player's input against the solution
boolean correct(){
  for(int i=0; i<=level; i++){
    if(solution[i] != player[i]){
      return false;
    }
  }
  //returns true if everything matches
  return true;
}

//Displays the current level to the player.
void displayLevel(){
 for(int i = 0; i<= level; i++){
  digitalWrite(disPin[solution[i]], HIGH);
  delay(disDelay);
  digitalWrite(disPin[solution[i]], LOW);
  delay(disDelay);
 } 
}

//If any button is pressed,
//Blink the LED, then add the entry to the player array
//Then set inputYet to true so that the main loop can continue.
void buttonPressed(){
  if(digitalRead(input1) == HIGH){
    pause(input1, led1);
    player[entry] = 0;
    inputYet = true;
  }
  if(digitalRead(input2) == HIGH){
    pause(input2, led2);
    player[entry] = 1;
    inputYet = true;
  }
  if(digitalRead(input3) == HIGH){
    pause(input3, led3);
    player[entry] = 2;
    inputYet = true;
  }
  if(digitalRead(input4) == HIGH){
    pause(input4, led4);
    player[entry] = 3;
    inputYet = true;
  }
}

//Pause loop debounces the button
//to prevent multiple inputs from one button press.
//Also blink the LED.
void pause(int inputnum, int lednum){
  digitalWrite(lednum, HIGH);
  
//Wait until the button is released, then turn off LED and continue.
  while(digitalRead(inputnum) == HIGH){
    delay(pauseT);
  }
  digitalWrite(lednum, LOW);
  delay(pauseT);
}

//Method to display the success pattern of LED's.
void success(){
 for(int k=0; k<2; k++){
  for(int l=0; l<4; l++){
   digitalWrite(disPin[l], HIGH); 
   delay(100);
   digitalWrite(disPin[l], LOW);
   delay(100);
  }
 }
 for(int k=0; k<3; k++){
  for(int l=0; l<4; l++){
   digitalWrite(disPin[l], HIGH);
  } 
  
  delay(100);
  
  for(int l=0; l<4; l++){
   digitalWrite(disPin[l], LOW); 
  }
  
  delay(100);
 }
 
 delay(600);
}

//Method to display the failure pattern of LED's
void failure(){
  for(int i=0; i<4; i++){
    digitalWrite(disPin[i], HIGH);
  }
  
  delay(1500);
  
  for(int i=0; i<4; i++){
    digitalWrite(disPin[i], LOW);
  }
  
  delay(1000);
}

//Arduino will loop continuesly through this method
//This just creates a new game, then starts the main game loop.
void loop(){
  
  gameSetup();
  
  mainLoop();
}
  
