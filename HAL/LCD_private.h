/*
 * LCD_private.h
 *
 * Created: 02/14/23 1:28:42 PM
 *  Author: Seif
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_
#include "LCD_cfg.h"
#define _4_Bit 1
#define _8_Bit 2

 void  writeInstruction(u8 ins);
 void writeData(u8 data);
extern const u8 LCD_indexes [Lines][Cells_per_line];
extern u32 Power(u32 num,u32 exp);



#endif /* LCD_PRIVATE_H_ */
