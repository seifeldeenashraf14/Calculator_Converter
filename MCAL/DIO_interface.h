

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "StdTypes.h"
typedef enum
{   PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
    PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
    PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
	}DIO_Pin_type;
	
	typedef enum
	{
		OUTPUT,
		INFREE,
		INPULL
	} DIO_PinStatus_type;
	
	
	typedef enum
	{
		PA,
		PB,
		PC,
		PD
	} DIO_Port_type;
		
		typedef enum
		{
			LOW=0,
			HIGH
		}DIO_PinVoltage_type;



extern void DIO_VoidInit(void);
extern void DIO_voidWritePin(DIO_Pin_type Copy_u8Pin,DIO_PinVoltage_type Copy_u8Volt);
extern DIO_PinVoltage_type DIO_DIO_PinVoltage_typeReadPin(DIO_Pin_type Copy_u8Pin);
extern void DIO_VoidTogglePin(DIO_Pin_type Copy_u8Pin);
void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt);

extern void DIO_VoidWritePort(DIO_Port_type Copy_u8Port,u8 Copy_u8Value);
extern u8 DIO_u8ReadPort(DIO_Port_type Copy_u8Port);
tenuErrrorStatus DIO_enuWriteGroup(DIO_Pin_type* pau8PinNumCpy , DIO_PinVoltage_type* pau8PinValueCpy,u8 u8Sizecpy);










#endif /* DIO_INTERFACE_H_ */
