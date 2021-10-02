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

#include "parameters.h"
    
//Declaracion de constantes 
//ESTADOS RELUCTOR
#define VELOCITYOK 0x00
#define VELOCITYOUTOFRANGE 0x01
    
//VELOCIDADES k/h
#define VELOCIDADMAXRELUCTOR 15000

//Declaracion de variables globales
extern unsigned char ucCountFreq;
extern unsigned char ucCountPos;
extern unsigned char ucCountVueltaRueda;
extern unsigned char ucKPHData1;
extern unsigned char ucKPHData2;

//Declaracion de funciones
void ReluctorFreqRead(void);
void ReluctorFreqCount(void);
unsigned int ReluctorPosRead(void);
void ReluctorPosCount(void);


#ifdef	__cplusplus
}
#endif

#endif	/* RELUCTOR_H */

