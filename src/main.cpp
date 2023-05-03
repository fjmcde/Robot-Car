#include "main.h"

/* Static variables */
static LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);
static Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();
static sensors_event_t humidity;
static sensors_event_t temp;

void setup() 
{
	// initialize LCD
	lcd.init();
	lcd.backlight();

	// set baud rate
	Serial.begin(115200);

	// print a test message
	Serial.println("SHTC3 test");

	// assert statement
	if(!shtc3.begin()) 
	{
		// error message
		Serial.println("Couldn't find SHTC3");
		
		// infinite loop
		while(1)
		{
			delay(1);
		}

		// error resolution
		Serial.println("Found SHTC3 sensor");
	}
}

void loop() 
{
	// get temperature and humidity events  
	shtc3.getEvent(&humidity, &temp);

	// convert temperature from celcius to fahrenheit
	float temp_f = (temp.temperature * 1.8) + 32;

	// 500ms delay
	delay(500);

	// print temperature and humidity
	lcd.setCursor(0, 0);
	lcd.print("Temp: "); 
	lcd.print(temp_f);
	lcd.print(" F");
	lcd.setCursor(0, 1);
	lcd.print("Hum: "); 
	lcd.print(humidity.relative_humidity); 
	lcd.print(" %rH");
}