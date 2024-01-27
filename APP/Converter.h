


#ifndef CONVERTER_H_
#define CONVERTER_H_
 #include "StdTypes.h"
 #include "Utils.h"
 #include "DIO_interface.h"
 #include "LCD_interface.h"
 #include "KeyPad_interface.h"
extern void Converter(void);
extern void Convert_string_to_value(void);
extern void First_Settings(void);
void Display_Output(void);
void Reset_conv(void);
extern u8 first_message,Button,Dec_1,Bin_1,Hex_1,Dec_2,Bin_2,Hex_2,Reset,i_1;
extern u32 num_100;


#endif /* CONVERTER_H_ */