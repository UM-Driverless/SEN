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
#define WHEEL_FL  1
#define WHEEL_FR  2
#define WHEEL_RL  3
#define WHEEL_RR  4
    
    
//VARIABLES
extern unsigned char ucWheelID = WHEEL_FL;

#ifdef	__cplusplus
}
#endif

#endif	/* PARAMETERS_H */

