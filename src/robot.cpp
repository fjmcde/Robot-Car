//***********************************************************************************
// included header file
//***********************************************************************************
#include "robot.h"


//***********************************************************************************
// static/private data
//***********************************************************************************


//***********************************************************************************
// static/private functions
//***********************************************************************************
/***************************************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 ******************************************************************************/
void stop(uint32_t waitTime)
{
    digitalWrite(DPIN_LEFT_BACKWARD, LOW);
    digitalWrite(DPIN_LEFT_FORWARD, LOW);
    digitalWrite(DPIN_RIGHT_BACKWARD, LOW);
    digitalWrite(DPIN_RIGHT_FORWARD, LOW);
    delay(waitTime);
}


/***************************************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 ******************************************************************************/
void turnCCW(CCW_spin_delay_Typedef degrees)
{
    digitalWrite(DPIN_LEFT_BACKWARD, LOW);
    digitalWrite(DPIN_LEFT_FORWARD, HIGH);
    digitalWrite(DPIN_RIGHT_BACKWARD, HIGH);
    digitalWrite(DPIN_RIGHT_FORWARD, LOW);
    delay(degrees);
}


/***************************************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 ******************************************************************************/
void turnCW(CW_spin_delay_Typedef degrees)
{
    digitalWrite(DPIN_LEFT_BACKWARD, HIGH);
    digitalWrite(DPIN_LEFT_FORWARD, LOW);
    digitalWrite(DPIN_RIGHT_BACKWARD, LOW);
    digitalWrite(DPIN_RIGHT_FORWARD, HIGH);
    delay(degrees);
}


/***************************************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 ******************************************************************************/
void drive_backward(uint32_t driveTime)
{
    digitalWrite(DPIN_LEFT_FORWARD, LOW);
    digitalWrite(DPIN_RIGHT_FORWARD, LOW);
    digitalWrite(DPIN_LEFT_BACKWARD, HIGH);
    digitalWrite(DPIN_RIGHT_BACKWARD, HIGH);
    delay(driveTime);
}


/***************************************************************************//**
 * @brief
 *   
 *
 * @details
 *   
 ******************************************************************************/
void drive_forward(uint32_t driveTime)
{
    digitalWrite(DPIN_RIGHT_FORWARD, HIGH);
    delay(250);
    digitalWrite(DPIN_LEFT_FORWARD, HIGH);
    digitalWrite(DPIN_LEFT_BACKWARD, LOW);
    digitalWrite(DPIN_RIGHT_BACKWARD, LOW);
    delay(driveTime);
}