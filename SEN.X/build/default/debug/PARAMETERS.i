# 1 "PARAMETERS.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/panze/.mchp_packs/Microchip/PIC18F-Q_DFP/1.12.193/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "PARAMETERS.c" 2







# 1 "./parameters.h" 1
# 27 "./parameters.h"
extern unsigned char ucWheelID;
extern unsigned char ucTyrePerimeter;
extern unsigned char ucWheelTeeth;



void PARAMETERSInit(void);
# 8 "PARAMETERS.c" 2



unsigned char ucWheelID;
unsigned char ucTyrePerimeter;
unsigned char ucWheelTeeth;




void PARAMETERSInit(void)
{
    ucWheelID = 1;
    ucTyrePerimeter = 167;
    ucWheelTeeth = 16;
}
