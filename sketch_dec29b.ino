#include <LiquidCrystal.h> 
#include <Keypad.h> 
 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
 
char Keymap [4][3] = { 
  {'1', '2', '3'}, 
  {'4', '5', '6'}, 
  {'7', '8', '9'}, 
  {'*', '0', '#'}, 
}; 
 
byte rowPins[4] = {7,6,5,4}; 
byte colPins[4] = {3,2,1}; 
 
Keypad myKeypad = Keypad(makeKeymap(Keymap), rowPins, colPins, 4, 3); 
 
char password[4] = {'1', '2', '3', '4'}; 
char userpress[4]; 
 
 
 
 
void setup() { 
  pinMode(A5, OUTPUT); 
  pinMode(A4, OUTPUT); 
  pinMode(A0, OUTPUT); 
  lcd.begin(16, 2); 
  lcd.clear(); 
  lcd.print("Press *"); 
 
} 
void loop(){ 
  byte keyCount = 0; 
  char keypressed = myKeypad.getKey(); 
   
  if(keypressed != NO_KEY){ 
    if(keypressed == '*'){ 
      boolean a=1; 
      lcd.clear(); 
      lcd.print("Enter Password:"); 
      lcd.setCursor(0,1); 
 
 
      while(a){ 
        keypressed = myKeypad.getKey(); 
        if (keypressed != NO_KEY){ 
          userpress[keyCount] = keypressed; 
          lcd.print("*"); 
          keyCount++; 
          if (keyCount==4)a=0; 
          } 
      } 
      check_password(); 
      } 
    } 
 
} 
void check_password(){ 
  byte b=0; 
  for(int i=0; i<4; i++){ 
    if (userpress[i] == password[i]){ 
      b++; 
       
      } 
    } 
    if(b==4){ 
      lcd.clear(); 

 
      lcd.print("Valid Password"); 
      digitalWrite(A5, HIGH); 
      digitalWrite(A4, HIGH); 
      delay(3000); 
      digitalWrite(A5, LOW); 
      digitalWrite(A4, LOW); 
      lcd.clear(); 
      lcd.print("Press *"); 
    } 
    else{ 
      lcd.clear(); 
      lcd.print("Invalid Password"); 
      digitalWrite(A0, 1); 
      delay(2000); 
      digitalWrite(A0, 0); 
      lcd.clear(); 
      lcd.print("Press *"); 
      } 
 
} 
