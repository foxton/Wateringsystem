int relayPin1 = 6;	//
int relayPin2 = 7;	//
int relayPin3 = 8;	//  8-11: DO-Pins for starting the pumps.
//int relayPin4 = 9;	//
int delayTime = 1000;
void setup()
{
pinMode(relayPin1,OUTPUT);	//Set relay as output
pinMode(relayPin2,OUTPUT);	//Set relay as output
pinMode(relayPin3,OUTPUT);	//Set relay as output
//pinMode(relayPin4,OUTPUT);	//Set relay as output
Serial.begin(9600);
delay(5000);
}

void loop()
{
  digitalWrite(relayPin1,HIGH);
 Serial.println("Relay 1 ON");
 delay(delayTime);
  digitalWrite(relayPin1,LOW);
  delay(delayTime);
  digitalWrite(relayPin2,HIGH);
    Serial.println("Relay 2 ON");
  delay(delayTime);
  digitalWrite(relayPin2,LOW);
    delay(delayTime);
  digitalWrite(relayPin3,HIGH);
    Serial.println("Relay 3 ON");
  delay(delayTime);
  digitalWrite(relayPin3,LOW);
  delay(delayTime);
//  digitalWrite(relayPin4,HIGH);
//    Serial.println("Relay 4 ON");
//  delay(delayTime);
//  digitalWrite(relayPin4,LOW);
}
