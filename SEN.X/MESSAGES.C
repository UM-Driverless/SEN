/* 
 * File:   MESSAGES.c
 * Author: 93Urbano
 *
 * Created on October 1, 2021, 10:50 AM
 */

#include "MESSAGES.h"
#include "mcc_generated_files/mcc.h"
#include "parameters.h"
#include "reluctor.h"


void CANWriteMessage(unsigned long id, unsigned char dataLength, unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6, unsigned char data7, unsigned char data8)
{
    unsigned int uiData1;
    unsigned int uiData2;
    unsigned int uiData3;
    unsigned int uiData4;
   
    //CANMessageInit();
    
    uiData1 = ( data1 << 0x08 ) & 0xFF00;
    uiData1 |= data2;
    uiData2 = ( data3 << 0x08 ) & 0xFF00;
    uiData2 |= data4;
    uiData3 = ( data5 << 0x08 ) & 0xFF00;
    uiData3 |= data6;
    uiData4 = ( data7 << 0x08 ) & 0xFF00;
    uiData4 |= data8;
    
    CANDATAdata [0] = data1;
    CANDATAdata [1] = data2;
    CANDATAdata [2] = data3;
    CANDATAdata [3] = data4;
    CANDATAdata [4] = data5;
    CANDATAdata [5] = data6;
    CANDATAdata [6] = data7;
    CANDATAdata [7] = data8;
    
    msg.msgId = id;
    msg.field.formatType = CAN_2_0_FORMAT;  //CAN 2.0
    msg.field.brs = CAN_NON_BRS_MODE;   //NO BRS
    msg.field.frameType = CAN_FRAME_DATA;   //FRAME DATA, NO REMOTE
    msg.field.idType = CAN_FRAME_STD;   //CAN VERSION STANDARD
    msg.field.dlc = dataLength; //DATA LENGTH
    msg.data = CANDATAdata;
    
    //POSIBLES FALLOS 
    if(CAN1_IsBusOff() == true)
    {
        Nop();
    }
    if(CAN1_IsTxErrorPassive() == true)
    {
        Nop();
    }
    if(CAN1_IsTxErrorWarning() == true)
    {
        Nop();
    }
    if(CAN1_IsTxErrorActive() == true)
    {
        Nop();
    }

    if(CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(CAN1_TX_TXQ) & CAN_TX_FIFO_AVAILABLE))
    {
        CAN1_Transmit(CAN1_TX_TXQ, &msg);
        Nop();
    }
}

void MESSAGESSendEvery100ms(void)
{
    switch (ucWheelID)
    {
        case WHEEL_FL:
            if ( ucReluctorState == VELOCITYOK )
            {
                CANWriteMessage(ID_SIGSENFL, data_lenght8, 0,0,0,0,ucKPHData1, ucKPHData2, ucCountVueltaRueda1, ucCountVueltaRueda2);
                Nop();
                CANWriteMessage(ID_SIGSENRL, data_lenght8, 0,0,0,0,10, 20, ucCountVueltaRueda1, ucCountVueltaRueda2);
            }
            break;
        case WHEEL_FR:
            if ( ucReluctorState == VELOCITYOK )
            {
                CANWriteMessage(ID_SIGSENFL, data_lenght8, 0,0,0,0,ucKPHData1, ucKPHData2, ucCountVueltaRueda1, ucCountVueltaRueda2);
                Nop();
                CANWriteMessage(ID_SIGSENRL, data_lenght8, 0,0,0,0,10, 20, ucCountVueltaRueda1, ucCountVueltaRueda2);
            }
            break;
        case WHEEL_RL:
            break;
        case WHEEL_RR:
            break;
    }
    
}

