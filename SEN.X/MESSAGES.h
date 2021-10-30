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

#define data_lenght0 0
#define data_lenght1 1
#define data_lenght2 2
#define data_lenght3 3
#define data_lenght4 4
#define data_lenght5 5
#define data_lenght6 6
#define data_lenght7 7
#define data_lenght8 8
    
//ID CAN

#define ID_IMUSENFL     0x3E5
#define ID_SIGSENFL     0x6E6
#define ID_ERRORSENFL   0x6E7

#define ID_IMUSENFR     0x3E8
#define ID_SIGSENFR     0x6E9
#define ID_ERRORSENFR   0x6EA

#define ID_IMUSENRL     0x3EB
#define ID_SIGSENRL     0x6EC
#define ID_ERRORSENRL   0x6ED

#define ID_IMUSENRR     0x3EE
#define ID_SIGSENRR     0x6EF
#define ID_ERRORSENRR   0x6F0



//DEFINICION DE FUNCIONES    
void CANWriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8);
void MESSAGESSendEvery100ms(void);



#ifdef	__cplusplus
}
#endif

#endif	/* MESSAGE_H */
