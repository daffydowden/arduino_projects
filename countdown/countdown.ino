/* Arduino timer countdown thingy */


// Switches
const int startPin = 2; // Pin for ON switch
const int resetPin = 3; // Pin for reset switch

// LEDs
const int activePin = 13; // Pin for activated LED

const int grn1 = 5; // Countdown LEDs
const int yel1 = 6;
const int yel2 = 9;
const int red1 = 10;
const int red2 = 11;

// SPEAKER
#define NOTE_C3  131
#define NOTE_C4  262
#define NOTE_C5  523
#define NOTE_C6  1047
#define NOTE_C7  2093
#define NOTE_C8  4186
int notes[] = {NOTE_C8, NOTE_C7, NOTE_C6, NOTE_C5, NOTE_C4};
int duration[] = {2,3,4,6,8};
const int speaker = 12;

int countdownTime = 10; // Time in seconds to countdown from

int status = 0; // Device status

// Setup
void setup(){
  Serial.begin(9600);
  
  // Setup LEDs  
  pinMode(activePin, OUTPUT); // Activated LED
  pinMode(grn1, OUTPUT); // Colour LEDs
  pinMode(yel1, OUTPUT); 
  pinMode(yel2, OUTPUT);
  pinMode(red1, OUTPUT); 
  pinMode(red2, OUTPUT); 
  
  // Setup ON Switch
  pinMode(startPin, INPUT);
  digitalWrite(startPin, HIGH); // turn on internal pull-up resistor
  // Setup RESET Swtich
  pinMode(resetPin, INPUT);
  digitalWrite(resetPin, HIGH); // turn on internal pull-up resistor
}


void loop(){
  // Check pin values  
  int onVal = digitalRead(startPin);
  int resetVal = digitalRead(resetPin);
  
  // Check ON switch
  if (onVal == LOW){
    // Check status
    if (status == 0) {
      activate();
    }
  }
  // Check RESET switch
  if (resetVal == LOW){
    // Check status
    if (status == 1) {
      reset();
    }
  }
  
  // If active, countdown
  if (status == 1){
    for(int i = countdownTime; i >= 0; i--){
      tick(i);
    }
    explode();
  }
}

// Activate countdown
void activate() {
  // Turn on Active LED
  digitalWrite(activePin, HIGH);
  Serial.println("ACTIVATED");
  status = 1;
}

// Soft reset of system
void reset() {
  digitalWrite(activePin, LOW);
  Serial.println("DEACTIVATED");
  status = 0;
}

void explode(){
  // Switch off LEDs, except RED
  digitalWrite(activePin, LOW);
  digitalWrite(grn1, LOW);
  digitalWrite(yel1, LOW);
  digitalWrite(yel2, LOW);
  
  tone(speaker, NOTE_C8, 2000);    
  delay(1000);
  noTone(speaker);
  
  Serial.println("BOOM!");
  status = 0;
}

void tick(int time) {
  Serial.println(time);
      
  int x = floor(time/2);
  int noteDuration = 1000/duration[x];
  tone(speaker, notes[x], noteDuration);
  
  delay(1000);
  noTone(speaker);
  
  lights(time);
}

void lights(int time){
  int nTime = ceil(time/2);
  
  switch(nTime){
    case 5:
      digitalWrite(grn1, HIGH);
      break;
    case 4:
      digitalWrite(yel1, HIGH);
      break;
    case 3:
      digitalWrite(yel2, HIGH);
      break;
    case 2:
      digitalWrite(red1, HIGH);
      break;
    case 1:
      digitalWrite(red2, HIGH);
      break;
  }
}
