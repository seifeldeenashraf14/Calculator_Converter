

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
 
 #include "StdTypes.h"
 
 
 
 extern void Calculator(void);
extern u64 ADD_SUBSTRACTION(u32 num1_f,u32 num2_f);
extern void Convert_string_to_num(u8 x);
extern u64 MULTIPLICATION_DIVSION(u32 num1_f,u32 num2_f);
void RESET(void);
 extern u8 Neg_Result_flag,x,Counter_Number,flag_op,Neg_flag,Pos_flag,f,Neg_flag_first;
 extern u32 num,num1,num2;
 extern  u64 result;




#endif /* CALCULATOR_H_ */