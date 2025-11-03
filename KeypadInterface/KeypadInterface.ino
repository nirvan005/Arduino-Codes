#include<Keypad.h>

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

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad Test Started. Press any key...");
}

void loop() {
  char customKey=customKeypad.getKey();
  if(customKey){
    Serial.print("Key Pressed: ");
    Serial.println(customKey);
  }
}
