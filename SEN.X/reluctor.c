/* 
 * File:   reluctor.c
 * Author: ruben
 *
 * Created on September 17, 2021, 6:52 PM
 */

#include "reluctor.h"

//Declaracion de variables globales
unsigned char ucCountFreq;
unsigned char ucCountPos;
unsigned char ucCountVueltaRueda;
unsigned int uiMeterPerSecond;
unsigned int uiKmeterPerHour;
unsigned char ucKPHData1;
unsigned char ucKPHData2;
unsigned char ucReluctorState;

//FUNCIONES
void ReluctorFreqCount(void)
{
    ucCountFreq++;
}

void ReluctorFreqRead(void) //se ejecuta cada 100ms con TMR0
{
    uiMeterPerSecond = ucCountFreq*(wheel_perimeter/wheel_tetons);
    uiKmeterPerHour = uiMeterPerSecond * 36/10;
    
    if ( uiKmeterPerHour >= VELOCIDADMAXRELUCTOR ) //150k/h
    {
        ucReluctorState = VELOCITYOUTOFRANGE; //no enviar mensaje CAN
    }
    else
    {
        ucReluctorState = VELOCITYOK; //enviar mensaje CAN
        ucKPHData1 = (( uiKmeterPerHour / 100 ) & 0x00FF);
        ucKPHData2 = (( uiKmeterPerHour - ( 1000 * ucKPHData1 )) & 0x00FF);
    }   
    
    ucCountFreq = 0;
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
    return (( ucCountVueltaRueda * 360 ) + ( ucCountPos*360 / wheel_tetons));
}