#include <LiquidCrystal.h>
int dt = 1000;
int rs = 2;
int en = 3;
int d4 = 4;
int d5 = 5;
int d6 = 6;
int d7 = 7;
int j;
int num1;
int num2;
int val;
String op;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("Enter number 1");
Serial.println("Enter your first number");
while (Serial.available() == 0){}
num1 = Serial.parseInt();
lcd.setCursor(0, 1);
lcd.print(num1);
delay(dt);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Enter number 2");
Serial.println("Enter your second number");
while (Serial.available() == 0){}
num2 = Serial.parseInt();
lcd.setCursor(0, 1);
lcd.print(num2);
delay(dt);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Enter operator");
Serial.println("Enter your operator");
while (Serial.available() == 0){}
op = Serial.readString();
lcd.setCursor(0, 1);
lcd.print(op);
delay(dt);
lcd.clear();

if (op == "+"){
  val = num1 + num2;
} else if(op == "-"){
  val = num1 - num2;
} else if(op == "*"){
  val = num1 * num2;
} else if(op == "/"){
  val = num1 / num2;
} else{
  lcd.print("Invalid Operator");
  lcd.setCursor(0,1);
  lcd.print("Try Again");
}
  lcd.setCursor(0,0);
  lcd.print(num1);
  lcd.print(' ');
  lcd.print(op);
  lcd.print(' ');
  lcd.print(num2);
  lcd.print(" = ");
  lcd.print(val);

  delay(3000);
}
