#include<Keypad.h>
#include<LiquidCrystal.h>
#include<Servo.h>

LiquidCrystal lcd(A4,A5,A3,A2,A1,A0);
Servo servo;
const int buzzer=8;

String password="1234";
String inputPassword="";

int lockedPos=0;
int unlockedPos=90;

const byte ROWS=4;
const byte COLS=3;

char keys[ROWS][COLS]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};

byte rowPins[ROWS]={0,1,2,3};
byte colPins[COLS]={4,5,6};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

int attemptCount=0;
const int maxAttempts=3;

void setup() {
  lcd.begin(16,2);
  servo.attach(9);
  servo.write(lockedPos);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  lcd.print("SMART DOOR-LOCK");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Password:");
}

void loop() {
  char key=keypad.getKey();
  if(key){
    if(key=='#'){
      lcd.clear();
      if(inputPassword==password){
        lcd.print("Access Granted");
        servo.write(unlockedPos);
        delay(2000);
        servo.write(lockedPos);
        lcd.clear();
        lcd.print("Door Locked");
        delay(2000);
        attemptCount=0;
      }
      else{
        attemptCount++;
        lcd.print("Wrong Password");
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        if(attemptCount>=maxAttempts){
          lcd.clear();
          lcd.print("System Locked!!");
          for(int i=0;i<5;i++){
            digitalWrite(buzzer, HIGH);
            delay(200);
            digitalWrite(buzzer, LOW);
            delay(200);
          }
          attemptCount=0;
        }
        delay(2000);
      }
      inputPassword="";
      lcd.clear();
      lcd.print("Enter Password");
    }
    else if(key=='*'){
      inputPassword="";
      lcd.clear();
      lcd.print("Enter Password");
    }
    else{
      inputPassword+=key;
      lcd.setCursor(0, 1);
      for(int i=0;i<inputPassword.length();i++){
        lcd.print('*');
      }
    }
  }
}
