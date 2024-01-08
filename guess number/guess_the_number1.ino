#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (9,A1,A2,A3,A4,A5);

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pin_rows[ROW_NUM] = {8, 7, 6, 5};   //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
 int i = 13;
 int inputInt;
 String inputString;
 int randNumber;
 int num=0;
 char key;
void setup() {
  
     Serial.begin(9600);
     lcd.begin(16,2);
     inputString.reserve(3);
    // Serial.setTimeout(100);
     randomSeed(analogRead(A0));
     randNumber = random(0, 100);
     Serial.print("randam no:" );
     Serial.println(randNumber);
     lcd.clear();
     lcd.setCursor(2,0);
     lcd.print("Guess the no.");
     lcd.setCursor(4,1);
     lcd.print("welcome");
     delay(2000);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("guess number");
     lcd.setCursor(0,1);
     lcd.print("between 0-99");
     delay(2000);
     lcd.clear();




  
    do{
       key = keypad.getKey();
      
      lcd.setCursor(0,0);
      lcd.print("Guess the no:");
      
      if (key >= '0' && key <= '9' || key =='#' || key == '*')
        {     
          inputString += key;
          Serial.println(inputString); 
          lcd.clear();
          lcd.setCursor(14,0);
          lcd.print(inputString);  

              if(key =='#')
                {
                  inputInt = inputString.toInt(); 
                  inputString = "";  
                  Serial.println(inputInt);
                  
                  if (randNumber<inputInt)
                  {             
                    lcd.setCursor(0,0);
                    lcd.print("lower no plz      ");
                    delay(2000);
                    lcd.clear();
                    num = num+1;
                  }

                  if(randNumber > inputInt)
                  {              
                    lcd.setCursor(0,0);
                    lcd.print("greater no plz  ");
                    delay(2000);
                    lcd.clear();
                     num = num+1;
                  }

                  if(randNumber==inputInt)
                  {
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("you guess no.in ");
                    num = num+1;
                    lcd.setCursor(0,1);
                    lcd.print(num);
                    lcd.setCursor(3,1);
                    lcd.print("attempt");
                    delay(3000); 
                    lcd.clear();
                    num =0;
                    lcd.print("Game over");
                    delay(2000);
                    
                  }
                  
                }
                

                if(key == '*')
                {
                   inputString = "";                 // clear input
                   lcd.clear();
                   i=0;
                }
                
        
}    
  }while(randNumber != inputInt);
          
}
void loop() {}