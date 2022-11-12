/*
*/


// Put the pins used in an array
// For difispark Atmel Tiny 85 this works for P0 P1 and P4
const int numleds = 7 ;
int pin[]= {0,1,4,2,3,5,6 };

void setup() {
  // set pins as outputs:
  for (int thisPin = 0; thisPin < numleds; thisPin++) {
      pinMode(pin[thisPin], OUTPUT);
  }

}

void loop() {
  const int SHIFT=6;

  //  max val of 0x4000-1 (16384) will run to 100% duty cycle.
  //  setting maxval to lower will never max out.
  const int maxval = 12000;
  
  int   brightness[4];
  // give all colours different periods, 
  int   delta[] = {2,7,3,5,11,13,17};

  brightness[0] = 0;
  brightness[1] = 0;  
  brightness[2] = 0;
  brightness[3] = 0;

  while (1){
    // update brighness
    for (int led = 0; led<numleds; led++) {
        brightness[led] = brightness[led] + delta[led];
        if (brightness[led] > maxval){
           // +- are equaly bright only fade direction differs
           brightness[led] = - maxval;
        }
        // shift out and ignore LSB
        analogWrite(pin[led], abs(brightness[led])>>SHIFT);
    }
    delay(2);
  }
}
