#include "StdTypes.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_cfg.h"

static DIO_Pin_type LCD_ArrayConfig[8]={PINA4,PINA5,PINA6,PINA7,PINB0,PINB1,PINB2,PINB3};
 
 #if LCD_MODE==_8_Bit
  void writeInstruction(u8 ins)
 {
	 	DIO_voidWritePin(RS,LOW);
	     LCD_HexToBin(ins);
	 	DIO_voidWritePin(EN,HIGH);
	 	_delay_ms(10);
	 	DIO_voidWritePin(EN,LOW);
	 	_delay_ms(10);
 }
   void writeData(u8 data)
  {
	  DIO_voidWritePin(RS,HIGH);
	  LCD_HexToBin(data);
	  DIO_voidWritePin(EN,HIGH);
	  _delay_ms(1);
	  DIO_voidWritePin(EN,LOW);
	  _delay_ms(1);
  }

void LCD_Init(void)
{
	_delay_ms(50);
    writeInstruction(0x38);  // 2 Line 8 Bit Mode  ( 5*7 dot )
    writeInstruction(0x0e);  // Cursor OFF and Display on
	writeInstruction(0x01);  //Clear Screen
	_delay_ms(10);
	writeInstruction(0x06);  // increase DDRAM address NO Shift
}/*
void LCD_Init_shift(void)
{
	_delay_ms(50);
	writeInstruction(0x38);  // 2 Line 8 Bit Mode  ( 5*7 dot )
	writeInstruction(0x0c);  // Cursor OFF and Display on
	writeInstruction(0x01);  //Clear Screen
	_delay_ms(1);
	writeInstruction(0x07);  // increase DDRAM address NO Shift
}*/

#elif LCD_MODE==_4_Bit

  void writeInstruction(u8 ins)
 {
	 DIO_voidWritePin(RS,LOW);
	 DIO_voidWritePin(D7,READ_Bit(ins,7));
	 DIO_voidWritePin(D6,READ_Bit(ins,6));
	 DIO_voidWritePin(D5,READ_Bit(ins,5));
	 DIO_voidWritePin(D4,READ_Bit(ins,4));
	 DIO_voidWritePin(EN,HIGH);
	 _delay_ms(1);
	 DIO_voidWritePin(EN,LOW);
	 _delay_ms(1);
	 DIO_voidWritePin(D7,READ_Bit(ins,3));
	 DIO_voidWritePin(D6,READ_Bit(ins,2));
	 DIO_voidWritePin(D5,READ_Bit(ins,1));
	 DIO_voidWritePin(D4,READ_Bit(ins,0));
	 DIO_voidWritePin(EN,HIGH);
	 _delay_ms(1);
	 DIO_voidWritePin(EN,LOW);
	 _delay_ms(1);
 }
 void writeData(u8 data)
 {
	 DIO_voidWritePin(RS,HIGH);
	 DIO_voidWritePin(D7,READ_Bit(data,7));
	 DIO_voidWritePin(D6,READ_Bit(data,6));
	 DIO_voidWritePin(D5,READ_Bit(data,5));
	 DIO_voidWritePin(D4,READ_Bit(data,4));
	 DIO_voidWritePin(EN,HIGH);
	 _delay_ms(1);
	 DIO_voidWritePin(EN,LOW);
	 _delay_ms(1);
	 DIO_voidWritePin(D7,READ_Bit(data,3));
	 DIO_voidWritePin(D6,READ_Bit(data,2));
	 DIO_voidWritePin(D5,READ_Bit(data,1));
	 DIO_voidWritePin(D4,READ_Bit(data,0));
	 DIO_voidWritePin(EN,HIGH);
	 _delay_ms(1);
	 DIO_voidWritePin(EN,LOW);
	 _delay_ms(1);
 }

 void LCD_Init(void)
 {
	 _delay_ms(50);
	  writeInstruction(0x02);
	 writeInstruction(0x28);  // 2 Line 4 Bit Mode  ( 5*7 dot )
	 writeInstruction(0x0c);  // Cursor OFF and Display on
	 writeInstruction(0x01);  //Clear Screen
	 _delay_ms(1);
	 writeInstruction(0x06);  // increase DDRAM address NO Shift
 }
 void LCD_Init_shift(void)
 {
	 _delay_ms(50);
	 writeInstruction(0x02);
	 writeInstruction(0x28);  // 2 Line 4 Bit Mode  ( 5*7 dot )
	 writeInstruction(0x0c);  // Cursor OFF and Display on
	 writeInstruction(0x01);  //Clear Screen
	 _delay_ms(1);
	 writeInstruction(0x07);  // increase DDRAM address  Shift
 }
#endif
void LCD_WriteChar(u8 ch)
{
	writeData(ch);
}

void LCD_WriteNumber(s64 num)//5841
{   u8 str[16]={0},i=0,flag_negative=0;
	s8 j;
	if(num==0)
	{
		LCD_WriteChar('0');
	}
	else 
	{
		
		if(num>0)
		{
		}
		else if(num<0)
		{
			num=num*(-1);
			flag_negative=1;
		}
		
		while(num)
		{
			str[i]=num%10+'0';
			num=num/10;
			i++;
		}
		
		if(flag_negative==0)
		{
			j=i-1;
		}
		else
		{
			j=i;
		}
		while(j>=0)
		{
			if(j==i&&flag_negative==1)
			{
				LCD_WriteChar('-');
			}
			else
			{
				LCD_WriteChar(str[j]);
			}	
			j--;
		}
		}
}


void LCD_WriteString(pu8 str)
{     
	u8 i;
	for(i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}
/*
void LCD_WriteBinary(u8 ch)
{
	s8 i,x;
	for(i=7;i>=0;i--)
	{   
		x=READ_Bit(ch,i)+'0';
		LCD_WriteChar(x);
	}
}*/
/*
void LCD_WriteHex(u8 ch)
{
    s8 i=0,x=0,j=3,z;
	for(i=7;i>=0;i--)
	{  
		z=READ_Bit(ch,i);
		x=x+(z*Power(2,j));
		j--;
		if(i==0||i==4)
		{   
			if((x<10) && (x>=0))
			{
				LCD_WriteChar((x+'0'));
			} 
			else
			{
				if(x==10)
				{
					LCD_WriteChar('A');
				}
				else if (x==11)
				{
					LCD_WriteChar('B');
				}
				else if (x==12)
				{
					LCD_WriteChar('C');
				}
				else if (x==13)
				{
					LCD_WriteChar('D');
				}
				else if (x==14)
				{
					LCD_WriteChar('E');
				}
				else if (x==15)
				{
					LCD_WriteChar('F');
				}
			}
			j=3;
			x=0;
		}
		}
}*/

void LCD_Setcursor(u8 line,u8 cell)
{
	writeInstruction(LCD_indexes[line-1][cell-1]);
}
void LCD_Clear(void)
{
	writeInstruction(0x01);
}/*
void LCD_Setcursorcgram(u8 adress)
{
	writeInstruction((adress+64));
}
*/












void LCD_HexToBin(u8 ins )
{
	static DIO_PinVoltage_type au8BinValuesLoc[8];
	u8 u8CounterLoc;
	for (u8CounterLoc=0; u8CounterLoc<8;u8CounterLoc++)
	{
		au8BinValuesLoc[u8CounterLoc]=READ_Bit(ins,u8CounterLoc);
	}
	DIO_enuWriteGroup(LCD_ArrayConfig,au8BinValuesLoc,8);
}








u32 Power(u32 num,u32 exp)
{
	u32 i,result=1;
	for(i=1; exp>=i; i=i+1)
	{
		result=result*num;
	}

	return result;
}
