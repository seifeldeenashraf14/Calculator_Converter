#include "Converter.h"
#define NO_KEY 'T'

u8 first_message=0,Button,Dec_1,Bin_1,Hex_1,Dec_2,Bin_2,Hex_2,Reset=0,i_1=5,i_power=7,C_Hex;
u32 num_100;

void Converter(void)
{    
	  First_Settings();
	  Convert_string_to_value();
	  Display_Output();
	  Reset_conv();
}



void Convert_string_to_value(void)
{   
	Button=KEYPAD_GetKey();
	if(Button!=NO_KEY)
   {
		if(Hex_1==1&&C_Hex<2)
	   {
		C_Hex++;
		if(Button=='c')
		{
			Button='A';
		}
		else if (Button=='=')
		{
			Button='B';
		}
		else if (Button=='+')
		{
			Button='C';
		}
		else if (Button=='-')
		{
			Button='D';
		}
		else if (Button=='*')
		{
			Button='E';
		}
		else if (Button=='/')
		{
			Button='F';
		}
	  }  
   }
	
	if(Button!=NO_KEY&&Button!='=')
	{
			if(Reset==4)
			{    
				if(Dec_1==1)
				{
					       LCD_Setcursor(1,i_1);
					        i_1++;
						   LCD_WriteChar(Button);
						  num_100=(num_100*10)+((Button)-'0');
						   
				}
				else if(Bin_1==1)
				{ 
					if(Button=='0'||Button=='1')
					{
					  LCD_Setcursor(1,i_1);
					  i_1++;
					  LCD_WriteChar(Button);
					   num_100=num_100+(Button-'0')*(Power(2,i_power));
					   i_power--;
					}
				}
				else if (Hex_1==1)
				{   
					  LCD_Setcursor(1,i_1);
					  i_1++;
					  LCD_WriteChar(Button); 
					if(C_Hex==1)
					{
							
						if(Button=='A'||Button=='B'||Button=='C'||Button=='D'||Button=='E'||Button=='F')
						{
							num_100=(Button-'7')*16;
						}
						else
						{
							num_100=(Button-'0')*16;
						}
					}
					else if(C_Hex==2)
					{
							if(Button=='A'||Button=='B'||Button=='C'||Button=='D'||Button=='E'||Button=='F')
							{
								num_100=num_100+(Button-'7');
							}
							else
							{
								num_100=num_100+(Button-'0');
							}
					}
				}

		}
	}


}


void First_Settings(void)
{
	if(first_message==0)
	{
		LCD_Setcursor(1,5);
		LCD_WriteString("Converter");
		_delay_ms(2000);
		LCD_Setcursor(1,1);
		LCD_WriteString("                  ");
		first_message=1;
	}
	if(Reset==0&&first_message==1)
	{   
		LCD_Setcursor(1,3);
		LCD_WriteString("Convert from");
		LCD_Setcursor(2,1);
		LCD_WriteString("1-De 2-Bi 3-Hex");
		Button=KEYPAD_GetKey();
		if(Button=='1')
		{
			Reset=1;
			Dec_1=1;
		}
		else if (Button=='2')
		{
			Reset=1;
			Bin_1=1;
		}
		else if (Button=='3')
		{
			Reset=1;
			Hex_1=1;
		} 
		else
		{    if(Button!=NO_KEY)
			{
					LCD_Clear();
					LCD_Setcursor(1,4);
					LCD_WriteString("Wrong Entery");
					_delay_ms(1000);
					LCD_Setcursor(1,4);
					LCD_WriteString("                     ");
			}
		}
		if(Reset==1)
		{
			LCD_Setcursor(1,3);
			LCD_WriteString("                     ");
		}
	}
	if(Reset==1)
	{
		LCD_Setcursor(1,3);
		LCD_WriteString("Convert to");
		LCD_Setcursor(2,1);
		LCD_WriteString("1-De 2-Bi 3-Hex");
		Button=KEYPAD_GetKey();
		if(Button=='1')
		{
			Reset=2;
			Dec_2=1;
		}
		else if (Button=='2')
		{
			Reset=2;
			Bin_2=1;
		}
		else if (Button=='3')
		{
			Reset=2;
			Hex_2=1;
		}
		else
		{
             if(Button!=NO_KEY)
			  {
				  LCD_Clear();
				  LCD_Setcursor(1,4);
				  LCD_WriteString("Wrong Entery");
				  _delay_ms(1000);
				  LCD_Setcursor(1,4);
				  LCD_WriteString("                     ");
			  }
		}
			if(Reset==2)
			{
				LCD_Setcursor(1,3);
				LCD_WriteString("                     ");
				LCD_Setcursor(2,1);
				LCD_WriteString("                     ");
				Reset=3;
			}
	}
	if(Reset==3)
	{
		if(Dec_1==1&&Bin_2==1)
		{
			LCD_Setcursor(1,1);
			LCD_WriteString("Dec:");
			LCD_Setcursor(2,1);
			LCD_WriteString("Bin:");
		}
		else if(Dec_1==1&&Hex_2==1)
		{
			LCD_Setcursor(1,1);
			LCD_WriteString("Dec:");
			LCD_Setcursor(2,1);
			LCD_WriteString("Hex:");
		}
		else if(Bin_1==1&&Dec_2==1)
		{
			LCD_Setcursor(1,1);
			LCD_WriteString("Bin:");
			LCD_Setcursor(2,1);
			LCD_WriteString("Dec:");
		}
		else if(Bin_1==1&&Hex_2==1)
		{
			LCD_Setcursor(1,1);
			LCD_WriteString("Bin:");
			LCD_Setcursor(2,1);
			LCD_WriteString("Hex:");
		}
		else if(Hex_1==1&&Dec_2==1)
		{
			LCD_Setcursor(1,1);
			LCD_WriteString("Hex:");
			LCD_Setcursor(2,1);
			LCD_WriteString("Dec:");
		}
		else if(Hex_1==1&&Bin_2==1)
		{
			LCD_Setcursor(1,1);
			LCD_WriteString("Hex:");
			LCD_Setcursor(2,1);
			LCD_WriteString("Bin:");
		}
		Reset=4;
	}
}


void Display_Output(void)
{
	if(Button=='=')
	{   
		LCD_Setcursor(2,5);
		Reset=5;
		if(Dec_2==1)
		{
			LCD_WriteNumber(num_100);
		}
		else if (Bin_2==1)
		{
			LCD_WriteBinary(num_100);
		}
		else if (Hex_2==1)
		{
			LCD_WriteHex(num_100);
		}
	}
}


void Reset_conv(void)
{   if(Reset==5&&Button=='c')
	{ 
		LCD_Setcursor(1,1);
		LCD_WriteString("         ");
		LCD_Setcursor(2,1);
		LCD_WriteString("         ");
	Reset=0;
	Dec_1=0;
	Bin_1=0;
	Hex_1=0;
	Dec_2=0;
	Bin_2=0;
	Hex_2=0;
	i_1=5;
	i_power=7;
	C_Hex=0;
	num_100=0;
	}
}