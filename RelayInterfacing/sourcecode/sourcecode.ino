byte relayPin=7;
byte led=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
   digitalWrite(relayPin,0);   // Turns ON Relays 1
   digitalWrite(led,1);   // arduino led also glow
   
   Serial.println("Light ON");
   delay(2000);                                      // Wait 2 seconds

   digitalWrite(relayPin,1);          // Turns Relay Off for 5seconds
   digitalWrite(led,0);   // arduino led also glow

   Serial.println("Light OFF");
   delay(5000);
}
