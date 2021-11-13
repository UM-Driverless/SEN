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
unsigned int uiCountVueltaRueda;
unsigned char ucCountVueltaRueda1;
unsigned char ucCountVueltaRueda2;


unsigned char ui_cm_in_period; // cm calculated in a count cycle
// speed in cm/s or m/s*10^-2, calculated after dividing by counting period (TMR0_period_ms)
unsigned int ui_MeterPerSecond_E_2;
unsigned int uiKPH_E_2;
unsigned char ucKPHData1;
unsigned char ucKPHData2;
unsigned char ucReluctorState;

//FUNCIONES
void ReluctorCountTeeth(void) // se ejecuta cada INT0
{
    ucCountTeeth++;
}

void ReluctorFreqRead(void) //se ejecuta cada 100ms con TMR1
{
    /*EJEMPLO DE CALCULO PARA ucCountTeeth = 1
     * ui_cm_in_period = 1 teton * (167cm/rueda*16teton/rueda) * base calculo (100) = 1043
     * ui_MeterPerSecond_E_2 = 1043 (10,43cm/s) * (1/100ms freq muestreo) * (1m/100cm) * (1000ms/1s) = 104,3 (1,043m/s)
     * uiKPH_E_2 = ui_MeterPerSecond_E_2 * (3600s/1h) * (1km/1000m) = 375,48 (3,75km/h)
     */
    ui_cm_in_period = 100;
    //ui_cm_in_period = ucCountTeeth*(ucTyrePerimeter/ucWheelTeeth)*REL_base_calculo;
    ui_MeterPerSecond_E_2 = ui_cm_in_period * (10 / TMR1_period_ms);
    uiKPH_E_2 = ui_MeterPerSecond_E_2 * 36/10;
    
    if ( uiKPH_E_2 >= VELOCIDADMAXRELUCTOR ) //150k/h
    {
        ucReluctorState = VELOCITYOUTOFRANGE; //no enviar mensaje CAN
    }
    else
    {
        ucReluctorState = VELOCITYOK; //enviar mensaje CAN
        ucKPHData1 = (( uiKPH_E_2 / REL_base_calculo ) & 0x00FF);
        ucKPHData2 = (( uiKPH_E_2 - ( REL_base_calculo * ucKPHData1 )) & 0x00FF);
    }
    
    ucCountTeeth = 0;
}

void ReluctorPosCount(void)
{
    ucCountPos++;
    if(ucCountPos >= ucWheelTeeth){
        ucCountPos = 0;
        uiCountVueltaRueda++;
        ucCountVueltaRueda1 = uiCountVueltaRueda & 0x00FF;
        ucCountVueltaRueda2 = ( uiCountVueltaRueda >> 0x08 ) & 0x00FF;
    }
}

unsigned int ReluctorPosRead(void) //no se usa
{
    return (( uiCountVueltaRueda * 360 ) + ( ucCountPos*360 / ucWheelTeeth));
}