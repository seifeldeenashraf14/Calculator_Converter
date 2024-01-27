


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
#include "StdTypes.h"
#include "Utils.h"
#include "KeyPad_cfg.h"

void KEYPAD_Init(void);
u8 KEYPAD_GetKey(void);
void Choose_Mode(u8 Mode);



#endif /* KEYPAD_INTERFACE_H_ */
