/******************************************************************************/
/**
 * file         Button.c
 *
 * brief        C file for _TempBasic
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

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/
#include <Dave.h>
#include "Button.h"


/******************************************************************************/
/* PRIVATE DEFINITIONS AND MACROS (scope: file)                               */
/******************************************************************************/


/******************************************************************************/
/* PRIVATE TYPEDEFS AND STRUCTURES (scope: file)                              */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/
int Number;

/******************************************************************************/
/* PRIVATE VARIABLES                                                          */
/******************************************************************************/
//static int32_t MyPrivate;


/******************************************************************************/
/* PRIVATE Function Prototype (scope: file)                                   */
/******************************************************************************/


/******************************************************************************/
/* PRIVATE Function Implementation (scope: file)                              */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC Function Implementation                                             */
/******************************************************************************/
/*
void Sche_InitTimer(const sScheTable_t * pParam,
                               eScheStatus_t * pState,
                               int32_t *pi32InBuf)
{
   
}
*/

void InitButton(void){
	DIGITAL_IO_Init(&dhDI_INC);
	DIGITAL_IO_Init(&dhDI_DEC);
	Number = 0;
}

void CheckButton(void){
	uint32_t pin1_status;
	uint32_t pin2_status;
	pin1_status = DIGITAL_IO_GetInput(&dhDI_INC);
	pin2_status = DIGITAL_IO_GetInput(&dhDI_DEC);

	if((pin1_status == 0) && (pin2_status == 1)){
		Number++;
		if(Number > 9){
			Number = 0;
		}
	}

	if((pin1_status == 1) && (pin2_status == 0)){
		Number--;
		if(Number < 0){
			Number = 9;
		}
	}
}

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/


