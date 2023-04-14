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

/* Drive Speed */
#define IDEAL_SPEED_LEFT    150
#define IDEAL_SPEED_RIGHT   220
#define FULL_SPEED_LEFT     255
#define FULL_SPEED_RIGHT    255

/* Drive Distance */

//***********************************************************************************
// enums
//***********************************************************************************
typedef enum
{
    cwTurn90Delay = 900,
    cwTurn180Delay = 1600,
    cwTurn270Delay = 2200,
    cwTurn360Delay = 3025
}CW_spin_delay_Typedef;


typedef enum
{
    ccwTurn90Delay = 975,
    ccwTurn180Delay = 2120,
    ccwTurn270Delay = 2900,
    ccwTurn360Delay = 3650   
}CCW_spin_delay_Typedef;

//***********************************************************************************
// structs
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
/* Basic Driving Functions */
void stop(uint32_t waitTime);
void spinCCW(CCW_spin_delay_Typedef degrees);
void spinCW(CW_spin_delay_Typedef degrees);
void drive_backward(uint32_t driveTime);
void drive_forward(uint32_t driveTime);

/* Sample Driving Courses */
void outAndBack(void);
void square(void);


#endif