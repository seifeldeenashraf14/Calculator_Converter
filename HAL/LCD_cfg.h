


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "StdTypes.h"
#include "DIO_interface.h"

#define Lines 2
#define Cells_per_line 16


#include "LCD_private.h"

#define LCD_MODE _8_Bit

#define RS PINC2
#define EN PINC3


/*****************************8 BIT Mode************************************/
#define LCD_Port PA

/***************************** 4 BIT Mode************************************/
#define D7 PINA7
#define D6 PINA6
#define D5 PINA5
#define D4 PINA4





#endif /* LCD_CFG_H_ */
