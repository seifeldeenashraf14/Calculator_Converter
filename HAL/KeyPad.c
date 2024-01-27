
#include "KeyPad_cfg.h"
#include "KeyPad_interface.h"
#include "Utils.h"


u8 MODE;
void KEYPAD_Init(void)
{
	DIO_voidWritePin(FIRST_OUTPUT,HIGH);
	DIO_voidWritePin(FIRST_OUTPUT+1,HIGH);
	DIO_voidWritePin(FIRST_OUTPUT+2,HIGH);
	DIO_voidWritePin(FIRST_OUTPUT+3,HIGH);
}

void Choose_Mode(u8 Mode)
{
 switch(Mode)
 {
 case Calculator_Mode :
	 MODE=0;
	 break;
 case Converter_Mode :
	 MODE=1;
	 break;
 }
}
u8 KEYPAD_GetKey(void)
{  
	u8 r,c,key=NO_KEY;
	for(r=0;r<ROWS;r++)
	{
		DIO_voidWritePin(FIRST_OUTPUT+r,LOW);
		for(c=0;c<COLS;c++)
		{
			if(DIO_DIO_PinVoltage_typeReadPin(FIRST_INPUT+c)==LOW)
			{

					key=KeysArray[0][r][c];

			}
			/*if(key=='8'||key=='2')
			{
          _delay_ms(20);
			}*/
			//else
			//{
			while(DIO_DIO_PinVoltage_typeReadPin(FIRST_INPUT+c)==LOW);
			//}
		}

		DIO_voidWritePin(FIRST_OUTPUT+r,HIGH);

	}
	return key ;
	
}
