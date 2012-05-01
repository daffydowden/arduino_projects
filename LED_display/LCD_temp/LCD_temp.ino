//LCD: http://www.hobbytronics.co.uk/tutorials-code/arduino-tutorials/ds18b20-arduino
//Temp: http://www.hobbytronics.co.uk/tutorials-code/arduino-tutorials/ds18b20-arduino

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// consts for the number of rows and columns
const int numRows = 2;
const int numCols = 16;

const byte degreeSym = B11011111;
// data wire is plugged into pin 2
#define ONE_WIRE_BUS 6

OneWire oneWire(ONE_WIRE_BUS);

//Pass onWire ref to Dallas temp
DallasTemperature sensors(&oneWire);

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
  
  lcd.print("Current Temp");
  
  int i = 0;
  lcd.write(' ');
  lcd.write(i);
  
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  
  lcd.setCursor(0,1);
  
  float currentTempC = sensors.getTempCByIndex(0);
  float currentTempF = sensors.getTempFByIndex(0);
  
  lcd.print(currentTempC);
  lcd.write(degreeSym);
  lcd.print("C");
  
  lcd.setCursor(9,1);
  lcd.print(currentTempF);
  lcd.write(degreeSym);
  lcd.print("F");
  
//  lcd.print(millis()/1000);
//  if(millis()/1000 > 10){
//     lcd.setCursor(6,0);
//     int i = 2;
//    lcd.write(i); 
//  }
}
