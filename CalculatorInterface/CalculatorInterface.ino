#include<Keypad.h>
// #include<LiquidCrystal_I2C.h>
#include<DFRobot_RGBLCD1602.h>
#include<Wire.h>

DFRobot_RGBLCD1602 lcd(0x27);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS]={
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'O','0','=','+'},
};

byte rowPins[ROWS]={9,8,7,6};
byte colPins[COLS]={5,4,3,2};

Keypad customKeypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

float operand1=0;
float operand2=0;
char operatorChar=' ';
String currentInput="";
bool calculated=false;

void resetCalculator(){
  operand1=0;
  operand2=0;
  operatorChar=' ';
  currentInput="";
  calculated=false;
  lcd.clear();
  lcd.print("Ready");
}

float performCalculation(float a, float b, char op) {
  switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': 
      if(b==0){ 
        lcd.clear();
        lcd.print("Error: Div/0");
        delay(2000);
        return 0;
      }
      return a / b;
    default: return a;
  }
}

void setup() {
  delay(100);
  lcd.init();
  delay(50);
  lcd.setBacklight(true);
  lcd.setCursor(0, 0);
  lcd.print("Arduino Calculator");
  delay(2000);
  resetCalculator();
}

void loop() {
  char key=customKeypad.getKey();
  if(key){
    if(key=='O'){
      resetCalculator();
      return;
    }
    if(isdigit(key)){
      if(calculated){
        currentInput="";
        calculated=false;
      }
      currentInput+=key;
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(currentInput);
    }
    else if(key=='+' || key=='-' || key=='*' || key=='/'){
      if(currentInput.length()>0 && operatorChar==' '){
        operand1=currentInput.toFloat();
        operatorChar=key;
        currentInput="";
        calculated=false;

        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,0);
        lcd.print(operand1,2);
        lcd.print(operatorChar);
      }
    }
    else if(key=='='){
      if(currentInput.length()>0 && operatorChar!=' '){
        operand2=currentInput.toFloat();
        float result=performCalculation(operand1,operand2,operatorChar);

        lcd.setCursor(0,0);
        lcd.print(operand1,2);
        lcd.print(operatorChar);
        lcd.print(operand2,2);
        lcd.print('=');

        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print(result,2);

        operand1=result;
        currentInput=String(result);
        operatorChar=' ';
        calculated=true;
      }
    }
  }
}