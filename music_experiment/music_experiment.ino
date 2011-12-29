// Example 04: Fade an LED in and out like on
// a sleeping Apple computer
const int speaker = 9; // the pin for the speaker
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A5 440
#define B5 494
#define C5 523
int note = 0;

void setup() {
}
void loop(){
  for(note=0; note < 8; note++) {
    switch(note)
    { case 0:
    tone(speaker, C4, 1000);
    break;
    
    case 1:
    tone(speaker, D4, 1000);
    break;
    
    case 2:
    tone(speaker, E4, 1000);
    break;
    
    case 3:
    tone(speaker, F4, 1000);
    break;
    
    case 4:
    tone(speaker, G4, 1000);
    break;
    
    case 5:
    tone(speaker, A5, 1000);
    break;
    
    case 6:
    tone(speaker, B5, 1000);
    break;
    
    case 7:
    tone(speaker, C5, 1000);
    break;
    }
delay(1000);
  }
}
