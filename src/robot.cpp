#include "robot.h"


//*********************************************************
// static/private data
//*********************************************************


//*********************************************************
// static/private functions
//*********************************************************
/******************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 *********************************************************/
void stop(uint32_t waitTime)
{
    digitalWrite(DPIN_LEFT_BACKWARD, LOW);
    digitalWrite(DPIN_LEFT_FORWARD, LOW);
    digitalWrite(DPIN_RIGHT_BACKWARD, LOW);
    digitalWrite(DPIN_RIGHT_FORWARD, LOW);
    delay(waitTime);
}


/******************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 *********************************************************/
void spinCCW(CCW_spin_delay_Typedef degrees)
{
    analogWrite(DPIN_RIGHT_PWM, FULL_SPEED_RIGHT);
	analogWrite(DPIN_LEFT_PWM, FULL_SPEED_RIGHT);

    digitalWrite(DPIN_LEFT_BACKWARD, HIGH);
    digitalWrite(DPIN_LEFT_FORWARD, LOW);
    digitalWrite(DPIN_RIGHT_BACKWARD, LOW);
    digitalWrite(DPIN_RIGHT_FORWARD, HIGH);
    delay(degrees);

    analogWrite(DPIN_RIGHT_PWM, IDEAL_SPEED_RIGHT);
	analogWrite(DPIN_LEFT_PWM, IDEAL_SPEED_LEFT);
}


/******************************************************//**
 * @brief
 *   Spins the robot
 *
 * @details
 *   Function to spin the robot clockwise using delays
 * @param[in] delayTime
 *   Enumerated spin delay in order top spin the robot 
 *   90, 180, 270, or 360 degrees. 
 *   See CW_spin_delay_Typedef enumeration.
 *********************************************************/
void spinCW(CW_spin_delay_Typedef delayTime)
{
    // set the PWM of the left and right side to full speed
    analogWrite(DPIN_RIGHT_PWM, FULL_SPEED_RIGHT);
	analogWrite(DPIN_LEFT_PWM, FULL_SPEED_LEFT);

    //
    digitalWrite(DPIN_LEFT_BACKWARD, LOW);
    digitalWrite(DPIN_LEFT_FORWARD, HIGH);
    digitalWrite(DPIN_RIGHT_BACKWARD, HIGH);
    digitalWrite(DPIN_RIGHT_FORWARD, LOW);
    delay(delayTime);

    analogWrite(DPIN_RIGHT_PWM, IDEAL_SPEED_RIGHT);
	analogWrite(DPIN_LEFT_PWM, IDEAL_SPEED_LEFT);
}


/******************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 *********************************************************/
void drive_backward(uint32_t driveTime)
{
    digitalWrite(DPIN_LEFT_FORWARD, LOW);
    digitalWrite(DPIN_RIGHT_FORWARD, LOW);
    digitalWrite(DPIN_LEFT_BACKWARD, HIGH);
    digitalWrite(DPIN_RIGHT_BACKWARD, HIGH);
    delay(driveTime);
}


/******************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 *********************************************************/
void drive_forward(uint32_t driveTime)
{
    digitalWrite(DPIN_LEFT_BACKWARD, LOW);
    digitalWrite(DPIN_RIGHT_BACKWARD, LOW);
    digitalWrite(DPIN_RIGHT_FORWARD, HIGH);
    digitalWrite(DPIN_LEFT_FORWARD, HIGH);
    delay(driveTime);
}


/******************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 *********************************************************/
void outAndBack(void)
{
 	drive_forward(3000);
	stop(500);
	spinCW(cwTurn180Delay);
	stop(500);
	drive_forward(3000);
	stop(500);
	spinCCW(ccwTurn180Delay);
	stop(500);   
}


/******************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 *********************************************************/
void square(void)
{
    for(int i = 0; i < 4; i++)
    {
        drive_forward(3000);
        stop(500);
        spinCW(cwTurn90Delay);
        stop(500);
    }
}