/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin2 = 2;
const int buttonPin1 = 4;  
const int ledPin1 =  12;
const int ledPin2 =  13;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lightMode = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin1);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    lightMode = 1;
  }
  
  buttonState = digitalRead(buttonPin2);
  if (buttonState == HIGH) {
    lightMode = 2;  
  }

  if (lightMode == 0){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  else if(lightMode == 1){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  }
  else if(lightMode == 2){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW);
  }
}
