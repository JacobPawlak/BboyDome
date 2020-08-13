//Jacob Pawlak 
//August 10th, 2020
//Bboy-Dome Lighting system
//goooo blue team


//Loading up all of my constants for the board
const int white = 13;  //button1
const int green = 12;  //button2
const int red = 11;    //button3
const int blue = 10;   //button4
const int multi = 9;   //button5

const int butt_w = 6;
const int butt_g = 5;
const int butt_r = 4;
const int butt_b = 3;
const int butt_m = 2;
const int butt_off = 1; //button6

int color_mode = 0;     //corresponds to button number... { white: 1, green:2, red:3, blue:4, multi:5, off:0 }
int button_state = 0;   //for HIGH | LOW check

//reminding myself that the buttons need 5v power, so ill have to pull that to each bank on the 'f-j' side of the board. if you look at it you'll know what im talking about.
//also that the sensor needs a 220 ohm resistor on the GROUND wire, not the signal.

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(multi, OUTPUT);
  
  pinMode(butt_w, INPUT);
  pinMode(butt_g, INPUT);
  pinMode(butt_r, INPUT);
  pinMode(butt_b, INPUT);
  pinMode(butt_m, INPUT);
  pinMode(butt_off, INPUT);
  
}

// the loop function runs over and over again forever
void loop() {

  //now that the loop is started, we need to read all of the buttons to see if they have been activated by touch.
  //{ white: 1, green:2, red:3, blue:4, multi:5, off:0 }
  button_state = digitalRead(butt_w);
  //if the button has been touched during this loop (which happens almost instantly, at least faster than you can touch two buttons), we need to set the color mode accordingly 
  if (button_state == HIGH) {
    color_mode = 1;
  }
  button_state = digitalRead(butt_g);
  if (button_state == HIGH) {
    color_mode = 2;  
  }
  button_state = digitalRead(butt_r);
  if (button_state == HIGH) {
    color_mode = 3;  
  }
  button_state = digitalRead(butt_b);
  if (button_state == HIGH) {
    color_mode = 4;  
  }
  button_state = digitalRead(butt_m);
  if (button_state == HIGH) {
    color_mode = 5;  
  }
  button_state = digitalRead(butt_off);
  if (button_state == HIGH) {
    color_mode = 0;  
  }

  //now that we have checked all of the buttons and set the color mode accordingly, we can turn the lights on to the color mode.
  if (color_mode == 0){
    digitalWrite(white, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(multi, LOW);
  }
  else if (color_mode == 1){
    digitalWrite(white, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(multi, LOW);
  }
  else if (color_mode == 2){
    digitalWrite(white, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(multi, LOW);
  }
  else if (color_mode == 3){
    digitalWrite(white, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(multi, LOW);
  }
  else if (color_mode == 4){
    digitalWrite(white, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(multi, LOW);
  }
  else if (color_mode == 5){
    digitalWrite(white, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(multi, HIGH);
  }


}
