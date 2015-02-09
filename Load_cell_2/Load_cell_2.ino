int loadCell = A0;
int delayTime = 1000;
int loadcellValue;
void setup()
{
pinMode(loadCell,INPUT);
Serial.begin(9600);
}
void loop()
{
  loadcellValue = analogRead(loadCell);
  Serial.println(loadcellValue);
  delay(delayTime);
}
