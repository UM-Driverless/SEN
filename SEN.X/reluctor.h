/* 
 * File:   reluctor.h
 * Author: ruben
 *
 * Created on September 17, 2021, 6:52 PM
 */

#ifndef RELUCTOR_H
#define	RELUCTOR_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//Declaracion de constantes
//ESTADOS RELUCTOR
#define VELOCITYOK 0x00
#define VELOCITYOUTOFRANGE 0x01
#define VELOCITYSENT 0x02
    
//VELOCIDADES k/h
#define VELOCIDADMAXRELUCTOR 15000

//Declaracion de variables globales
extern unsigned long ulCountTeeth;
extern unsigned char ucCountPos;
extern unsigned int uiCountVueltaRueda;
extern unsigned char ucCountVueltaRueda1;
extern unsigned char ucCountVueltaRueda2;
extern unsigned char ucKPHData1;
extern unsigned char ucKPHData2;
extern unsigned char ucReluctorState;

extern unsigned long ui_cm_in_period; // cm calculated in a count cycle
// speed in cm/s or m/s*10^-2, calculated after dividing by counting period (TMR0_period_ms)
extern unsigned long ui_MeterPerSecond_E_2;
extern unsigned long uiKPH_E_2;

//Declaracion de funciones
void ReluctorFreqRead(void);
void ReluctorCountTeeth(void);
unsigned int ReluctorPosRead(void);
void ReluctorPosCount(void);


#ifdef	__cplusplus
}
#endif

#endif	/* RELUCTOR_H */

