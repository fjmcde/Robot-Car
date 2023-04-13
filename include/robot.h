#ifndef ROBOT_H
#define ROBOT_h


//***********************************************************************************
// include files
//***********************************************************************************
// system included files
#include <Arduino.h>


//***********************************************************************************
// defined macros
//***********************************************************************************
/* Digital Pin definitions */
#define DPIN_ON_OFF          6
#define DPIN_RIGHT_FORWARD   7
#define DPIN_RIGHT_BACKWARD  8
#define DPIN_RIGHT_PWM       9  
#define DPIN_LEFT_PWM        10
#define DPIN_LEFT_FORWARD    11
#define DPIN_LEFT_BACKWARD   12

/* Drive Distance */

//***********************************************************************************
// enums
//***********************************************************************************
typedef enum
{
    cwTurn90Delay = 725,
    cwTurn180Delay = 1500,
    cwTurn270Delay = 2200,
    cwTurn360Delay = 2850
}CW_spin_delay_Typedef;


typedef enum
{
    ccwTurn90Delay = 825,
    ccwTurn180Delay = 1625,
    ccwTurn270Delay = 2450,
    ccwTurn360Delay = 3250   
}CCW_spin_delay_Typedef;

//***********************************************************************************
// structs
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
void stop(uint32_t waitTime);
void turnCCW(CCW_spin_delay_Typedef degrees);
void turnCW(CW_spin_delay_Typedef degrees);
void drive_backward(uint32_t driveTime);
void drive_forward(uint32_t driveTime);

#endif