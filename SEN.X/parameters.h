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
#define tyre_perimeter_cm 167
#define wheel_teeth 32

#define TMR0_period_ms = 10
#define TMR1_period_ms = 100
// Wheels in same order as their CAN ID. (Left, Right, Front, Back/Rear)
#define WHEEL_BL  1 // Back Left
#define WHEEL_BR  2 // Back Right
#define WHEEL_FL  3 // Front Left
#define WHEEL_FR  4 // Front Right

    
// VARIABLES. Set which wheel is being programmed.
extern unsigned char ucWheelID = WHEEL_FL;

#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

