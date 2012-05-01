#include <LiquidCrystal.h>

// consts for the number of rows and columns
const int numRows = 2;
const int numCols = 16;

//Faces
byte happy[8] = 
{
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};
byte sad[8] = 
{
  B00000,
  B10001,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000
};
byte shock[8] = 
{
  B00000,
  B10001,
  B00000,
  B00000,
  B00100,
  B01110,
  B00100,
  B00000
};

//Initialise the library with the number of the interface pins
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0, happy);
  lcd.createChar(1, sad);
  lcd.createChar(2, shock);
  
  lcd.begin(numCols, numRows);
  
  lcd.print("Hello");
  
  int i = 0;
  lcd.write(' ');
  lcd.write(i);
}

void loop() {
  // put your main code here, to run repeatedly: 
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
  if(millis()/1000 > 10){
     lcd.setCursor(6,0);
     int i = 2;
    lcd.write(i); 
  }
}
