/**#######################**\
*
*  WATERING SYSTEM
*  V 0.1
*
*/
#include <LiquidCrystal.h> // Library for the LCD display.

/*Variable declaration*/
int loadCell = A0;	    // AI-pin for reading the loadCell
int sensorRead1 = A1;	//
int sensorRead2 = A2;	//
int sensorRead3 = A3;	//  AI-pins for reading the humidity sensors
int sensorRead4 = A4;   //

int relayPin1 = 6;	//
int relayPin2 = 7;	//
int relayPin3 = 8;	//  6-9: DO-Pins for starting the pumps.
int relayPin4 = 9;	//
int sensorStart = 10;	//DO-Pin for starting the humidity sensors
int sensorState;  // SensorState: variables for saving humidity readings.
int loadcellValue;
int loadcellAverage;
int Hours;
int Minutes;
int dryLimit = 400;	//limit for soil moisture
int sensorID;

// initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*Setup*/
void setup()
{
	pinMode(relayPin1, OUTPUT);	//Set relay as output
	pinMode(relayPin2, OUTPUT);	//Set relay as output
	pinMode(relayPin3, OUTPUT);	//Set relay as output
	//pinMode(relayPin4, OUTPUT);	//Set relay as output
	pinMode(sensorRead1, INPUT);  //Set sensorRead as input
	pinMode(sensorRead2, INPUT);  //Set sensorRead as input
	pinMode(sensorRead3, INPUT);  //Set sensorRead as input
	//pinMode(sensorRead4, INPUT);  //Set sensorRead as input
	pinMode(sensorStart, OUTPUT);  //Set sensorStart as input
	pinMode(loadCell, INPUT);
	Serial.begin(9600);			//for debugging
	// set up the LCD's number of columns and rows: 
	lcd.begin(16, 2);
	lcd.clear();
}

/*Loop*/

void loop()
{
	/*Update the display*/

	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Humidity:");
	lcd.setCursor(0, 1);
	lcd.print("Water:");
	for (int n = 1; n < 6; n++)
	{
		loadcellValue = analogRead(loadCell);
		loadcellAverage += loadcellValue;
		Serial.print("load cell measurment: ");
		Serial.print(n);
		Serial.print(" ");
		Serial.println(loadcellValue);
		delay(100);
	}
	Serial.print("load cell average: ");
	loadcellAverage = loadcellAverage / 5;
	Serial.println(loadcellAverage);
	lcd.setCursor(7, 1);
	lcd.print(loadcellValue);
	Serial.println(loadcellValue);

	/*Check water level and read humidity sensors*/

	if (loadcellAverage >= 210)  //Don't start waterpump with too little water in tank
	{
		readSensor(sensorStart, sensorRead1, sensorState, relayPin1, 1);
		//delay(10000);
		Serial.print('\n');
		readSensor(sensorStart, sensorRead2, sensorState, relayPin2, 2);
		//delay(10000);
		Serial.print('\n');
		readSensor(sensorStart, sensorRead3, sensorState, relayPin3, 3);
		//delay(10000);
		Serial.print('\n');
		//readSensor(sensorStart, sensorRead4, sensorState, relayPin4);
		Serial.print('\n');
	}
	else
	{
		Serial.println("Fill Watertank");
		Serial.println(loadcellAverage);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Fill Watertank");
		lcd.setCursor(0, 1);
		lcd.print(loadcellAverage);
		shortDelay;
	}

	/* Time delay */

	//shortDelay();
	hourDelay(1);
	//delayMinutes(20);
}


/**Function for reading sensor and checking the humidity, start pump if dry**/
int readSensor(int sensorStart, int sensorRead, int sensorState, int relayPin, int sensorID)
{
	digitalWrite(sensorStart, HIGH);
	delay(1000);
	sensorState = analogRead(sensorRead);
	delay(1000);
	digitalWrite(sensorStart, LOW);
	lcd.setCursor(9, 0);
	lcd.print(sensorID);
	lcd.setCursor(11, 0);
	lcd.println(sensorState);
	Serial.println(sensorState);
	shortDelay();
	if (sensorState >= dryLimit)
	{
		Serial.print(sensorState);
		Serial.print(" Low humidity ");
		digitalWrite(relayPin, HIGH);
		delay(1000);
		digitalWrite(relayPin, LOW);
	}
	else
	{
		Serial.print(" High humidity ");
		digitalWrite(relayPin, LOW);
	}
	return sensorState;
}

/**Time delay function, a couple of hours between each reading is good enough for most plants*/
void hourDelay(int Hours)
{
	for (int n = 0; n < Hours; n++)  //Time delay loop (For longer time periods)
	{
		delay(3600000); // 1 hour in milliseconds

	}
}
void shortDelay()	//For debugging
{
	delay(10000); //10 seconds in milliseconds
}
void delayMinutes(int Minutes)
{
	for (int n = 0; n < Minutes; n++)
	{
		delay(60000); //1 minute in milliseconds
	}
}
