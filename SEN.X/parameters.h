/* 
 * File:   parameters.h
 * Author: ruben
 *
 * Created on September 17, 2021, 7:44 PM
 */

#ifndef PARAMETERS_H
#define	PARAMETERS_H

#ifdef	__cplusplus
extern "C" {
#endif

// OUR CONSTANTS
#define TMR0_period_ms      10
#define TMR1_period_ms      500
#define REL_base_calculo    100
// Wheels in same order as their CAN ID. (Left, Right, Front, Back/Rear)
#define WHEEL_FL  1 // Front Left
#define WHEEL_FR  2 // Front Right
#define WHEEL_RL  3 // Rear Left
#define WHEEL_RR  4 // Rear Right

    
// VARIABLES. Set which wheel is being programmed.
extern unsigned char ucWheelID;
extern unsigned long ulTyrePerimeter;
extern unsigned long ulWheelTeeth;


// FUNCIONES
void PARAMETERSInit(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

