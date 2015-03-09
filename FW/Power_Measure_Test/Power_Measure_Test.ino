/*
  
  MCP4801 Initial Testing

*/  


// inslude the SPI library:
#include <SPI.h>


// set pin 10 as the slave select for the digital pot:
const int V_ADJ_MON = 0;

void setup() {
  // set the slaveSelectPin as an output:
  // initialize SPI:
  Serial.begin(9600);
  
  //change clock speed
  
}

void loop() {

  int power = 0; 
  power = analogRead(V_ADJ_MON);
  delay(500);
  Serial.print("Power Level = ");
  Serial.println(power);
  Serial.println("");

  // wait a second at the top:
  
  // change the resistance on this channel from max to min:

}
