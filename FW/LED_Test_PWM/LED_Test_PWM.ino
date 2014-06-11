/*
  
LED Driver Testing

*/  
const int LED_PWM = 9;

void setup() {
  // set the slaveSelectPin as an output:
  pinMode (LED_PWM, OUTPUT);
  // initialize SPI:
  Serial.begin(9600);
  
  //change clock speed
  
}

void loop() {

  analogWrite(LED_PWM, 255);
  Serial.println("LED ON");
  Serial.println("");
  delay(5000);
  analogWrite(LED_PWM, 0); 
  Serial.println("LED OFF");
  Serial.println("");  
  delay(5000);
  int pwm = 0;
  for (int pwmlevel = 1; pwmlevel < 5; pwmlevel++) {
  
    pwm=((pwmlevel * 64) - 1);
    analogWrite(LED_PWM, pwm);
    delay(5000);
    Serial.print("PWM Level = ");
    Serial.println(pwm);
    Serial.println("");
  }

}


