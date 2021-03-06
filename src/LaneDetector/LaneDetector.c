/******************************************************************************/
/**
 * file         LaneDetector.c
 *
 * brief        C file for LaneDetector
 *
 * version      1.00
 * date         Aug/22/2017
 * warning
 * note
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2017-08-22   1.00     ARCLab  - Creation Release
 *
 */
/******************************************************************************/

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/
#include "LaneDetector.h"

/******************************************************************************/
/* PRIVATE DEFINITIONS AND MACROS (scope: file)                               */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE TYPEDEFS AND STRUCTURES (scope: file)                              */
/******************************************************************************/

/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE VARIABLES                                                          */
/******************************************************************************/
uint32_t LeftSensor;
uint32_t RightSensor;
uint32_t CenterSensor;

float fltLeftVol;
float fltCenterVol;
float fltRightVol;

LANE_TYPE_t eLaneType;
int32_t i32LaneOffset;

/******************************************************************************/
/* PRIVATE Function Prototype (scope: file)                                   */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE Function Implementation (scope: file)                              */
/******************************************************************************/

/******************************************************************************/
/* PUBLIC Function Implementation                                             */
/******************************************************************************/
void Sense_LaneDetector(void)
{

	uint32_t sensor_state;

	uint16_t left_adc_result;
	uint16_t center_adc_result;
	uint16_t right_adc_result;

	LeftSensor = DIGITAL_IO_GetInput(&dhDI_LANE_L);
	CenterSensor = DIGITAL_IO_GetInput(&dhDI_LANE_C);
	RightSensor = DIGITAL_IO_GetInput(&dhDI_LANE_R);

	sensor_state = 0;
	sensor_state = sensor_state | (LeftSensor << 2);
	sensor_state = sensor_state | (CenterSensor << 1);
	sensor_state = sensor_state | (RightSensor);

	switch (sensor_state)
	{
		case 0:
			eLaneType = NO_LANE;
			break;

		case 1:
			eLaneType = VALID;
			i32LaneOffset = 20;
			break;

		case 2:
			eLaneType = VALID;
			i32LaneOffset = 0;
			break;

		case 3:
			eLaneType = VALID;
			i32LaneOffset = 10;
			break;

		case 4:
			eLaneType = VALID;
			i32LaneOffset = -20;
			break;

		case 5:
			eLaneType = INVALID;
			break;

		case 6:
			eLaneType = VALID;
			i32LaneOffset = -10;
			break;

		case 7:
			eLaneType = ALL;
			break;

	}

	left_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChLeft_handle);
	center_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChCenter_handle);
	right_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChRight_handle);

	fltLeftVol = (float)((left_adc_result/4095.0)*3.3);
	fltCenterVol = (float)((center_adc_result/4095.0)*3.3);
	fltRightVol = (float)((right_adc_result/4095.0)*3.3);

}

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/
