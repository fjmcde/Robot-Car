#include <Arduino.h>
#include "robot.h"

void setup() {
	// setup button
	pinMode(DPIN_ON_OFF, INPUT_PULLUP);

	// setup pwm
	pinMode(DPIN_RIGHT_PWM, OUTPUT);
	pinMode(DPIN_LEFT_PWM, OUTPUT);
	analogWrite(DPIN_RIGHT_PWM, 5*51);
	analogWrite(DPIN_LEFT_PWM, 4*51);  // compensate for hardware non-linearity

	//setup direction output
	pinMode(DPIN_RIGHT_FORWARD, OUTPUT);
	pinMode(DPIN_LEFT_FORWARD, OUTPUT);
	pinMode(DPIN_RIGHT_BACKWARD, OUTPUT);
	pinMode(DPIN_LEFT_BACKWARD, OUTPUT);
}

void loop() {
	do{}while(digitalRead(DPIN_ON_OFF));
	delay(1000);

	drive_forward(3000);
	stop(500);
}
