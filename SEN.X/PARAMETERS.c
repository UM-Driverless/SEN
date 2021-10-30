/* 
 * File:   parameters.h
 * Author: ruben
 *
 * Created on Octubre 30, 2021, 7:44 PM
 */

#include "parameters.h"

// VARIABLES. Set which wheel is being programmed.
unsigned char ucWheelID;
unsigned char ucTyrePerimeter;
unsigned char ucWheelTeeth;



//PARAMETRIZACION A TOCAR
void PARAMETERSInit(void)
{
    ucWheelID = WHEEL_FR;
    ucTyrePerimeter = 167;
    ucWheelTeeth = 32;
}
