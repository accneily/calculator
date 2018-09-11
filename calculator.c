#include "stc89c5xRC.h"
#include <stdio.h>
typedef unsigned char UINT8;
typedef unsigned int UINT16;
void delay(UINT16 i);
void vValTOShow(UINT16 key_value,UINT8 HEX_DEC);
void KEYSCAN();
UINT8 pre_P2,pre_P2=0xf0,i,x;
bit	pre_P32,pre_P33,flag,flag2 ;
UINT8 key_value;
UINT8 num[4],num2[2];
UINT16 key_value1;



void main ()
{
    
    while(1)
    {  	
	   KEYSCAN();
	   if(P32==0&&pre_P32==1)
		{
			flag=1;
		}

	   if(P2!=0xf0&&pre_P2==0xf0)
		{
	   		num[i]=key_value;
			key_value1=num[i];
			i++;
		}
		if(flag==0)
		{
			if(i==1)
			{
				 num2[0]  = num[0];
			}
			
			if(i==2)
			{	
				num2[0]  = num[0]*10+num[1];
				key_value1=num2[0] ;
				flag2=1;  
			}
		}

		if(flag==1)
		{
			if(i==2&&flag2==0)
			{
				num2[1]=num[1];
				key_value1=num2[1] ;
			}
			if(i==3)
			{
				if(flag2==1)
				{
					num2[1]=num[2];
					key_value1=num2[1] ;
				}
				

				if(flag2==0)
				{
				num2[1]=num[1]*10+num[2];
				key_value1=num2[1] ;
				}
			}


		

			if(i==4)
			{
				num2[1]=num[2]*10+num[3];
				key_value1=num2[1] ;	
			}	
		}


		if(P33==0&&pre_P33==1)
		{
		 	key_value1=num2[0]*num2[1];
			flag=0;flag2=0;
			i=0;
		}
		if(P34==0)
		{
			i=0;
			flag=0;
			flag2=0;
			key_value1=0;	
		}

	   pre_P2=P2;
	   pre_P32=P32;
	   pre_P33=P33;

	   vValTOShow(key_value1,10);

	   
	 }



}

void KEYSCAN()
{
	UINT8 rom,column;
	P2=0xf0;
	if(P2!=0xf0)
	{	
		delay(500);
		if(P2!=0xf0)
		{
			
			P2=0xf0,rom=P2;
			P2=0x0f,column=P2;
			switch(rom)
			{
				case 0xe0:	key_value=0;	break;
				case 0xd0:	key_value=1;	break;
				case 0xb0:	key_value=2;	break;
				case 0x70:	key_value=3;	break;
				default:	key_value=16;
			}
			switch(column)
			{
				case 0x0e:	key_value=key_value;   	break;
				case 0x0d:	key_value=key_value+4; 	break;
				case 0x0b:	key_value=key_value+8; 	break;
				case 0x07:	key_value=key_value+12;	break;	
				default:	key_value=16;
			}
		}
	}
}

void delay(UINT16 i)
{
	while(i--);
}
