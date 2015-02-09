//Small test for checking the value of the soil humidity sensors
//Plant needs water when sensorValue >= 600.
//Plant is well-watered when sensorValue = 250-300

int sensor1 = A1;
int sensor2 = A2;
int sensor3 = A3;
int sensor4 = A4;
int sensorStart = 10;
int sensorValue;
int delayTime = 5000;
void setup()
{
pinMode(sensor1,INPUT);
pinMode(sensor2,INPUT);
pinMode(sensor3,INPUT);
pinMode(sensor4,INPUT);
pinMode(sensorStart,OUTPUT);
Serial.begin(9600);
}
void loop()
{
  digitalWrite(sensorStart,HIGH);
  delay(1000);
  sensorValue = analogRead(sensor1);
  Serial.print("Plant 1: ");
  Serial.println(sensorValue);
  sensorValue = analogRead(sensor2);
  Serial.print("Plant 2: ");
  Serial.println(sensorValue);
  Serial.print("Plant 3: ");
  sensorValue = analogRead(sensor3);
  Serial.println(sensorValue);
 // sensorValue = analogRead(sensor4);
  //Serial.print("Plant 4: ");
  //Serial.println(sensorValue);
  digitalWrite(sensorStart,LOW);
  delay(delayTime);
}
