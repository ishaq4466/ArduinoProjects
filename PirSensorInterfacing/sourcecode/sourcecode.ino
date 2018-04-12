byte sensorPin=2;   //arduino(2 pin)-->PIR(data pin)
byte state=LOW;    //variable for sensing the  pir state
byte led=13;      //led for output when motion is detected

void setup() {
  // put your setup code here, to run once:
pinMode(sensorPin,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
state=digitalRead(sensorPin);

if(state==HIGH)
{
  digitalWrite(led,HIGH);
  Serial.print("Motion detected\n");
}
else
{
  digitalWrite(led,LOW);
  Serial.print("Motion not detected\n");
}
delay(2000);
}
