/*
  
  MCP4801 Initial Testing

*/  


// inslude the SPI library:
#include <SPI.h>


// set pin 10 as the slave select for the digital pot:
const int DAC_CS_N = 7;
const int LDAC_N = 3;
const int SHDN_N = 2;
const int FAN_PWM = 10;

void setup() {
  // set the slaveSelectPin as an output:
  pinMode (DAC_CS_N, OUTPUT);
  pinMode (LDAC_N, OUTPUT);
  pinMode (SHDN_N, OUTPUT);
  // initialize SPI:
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  SPI.setDataMode(SPI_MODE0);
  SPI.begin(); 
  Serial.begin(9600);
  
  //change clock speed
  
}

void loop() {

  digitalWrite(SHDN_N,HIGH);
  
  
  for (int level = 0; level < 64; level++) {
    MCP4801Write(level);
    delay(5000);
  }
  // wait a second at the top:
  delay(10000);
  // change the resistance on this channel from max to min:

}

void MCP4801Write(int value) {
  int wr_enable = 0;
  int gain = 1;
  int shdn = 1;
  int command = 0;
  int MSB = 0;
  int LSB = 0;
  
  Serial.print("Value: ");
  Serial.println(value);
  
  long voltage = 0;
  voltage = 2.048 * (value/256);
  Serial.print("Voltage = ");
  Serial.println(voltage);
  
  
  command = (wr_enable << 15) | (gain << 13) | (shdn << 12) |  (value << 4);

  Serial.print("Command: ");
  Serial.println(command,BIN);

  MSB = ( (command & 0xFF00) >> 8);
  
  Serial.print("MSB: ");
  Serial.println(MSB,BIN);
  
  LSB = ( (command & 0x00FF) );
  
  Serial.print("LSB: ");
  Serial.println(LSB,BIN);
  
  Serial.println("");

  // take the SS pin low to select the chip:
  digitalWrite(DAC_CS_N,LOW);
  //  send in the address and value via SPI:

  SPI.transfer(MSB);
  SPI.transfer(LSB);
  
  // take the SS pin high to de-select the chip:
  digitalWrite(DAC_CS_N,HIGH); 
}
