 /*
  
  MCP3901 Initial Testing

*/  


// inslude the SPI library:
#include <SPI.h>


// set pin 10 as the slave select for the digital pot:
const int ADC_CS_N = 8;
const int DAC_CS_N = 7;
const int ADC_RESET_N = 5;
const int ADC_DR_N = 4;

const int address_register_write = 0;
const int address_register_read = 1;



const int address_register_ch0_msb = (0x00 << 1);
const int address_register_ch0_mid = (0x01 << 1);
const int address_register_ch0_lsb = (0x02 << 1);
const int address_register_ch1_msb = (0x03 << 1);
const int address_register_ch1_mid = (0x04 << 1);
const int address_register_ch1_lsb = (0x05 << 1);
const int address_register_mod = (0x06 << 1);
const int address_register_phase = (0x07 << 1);
const int address_register_gain = (0x08 << 1);
const int address_register_statuscom = (0x09 << 1);
const int address_register_config1 = (0x0A << 1);
const int address_register_config2 = (0x0B << 1);





void setup() {
  // set the slaveSelectPin as an output:
  pinMode (ADC_CS_N, OUTPUT);
  pinMode (DAC_CS_N, OUTPUT);
  pinMode (ADC_RESET_N, OUTPUT);
  pinMode (ADC_DR_N, INPUT);
  // initialize SPI:
//  SPI.setClockDivider(SPI_CLOCK_DIV128);
  SPI.setDataMode(SPI_MODE0);
  SPI.begin(); 
  Serial.begin(9600);
  digitalWrite(ADC_CS_N,HIGH);
  digitalWrite(DAC_CS_N,HIGH);
  digitalWrite(ADC_RESET_N,HIGH);
  
}

void loop() {
  
  
   MCP3901_Data_Read();
   delay(2000);
 

}

void MCP3901_Config_Write(int writeval)
{
  int address = (address_register_config2 | address_register_write);
  digitalWrite(ADC_CS_N,LOW);

  SPI.transfer(address);  //address register
  SPI.transfer(writeval);  //config register

  Serial.print("Writing to address: ");
  Serial.println(address,BIN);
  Serial.println("");

  Serial.print("Writing to config data: ");
  Serial.println(writeval,BIN);
  Serial.println("");

  digitalWrite(ADC_CS_N,HIGH);  
}

int MCP3901_Config_Read()
{ 
  digitalWrite(ADC_CS_N,LOW);  
  
  int value1;
  int value2;
  int value3;
  int readaddress = (address_register_statuscom | address_register_read);
  
  
  
  SPI.transfer( readaddress );  //address registe
  value1 = SPI.transfer( 0xFF );  //Push dummy 1's and get byte return
  value2 = SPI.transfer( 0xFF );  //Push dummy 1's and get byte return
  value3 = SPI.transfer( 0xFF );  //Push dummy 1's and get byte return 

  Serial.print("Writing to address: ");
  Serial.println(readaddress,BIN);
  Serial.println("");
  
  Serial.print("Byte1: ");
  Serial.println(value1,BIN);
  Serial.println("");
  
  Serial.print("Byte2: ");
  Serial.println(value2,BIN);
  Serial.println("");  
  
  Serial.print("Byte3: ");
  Serial.println(value3,BIN);
  Serial.println("");
  
  digitalWrite(ADC_CS_N,HIGH); 

  return value1;  
  
 
}

int MCP3901_Data_Read()
{
  digitalWrite(ADC_CS_N,LOW);  
  
  int value1=0;
  int value2=0;
  int combinedvalue=0;
  int readaddress = (address_register_ch0_msb | address_register_read);
  int cal_value = 0;
  
  
  SPI.transfer( readaddress );  //address registe
  value1 = SPI.transfer( 0xFF );  //Push dummy 1's and get byte return
  value2 = SPI.transfer( 0xFF );  //Push dummy 1's and get byte return

  Serial.print("Writing to address: ");
  Serial.println(readaddress,BIN);
  Serial.println("");
  
  Serial.print("Byte1: ");
  Serial.println(value1,BIN);
  Serial.println("");
  
  Serial.print("Byte2: ");
  Serial.println(value2,BIN);
  Serial.println("");  
  
  
  combinedvalue = ( (value1 << 8) | (value2) );

  Serial.print("16 bit combined: ");
  Serial.println(combinedvalue,BIN);
  Serial.println("");  

  cal_value = ( combinedvalue / ( 2.37/65536) );

  Serial.print("Voltage measure at input: ");
  Serial.println(combinedvalue,DEC);
  Serial.println(""); 

  
  digitalWrite(ADC_CS_N,HIGH); 

  return value1;  
  
}

