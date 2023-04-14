#include <Arduino.h>
#include "robot.h"

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
}

void loop() {
	do{}while(digitalRead(DPIN_ON_OFF));
	delay(1000);

	square();
	stop(500);
}
