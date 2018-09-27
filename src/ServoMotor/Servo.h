/******************************************************************************/
/**
 * file         Servo.h
 *
 * brief        Header file for Servo
 *
 * version      1.00
 * date         Feb/23/2018
 * warning
 * note
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2018-09-23   1.00             - Creation Release
 *
 */
/******************************************************************************/

#ifndef SERVO_H
#define SERVO_H

/******************************************************************************/
/* Include                                                                    */
/******************************************************************************/
#include <Dave.h>

/******************************************************************************/
/* PUBLIC DEFINITIONS AND MACROS                                              */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC TYPEDEFS AND STRUCTURES                                             */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/
extern float my_angle;
extern uint32_t my_duty;

/******************************************************************************/
/* PUBLIC FUNCTIONS                                                           */
/******************************************************************************/
void SetServoAngle(float angle);
/***************************************************************************/
/**
brief      Initialization of the timer for scheduler
param[in]  pParam   Pointer to the parameters structure.
param[out] pState   Pointer to the state structure.
param[in,out] pi32InBuf Pointer to a buffer for storing input signal
return     void.

void Sche_InitTimer(const sScheTable_t * pParam,
                               eScheStatus_t * pState,
                               int32_t *pi32InBuf);
 */


#endif

/******************************************************************************/
/*                            EOF                                             */
/******************************************************************************/