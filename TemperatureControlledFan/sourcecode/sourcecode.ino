
#include "DHT.h"           // Including DHT22 library

#define DHTPIN 6      // Declaring pin 6 for communicating to DHT22 sensor
#define DHTTYPE DHT22 // Declaring the type of DHT sensor we are using (DHT22 or DHT11)

DHT dht(DHTPIN, DHTTYPE);          // Declaring DHT connection and type

int Motor_Pin1 = 4;  // pin 2 on L293D
int Motor_Pin2 = 3;  // pin 7 on L293D
int Enable = 5;      // pin 1 on L293D (it is conected to PWM pin of arduino.)

void setup() {
  pinMode(Motor_Pin1, OUTPUT);  //controlling pins for motor rotation direction
  pinMode(Motor_Pin2, OUTPUT);	//motor controlling pin
  pinMode(Enable, OUTPUT);
  Serial.begin(9600);
  dht.begin();     // Initializes DHT sensor
}

//controlling the motor direction(clockwise,anticlockwise)
void direc(int x,int y)
{ 
  digitalWrite(Motor_Pin1, x);  
  digitalWrite(Motor_Pin2, y); 
  
}


void loop() {

  float temp = dht.readTemperature(); // Reading the temperature in Celsius

  if (isnan(temp)) {                  // Validating received data
	Serial.print("ERROR!!!Something is Went Wrong!!!!");  
  delay(1000);
    return;
  }
  
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


