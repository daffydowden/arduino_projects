/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe
 Modified by R Dowden - 27 Dec 2011 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6 };

void setup() {
  // iterate over the notes of the melody, twice:
  for (int melodyNum = 0; melodyNum < 2; melodyNum++){
    for (int thisNote = 0; thisNote < 11; thisNote++) {

      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      tone(8, melody[thisNote],noteDuration);
  
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
  }
}

void loop() {}
