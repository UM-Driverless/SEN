# 1 "reluctor.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/DAVIDJ/.mchp_packs/Microchip/PIC18F-Q_DFP/1.12.193/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "reluctor.c" 2







# 1 "./reluctor.h" 1
# 25 "./reluctor.h"
extern unsigned long ulCountTeeth;
extern unsigned char ucCountPos;
extern unsigned int uiCountVueltaRueda;
extern unsigned char ucCountVueltaRueda1;
extern unsigned char ucCountVueltaRueda2;
extern unsigned char ucKPHData1;
extern unsigned char ucKPHData2;
extern unsigned char ucReluctorState;

extern unsigned long ui_cm_in_period;

extern unsigned long ui_MeterPerSecond_E_2;
extern unsigned long uiKPH_E_2;


void ReluctorFreqRead(void);
void ReluctorCountTeeth(void);
unsigned int ReluctorPosRead(void);
void ReluctorPosCount(void);
# 8 "reluctor.c" 2

# 1 "./parameters.h" 1
# 27 "./parameters.h"
extern unsigned char ucWheelID;
extern unsigned long ulTyrePerimeter;
extern unsigned long ulWheelTeeth;



void PARAMETERSInit(void);
# 9 "reluctor.c" 2



unsigned long ulCountTeeth;
unsigned char ucCountPos;
unsigned int uiCountVueltaRueda;
unsigned char ucCountVueltaRueda1;
unsigned char ucCountVueltaRueda2;


unsigned long ui_cm_in_period;

unsigned long ui_MeterPerSecond_E_2;
unsigned long uiKPH_E_2;
unsigned char ucKPHData1;
unsigned char ucKPHData2;
unsigned char ucReluctorState;


void ReluctorCountTeeth(void)
{
    ulCountTeeth++;
}

void ReluctorFreqRead(void)
{







    ui_cm_in_period = ( ulCountTeeth * 100 );
    ui_cm_in_period = ( ui_cm_in_period * ulTyrePerimeter );
    ui_cm_in_period = ( ui_cm_in_period / ulWheelTeeth );
    ui_MeterPerSecond_E_2 = ( ui_cm_in_period * 10 );
    ui_MeterPerSecond_E_2 = ( ui_MeterPerSecond_E_2 / 500 ) ;
    uiKPH_E_2 = ( ui_MeterPerSecond_E_2 * 36 );
    uiKPH_E_2 = ( uiKPH_E_2 / 10 );

    if ( uiKPH_E_2 >= 15000 )
    {
        ucReluctorState = 0x01;
    }




    else
    {
        ucReluctorState = 0x00;
        ucKPHData1 = (( uiKPH_E_2 / 100 ) & 0x00FF);
        ucKPHData2 = (( uiKPH_E_2 - ( 100 * ucKPHData1 )) & 0x00FF);
    }

    ulCountTeeth = 0;
}

void ReluctorPosCount(void)
{
    ucCountPos++;
    if(ucCountPos >= ulWheelTeeth){
        ucCountPos = 0;
        uiCountVueltaRueda++;
        ucCountVueltaRueda1 = uiCountVueltaRueda & 0x00FF;
        ucCountVueltaRueda2 = ( uiCountVueltaRueda >> 0x08 ) & 0x00FF;
    }
}

unsigned int ReluctorPosRead(void)
{
    return (( uiCountVueltaRueda * 360 ) + ( ucCountPos*360 / ulWheelTeeth));
}
