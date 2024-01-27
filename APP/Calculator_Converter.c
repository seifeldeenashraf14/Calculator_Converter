#include "Calculator_Converter.h"


u8 ynamooos=0,flag_numooooos=0;


void Calculator_Converter(void)
{
	ynamooos=KEYPAD_GetKey();
if(flag_numooooos==0)
{
LCD_WriteString("Choose mode");
LCD_Setcursor(2,1);
LCD_WriteString("1-Calc");
LCD_Setcursor(2,11);
LCD_WriteString("2-Conv");
flag_numooooos=1;
}

if(ynamooos=='1')
{
LCD_Clear();
	Choose_Mode(Calculator_Mode);
	while(1)
	{
		Calculator();
	}

}
else if(ynamooos=='2')
{
	LCD_Clear();
	Choose_Mode(Converter_Mode);
	while(1)
	{
		Converter();
	}
}


	}









