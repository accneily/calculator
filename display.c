#include "stc89c5xRC.h"

typedef unsigned char UINT8;
typedef unsigned int UINT16;

UINT8 code _7SegTab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                       0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
UINT16 j;
void vValTOShow(UINT16 u2Val,UINT8 HEX_DEC)
{
	UINT8 k, uData;
    for (k=0; k<4; k++)    
    {	
		uData = u2Val%HEX_DEC;
        u2Val /= HEX_DEC;  
        P0 = _7SegTab[uData];
        P1 = (P1 & 0xF0) | (0x01 << k);    //不影响P1口的高四位
        j=250;
        while(j--);
        P1 = P1 & 0xF0;  //去除余晖，不仿真可以不加这一句。不P1&0XF0影响P1口的高四位
    }
}
