/*
 * KeyPad_cfg.h
 *
 * Created: 02/16/23 4:17:27 PM
 *  Author: Seif
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "DIO_interface.h"
#include "StdTypes.h"
#define FIRST_OUTPUT PINC4
#define FIRST_INPUT PIND4
#define Modes 2
#define Calculator_Mode 0
#define Converter_Mode 1

#define ROWS 4
#define COLS 4
#define NO_KEY 'T'
extern  u8 KeysArray [Modes][ROWS][COLS];
#define ROWS 4
#define COLS 4




#endif /* KEYPAD_CFG_H_ */
