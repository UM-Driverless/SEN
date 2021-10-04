/* 
 * File:   MESSAGE.c
 * Author: 93Urbano
 *
 * Created on October 1, 2021, 10:50 AM
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//INCLUDES
#include "mcc_generated_files/mcc.h"
    
    
//DEFINICION DE CONSTANTES    
#define CAN_TX_BUFF  "BUFFERCAN"
 
CAN_MSG_OBJ msg;
uint8_t CANDATAdata[32] = CAN_TX_BUFF;
    
//ID CAN

#define ID_IMUSENBL 0x3E5
#define ID_SIGSENBL 0x6E6
#define ID_ERRORSENBL 0x6E7

#define ID_IMUSENBR 0x3E8
#define ID_SIGSENBR 0x6E9
#define ID_ERRORSENBR 0x6EA

#define ID_IMUSENFL 0x3EB
#define ID_SIGSENFL 0x6EC
#define ID_ERRORSENFL 0x6ED

#define ID_IMUSENFR 0x3EE
#define ID_SIGSENFR 0x6EF
#define ID_ERRORSENFR 0x6F0








//DEFINICION DE FUNCIONES    
void CANWriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);




#ifdef	__cplusplus
}
#endif

#endif	/* MESSAGE_H */
