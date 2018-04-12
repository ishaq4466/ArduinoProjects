byte pirSensor=6;
byte state=LOW;
byte relayPin=7;  //For handling bulb
byte led=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pirSensor,INPUT);  
  pinMode(relayPin,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  
state=digitalRead(pirSensor);    //reading the state of pirSensor

if(state==HIGH)
   {
   digitalWrite(relayPin,0);   // Turns ON Relay and bulb goes on
   digitalWrite(led,1);   // arduino led also glow
   
   Serial.println("Motion detected\nGetting Light ON");
   delay(5000);                                      // Wait 5 seconds
   }
   else{
   digitalWrite(relayPin,1);          // Turns Relay Off
   digitalWrite(led,0);   // arduino led also glow
   Serial.println("Motion not detected\nLight OFF\n");
   }
}
