/* 
 * File:   parameters.h
 * Author: ruben
 *
 * Created on Octubre 30, 2021, 7:44 PM
 */

#include "parameters.h"

// VARIABLES. Set which wheel is being programmed.
unsigned char ucWheelID;
unsigned long ulTyrePerimeter;
unsigned long ulWheelTeeth;



//PARAMETRIZACION A TOCAR
void PARAMETERSInit(void)
{
    ucWheelID = WHEEL_FR;
    ulTyrePerimeter = 167;
    ulWheelTeeth = 16;
}
