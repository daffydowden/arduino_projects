#include <OneWire.h>
#include <DallasTemperature.h>

// data wire is plugged into pin 2
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

//Pass onWire ref to Dallas temp
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println('Temp demo');
  
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly: 
  
 Serial.print("\nRequesting temps... ");
 sensors.requestTemperatures();
 Serial.println("DONE");
 
 Serial.print("Temp for Device 1 is: ");
 Serial.print(sensors.getTempCByIndex(0));
 Serial.print("\n");
}
