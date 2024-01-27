#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "DIO_private.h"


void DIO_VoidInitPin(DIO_Pin_type Copy_u8Pin,DIO_PinStatus_type Copy_u8Status)
{
    switch (Copy_u8Status)
		{
			case OUTPUT:
			switch ((Copy_u8Pin/8))
			{
				case PA:
				SET_Bit(DDRA,Copy_u8Pin%8);
				CLR_Bit(PORTA,Copy_u8Pin%8);
				break;
				case PB:
				SET_Bit(DDRB,Copy_u8Pin%8);
				CLR_Bit(PORTB,Copy_u8Pin%8);
				break;
				case PC:
				SET_Bit(DDRC,Copy_u8Pin%8);
				CLR_Bit(PORTC,Copy_u8Pin%8);
				break;
				case PD:
				SET_Bit(DDRD,Copy_u8Pin%8);
				CLR_Bit(PORTD,Copy_u8Pin%8);
				break;
			}
			break;
			
			case INFREE:
			switch ((Copy_u8Pin/8))
			{
				case PA:
				CLR_Bit(DDRA,Copy_u8Pin%8);
				CLR_Bit(PORTA,Copy_u8Pin%8);
				break;
				case PB:
				CLR_Bit(DDRB,Copy_u8Pin%8);
				CLR_Bit(PORTB,Copy_u8Pin%8);
				break;
				case PC:
				CLR_Bit(DDRC,Copy_u8Pin%8);
				CLR_Bit(PORTC,Copy_u8Pin%8);
				break;
				case PD:
				CLR_Bit(DDRD,Copy_u8Pin%8);
				CLR_Bit(PORTD,Copy_u8Pin%8);
				break;
			}
			break;
			case INPULL:
			switch ((Copy_u8Pin/8))
			{
				case PA:
				CLR_Bit(DDRA,Copy_u8Pin%8);
				SET_Bit(PORTA,Copy_u8Pin%8);
				break;
				case PB:
				CLR_Bit(DDRB,Copy_u8Pin%8);
				SET_Bit(PORTB,Copy_u8Pin%8);
				break;
				case PC:
				CLR_Bit(DDRC,Copy_u8Pin%8);
				SET_Bit(PORTC,Copy_u8Pin%8);
				break;
				case PD:
				CLR_Bit(DDRD,Copy_u8Pin%8);
				SET_Bit(PORTD,Copy_u8Pin%8);
				break;
			}
			break;		
}
}
void DIO_voidWritePin(DIO_Pin_type Copy_u8Pin,DIO_PinVoltage_type Copy_u8Volt)

	{
		switch (Copy_u8Volt)
		{
			case HIGH :
			switch ((Copy_u8Pin/8))
			{
				case PA:
				SET_Bit(PORTA,Copy_u8Pin%8);
				break;
				case PB:
				SET_Bit(PORTB,Copy_u8Pin%8);
				break;
				case PC:
				SET_Bit(PORTC,Copy_u8Pin%8);
				break;
				case PD:
				SET_Bit(PORTD,Copy_u8Pin%8);
				break;
			}
			break;
			case LOW:
			switch ((Copy_u8Pin/8))
			{
				case PA:
				CLR_Bit(PORTA,Copy_u8Pin%8);
				break;
				case PB:
				CLR_Bit(PORTB,Copy_u8Pin%8);
				break;
				case PC:
				CLR_Bit(PORTC,Copy_u8Pin%8);
				break;
				case PD:
				CLR_Bit(PORTD,Copy_u8Pin%8);
				break;
			}
			break;
		}
	}
void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	switch (volt)
	{
		case HIGH :
		switch ((pin/8))
		{
			case PA:
			SET_Bit(PORTA,pin%8);
			break;
			case PB:
			SET_Bit(PORTB,pin%8);
			break;
			case PC:
			SET_Bit(PORTC,pin%8);
			break;
			case PD:
			SET_Bit(PORTD,pin%8);
			break;
		}
		break;
		case LOW:
		switch ((pin/8))
		{
			case PA:
			CLR_Bit(PORTA,pin%8);
			break;
			case PB:
			CLR_Bit(PORTB,pin%8);
			break;
			case PC:
			CLR_Bit(PORTC,pin%8);
			break;
			case PD:
			CLR_Bit(PORTD,pin%8);
			break;
		}
		break;
	}
}


DIO_PinVoltage_type DIO_DIO_PinVoltage_typeReadPin(DIO_Pin_type Copy_u8Pin)
{	
	DIO_PinVoltage_type volt=LOW;
		switch ((Copy_u8Pin/8))
		{
			case PA:
			 volt=READ_Bit(PINA,Copy_u8Pin%8);
			break;
			case PB:
			volt=READ_Bit(PINB,Copy_u8Pin%8);
			break;
			case PC:
			volt=READ_Bit(PINC,Copy_u8Pin%8);
			break;
			case PD:
			volt=READ_Bit(PIND,Copy_u8Pin%8);
			break;
		}
		return volt;
}


	
void DIO_VoidInit(void)
{
	DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_VoidInitPin(i,PinsStatusArray[i]);
	}
}


void DIO_VoidTogglePin(DIO_Pin_type Copy_u8Pin)
{
	
	switch ((Copy_u8Pin/8))
	{
		case PA:
		TOG_Bit(PORTA,Copy_u8Pin%8);
		break;
		case PB:
		TOG_Bit(PORTB,Copy_u8Pin%8);
		break;
		case PC:
		TOG_Bit(PORTC,Copy_u8Pin%8);
		break;
		case PD:
		TOG_Bit(PORTD,Copy_u8Pin%8);
		break;
	}
	
}

void DIO_VoidWritePort(DIO_Port_type Copy_u8Port,u8 Copy_u8Value)
{
		switch (Copy_u8Port)
		{
			case PA:
			PORTA=Copy_u8Value;
			break;
			case PB:
			PORTB=Copy_u8Value;
			break;
			case PC:
			PORTC=Copy_u8Value;
			break;
			case PD:
			PORTD=Copy_u8Value;
			break;
		}
}
u8 DIO_u8ReadPort(DIO_Port_type Copy_u8Port)
{
	
	u8 volt=0;
	switch (Copy_u8Port)
	{
		case PA:
		volt=PINA;
		break;
		case PB:
		volt=PINB;
		break;
		case PC:
		volt=PINC;
		break;
		case PD:
		volt=PIND;
		break;
	}
	
	return volt;
}

tenuErrrorStatus DIO_enuWriteGroup(DIO_Pin_type* pau8PinNumCpy , DIO_PinVoltage_type* pau8PinValueCpy,u8 u8Sizecpy)
{
	tenuErrrorStatus enuReturnStateLoc =EOK;

	u8 u8CounterLoc=0;

	for ( u8CounterLoc=0 ;   u8CounterLoc< u8Sizecpy ;u8CounterLoc++)
	{

		DIO_voidWritePin(pau8PinNumCpy[u8CounterLoc],pau8PinValueCpy[u8CounterLoc]);

	}

	return enuReturnStateLoc;
}
