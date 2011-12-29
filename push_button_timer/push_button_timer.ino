/*
  Countdown timer
*/


const int ledPin = 13;
const int inputPin = 2;

const int debounceTime = 20; // time in milliseconds required for stable switch

const int fastIncrement = 1000; // increment faster after this many m seconds

const int vFastIncrement = 4000; // increment even faster after this many

int count = 0; // 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin, HIGH); // Turn on internal pull-up
  Serial.begin(9600);
}

void loop() {
  int duration = switchTime();
  
  if(duration > vFastIncrement) {
    count = count + 10;
  } else if (duration > fastIncrement) {
    count = count + 4;
  } else if (duration > debounceTime) {
    count = count + 1;
  } else {
    // switch not pressed
    if (count == 0) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
      count = count - 1;
    }
  }
  Serial.println(count);
  delay(100);
}

// return time in milliseconds that the switch has been pressed
long switchTime() {
  static unsigned long startTime = 0;
  
  static boolean state;
  
  if(digitalRead(inputPin) != state) {
    state = ! state;
    startTime = millis();
  }
  if (state == LOW){
    return millis() - startTime; // switch pushed, return time in milliseconds
  } else {
    return 0;  
  }
}
