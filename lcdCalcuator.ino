#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
float firstNum;
float secondNum;
float answer;
int dt = 1800;
bool error;
bool wrong;
String op;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setupanswerode here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  error = false;
  wrong = false;
  Serial.println("Please enter your first number: ");
  lcd.setCursor(0, 0);
  lcd.print("First number: ");

  while(Serial.available() == 0) {

  }
  
  firstNum = Serial.parseFloat();

  Serial.print("You entered: ");
  Serial.println(firstNum);

  lcd.setCursor(0, 1);
  lcd.print("Entered: ");
  lcd.print(firstNum);
  delay(dt);
  lcd.clear();
  
  while(Serial.available() > 0) {
    Serial.read();
    lcd.clear();
  }

  Serial.println("Please enter your second number: ");
  lcd.setCursor(0, 0);
  lcd.print("Second number: ");

  while(Serial.available() == 0) {

  }
  
  secondNum = Serial.parseFloat();

  Serial.print("You entered: ");
  Serial.println(secondNum);

  lcd.setCursor(0, 1);
  lcd.print("Entered: ");
  lcd.print(secondNum);
  delay(dt);
  lcd.clear();

  while(Serial.available() > 0) {
    Serial.read();
    lcd.clear();
  }

  Serial.println("Please enter your operator (+,-,*,/)");
  lcd.setCursor(0, 0);
  lcd.print("Operator +,-,*,/ ");

  while(Serial.available() == 0) {

  }

  op = Serial.readString();
  op.trim();

  lcd.setCursor(0, 1);
  lcd.print("Operator: ");
  lcd.print(op);
  Serial.print("Operator: ");
  Serial.println(op);
  delay(dt);

  if(op == "+") {
    answer = firstNum + secondNum;
  } else if(op == "-") {
    answer = firstNum - secondNum;
  } else if(op == "*") {
    answer = firstNum * secondNum;
  } else if(op == "/") {
    if(secondNum == 0) {
      error = true;
    } else {
     answer = firstNum / secondNum;
    }
  } else {
    wrong = true;
  }

  if(error) {
    lcd.clear();
    Serial.println("Error: Cannot divide by zero");
    lcd.setCursor(0, 0);
    lcd.print("Error: ");
    lcd.setCursor(0, 1);
    lcd.print("Divide by 0");
    delay(3000);
  } else if(wrong) {
    lcd.clear();
    Serial.println("Error, please try again");
    lcd.setCursor(0, 0);
    lcd.print("Error");
    delay(dt);
  } else {
    Serial.print("The total is: ");
    Serial.println(answer);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Total: ");
    lcd.setCursor(0, 1);
    lcd.print(firstNum);
    lcd.print(op);
    lcd.print(secondNum);
    lcd.print(" = ");
    lcd.print(answer);
    delay(3000);
  }  

  while(Serial.available() > 0) {
    Serial.read();
    lcd.clear();
  }
        
  lcd.clear();

  }
