
int Motor_Pin1 = 4;  // pin 2 on L293D
int Motor_Pin2 = 3;  // pin 7 on L293D
int Enable = 5;      // pin 1 on L293D (it is conected to PWM pin of arduino.)

int sensorPin = A0;  //Data pin of LM35 temoperature sensor
float temp, tempF;

void setup() {

Serial.begin(9600);
}
void loop() {
  //in degree Celsius
   temp = get_temperature(sensorPin);
//tempF = celsius_to_fahrenheit(tempC);
  
 Serial.print("Temp.: "); 
 Serial.println(temp);      // Writing the temperture to serial monitor
  
  if(temp <25 ) {                 // If the temperature less than 25
    analogWrite(Enable,77);        // 30% PWM duty cycle
    Serial.println("Cold Condition\n");      
    delay(100);
  }
  else if(temp>=25 & temp<30) {      // If the temperature is between 25 & 30
    analogWrite(Enable, 128);         // 50% of maximum duty cycle value (255). 
    Serial.println("Normal Room temperature ");
    delay(100);
  }
  else if(temp>=30 & temp<35) {      // If the temperature is between 30 & 35
    analogWrite(Enable, 192);        // 75% of maximum duty cycle value (255).
    Serial.println("Hot Condition ");
    delay(100);
  }
  else if(temp>=35) {                // If the temperature is above 35
    analogWrite(Enable, 255);        // 100% duty cycle
    Serial.println("\nExtremely Hotttt!!!");
    delay(100);
  }
  
direc(0,1); //controling motor direction

  delay(2000); // 2 seconds delay
}



float get_temperature(int pin) {
// We need to tell the function which pin the sensor is hooked up to. We're using
// the variable pin for that above
// Read the value on that pin
float temperature = analogRead(pin);
// Calculate the temperature based on the reading and send that value back
float voltage = temperature * 5.0;
voltage = voltage / 1024.0;
return ((voltage - 0.5) * 100);
}

float celsius_to_fahrenheit(int temp) {
return (temp * 9 / 5) + 32;
}

void direc(int x,int y)
{ 
  digitalWrite(Motor_Pin1, x);  
  digitalWrite(Motor_Pin2, y); 
  
}

