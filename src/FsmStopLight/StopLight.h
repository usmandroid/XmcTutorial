/******************************************************************************/
/**
 * file         StopLight.h
 *
 * brief        Header file for StopLight
 *
 * version      1.00
 * date         Feb/18/2010
 * warning
 * note
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2010-02-18   1.00             - Creation Release
 *
 */
/******************************************************************************/

#ifndef STOPLIGHT_H
#define STOPLIGHT_H

/******************************************************************************/
/* Include                                                                    */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC DEFINITIONS AND MACROS                                              */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC TYPEDEFS AND STRUCTURES                                             */
/******************************************************************************/
typedef enum {
	STOPLIGHT_INIT = 0,
	STOPLIGHT_RED = 1,
	STOPLIGHT_GREEN = 2,
	STOPLIGHT_YELLOW = 3
} StopLightState_t;

typedef enum {
	LIGHT_OFF_ALL = 0,
	LIGHT_RED_ONLY = 1,
	LIGHT_GREEN_ONLY = 2,
	LIGHT_YELLOW_ONLY = 3
} Light_t;


/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/
extern Light_t Light;
extern StopLightState_t StopLightState;


/******************************************************************************/
/* PUBLIC FUNCTIONS                                                           */
/******************************************************************************/

void StopLight(void);

#endif

/******************************************************************************/
/*                            EOF                                             */
/******************************************************************************/
