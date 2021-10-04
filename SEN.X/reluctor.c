/* 
 * File:   reluctor.c
 * Author: ruben
 *
 * Created on September 17, 2021, 6:52 PM
 */

#include "reluctor.h"
#include "parameters.h"

// Declaracion de variables globales
unsigned char ucCountTeeth; // Count teeth and reset every time
unsigned char ucCountPos;
unsigned char ucCountVueltaRueda;

unsigned char ui_cm_in_period; // cm calculated in a count cycle
// speed in cm/s or m/s*10^-2, calculated after dividing by counting period (TMR0_period_ms)
unsigned int ui_MeterPerSecond_E_2;
unsigned int uiKPH_E_2;
unsigned char ucKPHData1;
unsigned char ucKPHData2;
unsigned char ucReluctorState;

//FUNCIONES
void ReluctorCountTeeth(void) // se ejecuta cada 10ms con TMR0
{
    ucCountTeeth++;
}

void ReluctorFreqRead(void) //se ejecuta cada 100ms con TMR1
{
    ui_cm_in_period = ucCountTeeth*(tyre_perimeter_cm/wheel_teeth);
    ui_MeterPerSecond_E_2 = ui_cm_in_period * (1000 / TMR0_period_ms);
    uiKPH_E_2 = ui_MeterPerSecond_E_2 * 36/10;
    
    if ( uiKPH_E_2 >= VELOCIDADMAXRELUCTOR ) //150k/h
    {
        ucReluctorState = VELOCITYOUTOFRANGE; //no enviar mensaje CAN
    }
    else
    {
        ucReluctorState = VELOCITYOK; //enviar mensaje CAN
        ucKPHData1 = (( uiKPH_E_2 / 100 ) & 0x00FF);
        ucKPHData2 = (( uiKPH_E_2 - ( 1000 * ucKPHData1 )) & 0x00FF);
    }
    
    ucCountTeeth = 0;
}

void ReluctorPosCount(void)
{
    ucCountPos++;
    if(ucCountPos >= 32){
        ucCountPos = 0;
        ucCountVueltaRueda++;
    }
}

unsigned int ReluctorPosRead(void)
{
    return (( ucCountVueltaRueda * 360 ) + ( ucCountPos*360 / wheel_teeth));
}