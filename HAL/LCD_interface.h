


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "StdTypes.h"
#include "DIO_interface.h"




extern void LCD_Init(void);
extern void LCD_Init_shift(void);
extern void LCD_WriteNumber(s64 num);
extern void LCD_WriteChar(u8 ch);
extern void LCD_WriteString(pu8 str);
extern void LCD_WriteBinary(u8 ch);
extern void LCD_WriteHex(u8 ch);
extern void LCD_Clear(void);
extern void LCD_Setcursor(u8 line,u8 cell); // line 1,2  cell 1:16
extern void LCD_Setcursorcgram(u8 adress);
extern u32 Power(u32 num,u32 exp);
void LCD_HexToBin(u8 ins );




#endif /* LCD_INTERFACE_H_ */
