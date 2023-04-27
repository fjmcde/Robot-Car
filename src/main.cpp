#include <Arduino.h>
#include "robot.h"
#include "../lib/LiquidCrystal_I2C/LiquidCrystal_I2C.h"

// static LCD class instantiation
static LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
	// setup button
	pinMode(DPIN_ON_OFF, INPUT_PULLUP);

	// setup pwm
	pinMode(DPIN_RIGHT_PWM, OUTPUT);
	pinMode(DPIN_LEFT_PWM, OUTPUT);
	analogWrite(DPIN_RIGHT_PWM, IDEAL_SPEED_RIGHT);
	analogWrite(DPIN_LEFT_PWM, IDEAL_SPEED_LEFT);

	//setup direction output
	pinMode(DPIN_RIGHT_FORWARD, OUTPUT);
	pinMode(DPIN_LEFT_FORWARD, OUTPUT);
	pinMode(DPIN_RIGHT_BACKWARD, OUTPUT);
	pinMode(DPIN_LEFT_BACKWARD, OUTPUT);

	// initialize LCD
	lcd.init();
	lcd.backlight();
}

void loop() {
	// print message to LCD
	lcd.setCursor(3, 0);
  	lcd.print("I'M ALIVE!"); 
  	lcd.setCursor(0, 1);
  	lcd.print("LETS GOOOOOOOOO!");

	do{}while(digitalRead(DPIN_ON_OFF));
	delay(1000);



	outAndBack();;
	stop(500);	
}