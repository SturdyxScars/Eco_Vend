#include <Servo.h>
#include<Keypad.h>
#include <LiquidCrystal_I2C.h>

// Define the pins for the coin selector machine
const int coinSelectorPin = A0;
LiquidCrystal_I2C lcd(0x27,16,2);
const int IR_pin = 2;  //define the ir sensor pin

// Define the pins for the servo motor
const int servoPin1 = 12;
Servo myServo;
const int servoPin2 = 11;
Servo servo;
const int servoPin3 = 10;
Servo servonew;

// Define the pins for the keypad
const byte ROWS = 4; // Number of rows on the keypad
const byte COLS = 3; // Number of columns on the keypad
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};    // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3};  // Connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Variables
int randomNum;
int userNum;
boolean correctGuess = false;

void setup() {
  // Initialize the coin selector machine pin
  lcd.init();
  lcd.setCursor(0,0);
  lcd.backlight();
  lcd.print("Insert a Coin");
  pinMode(coinSelectorPin, INPUT);
  // Initialize the servo motor
  myServo.attach(servoPin1);
  servo.attach(servoPin2);
  servonew.attach(servoPin3);
  pinMode(IR_pin,INPUT);  // output at reception of arduino

  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Insert a Coin");
 
  

  lcd.setCursor(0,1);
  // Step 1: Wait for a coin to be inserted
  while (digitalRead(coinSelectorPin) != HIGH) {
    // Wait for coin insertion
  };
   // Step 2: Rotate the servo motor
   correctGuess = true;
  if(digitalRead(coinSelectorPin)== HIGH && correctGuess == true)
  {
    lcd.print("Detected");
    
    myServo.write(0);  // Rotate the servo to complete one rotation
  delay(3000);      // Wait for the servo to complete rotation
  myServo.write(90); // Stop the servo at the initial position
  
 
  // Step 3: Generate a random number
  randomNum = generateRandomNumber();
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  Serial.print("Random num:");
  lcd.print("Random num:");
  Serial.println(randomNum);
  lcd.setCursor(11,0);
  lcd.println(randomNum);
  lcd.setCursor(0,1);
  userNum = getUserInput();
  lcd.println(userNum);
  }
 

  // Step 4: Wait for the user to enter a three-digit number
  

  // Step 5: Check if the user's guess is correct
  if (userNum == randomNum) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("Correct!");
    delay(3000);
    Serial.println("Correct!");
    correctGuess = true;
    servo.write(0);
    delay(1000);
    servo.write(180);
    delay(1000);

    //ir working for dispensing of reward.


     int sensorValue = digitalRead(IR_pin);
  
    Serial.println(sensorValue);
    while(digitalRead(IR_pin)==HIGH){
    if (sensorValue == HIGH) {
    servonew.write(0);
    delay(1000);
    servonew.write(90);
    
    // Object detected, rotate the servo motor
      // Rotate to 90 degrees
  } 
    else if(sensorValue == LOW){
    // No object detected, stop the servo motor
       // Rotate to 0 degrees
    
    servonew.write(90); 
  }
    }
  
  

  delay(100);  // Delay for stability
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Incorrect");
    Serial.println("Incorrect!");
    delay(3000);
    correctGuess = false;
  }

  // Reset variables
  randomNum = 0;
  userNum = 0;
  correctGuess = false;
}

int generateRandomNumber() {
  randomSeed(analogRead(A0));  // Seed the random number generator with analog input
  return random(100, 999);     
}

int getUserInput() {
  char key;
  String inputString;

  while (inputString.length() < 4) {
    
    
    key = keypad.getKey();
    if(key=='#') break;

    if (key) {
      inputString += key;
      lcd.println(key);
     
      Serial.println(key);  // Print the entered digit to the serial monitor
    }
    
  }
   
  
  Serial.println();  // Move to the next line in the serial monitor
  lcd.clear();
  return inputString.toInt();
}
void rotation(){
  servonew.write(90);
  delay(1000);
  
}
