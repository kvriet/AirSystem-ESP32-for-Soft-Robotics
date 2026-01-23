// In the previous examples we worked with named objects for the pump and valve. 
// However, you can also directly address these objects within they object array. 
// This can be useful if you want to loop through the objects. 
// The code below shows you how to access pumps and valves through motors[i].

#include <AirSystem-ESP.h>

int motorPercentage = 0;

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  for (int i = 0; i < 4; i++) {
    // Turn off all components
    motors[i].off();
  }
}

void loop() {
  motors[0].set(motorPercentage); // pump A
  motors[1].set(motorPercentage); // valve A

  motorPercentage++; // Add 1 to the motorPercentage variable

  if (motorPercentage > 100){
    motorPercentage = 0; // If motorPercentage becomes larger than 100, make it 0 again
  }

  delay(100);
}
