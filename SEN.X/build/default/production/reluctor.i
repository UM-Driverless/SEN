# 1 "reluctor.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/ruben/.mchp_packs/Microchip/PIC18F-Q_DFP/1.12.193/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "reluctor.c" 2







# 1 "./reluctor.h" 1
# 15 "./reluctor.h"
# 1 "./parameters.h" 1
# 25 "./parameters.h"
extern unsigned char ucWheelID = 1;
# 15 "./reluctor.h" 2
# 26 "./reluctor.h"
extern unsigned char ucCountFreq;
extern unsigned char ucCountPos;
extern unsigned char ucCountVueltaRueda;
extern unsigned char ucKPHData1;
extern unsigned char ucKPHData2;


void ReluctorFreqRead(void);
void ReluctorFreqCount(void);
unsigned int ReluctorPosRead(void);
void ReluctorPosCount(void);
# 8 "reluctor.c" 2




unsigned char ucCountFreq;
unsigned char ucCountPos;
unsigned char ucCountVueltaRueda;
unsigned int uiMeterPerSecond;
unsigned int uiKmeterPerHour;
unsigned char ucKPHData1;
unsigned char ucKPHData2;
unsigned char ucReluctorState;


void ReluctorFreqCount(void)
{
    ucCountFreq++;
}

void ReluctorFreqRead(void)
{
    uiMeterPerSecond = ucCountFreq*(167/32);
    uiKmeterPerHour = uiMeterPerSecond * 36/10;

    if ( uiKmeterPerHour >= 15000 )
    {
        ucReluctorState = 0x01;
    }
    else
    {
        ucReluctorState = 0x00;
        ucKPHData1 = (( uiKmeterPerHour / 100 ) & 0x00FF);
        ucKPHData2 = (( uiKmeterPerHour - ( 1000 * ucKPHData1 )) & 0x00FF);
    }

    ucCountFreq = 0;
}

void ReluctorPosCount(void)
{
    ucCountPos++;
    if(ucCountPos >= 32){
        ucCountPos = 0;
        ucCountVueltaRueda++;
    }
}

unsigned int ReluctorPosRead(void)
{
    return (( ucCountVueltaRueda * 360 ) + ( ucCountPos*360 / 32));
}
