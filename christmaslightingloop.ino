/*
*/


// Put the pins used in an array
const int numleds = 4 ;
int pin[]= {LED_BUILTIN,9,10,11};

void setup() {
  // set pins as outputs:
  for (int thisPin = 0; thisPin < numleds; thisPin++) {
      pinMode(pin[thisPin], OUTPUT);
  }

}

void loop() {
  const int SHIFT=6;

//  const int maxval = (256<<SHIFT) -1;
//  max val of 0x4000-1 (16384) will run to 100% duty cycle.
//  setting maxval to lower will never max out.
  const int maxval = 12000;
  
  int   brightness[4];
  // give all colours different periods, 
  int   delta[] = {2,7,3,5};

  brightness[0] = 0;
  brightness[1] = 0;  
  brightness[2] = 0;
  brightness[4] = 0;

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
