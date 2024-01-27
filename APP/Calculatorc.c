 
 #include "LCD_interface.h"
 #include "KeyPad_interface.h"
 #include "Calculator.h"
 
 
  u8 Neg_Result_flag,x,flag_op,Neg_flag,Pos_flag,Neg_flag_first,c,Multi_flag,Div_flag,Done_operation,flag,flag_another_op;
  u32 num,num1,num2;
  u64 result;
  u8 f=1;


void Calculator(void)
{    
	x=KEYPAD_GetKey();
	if(x!=NO_KEY)
	{
		if(Done_operation==1&&x!='='&&flag_another_op==0)
			{
				LCD_Clear();
				LCD_Setcursor(1,1);
				if(Neg_Result_flag==1)
				{  
						LCD_WriteChar('-');
				}
				LCD_WriteNumber(num1);
				flag_another_op=1;
			}
		LCD_WriteChar(x);
		Convert_string_to_num(x);	
	}
		if(x=='=')
		{  
			if(Multi_flag==1||Div_flag==1)
			{
				result=MULTIPLICATION_DIVSION(num1,num2);
			}
			else
			{
				result=ADD_SUBSTRACTION(num1,num2);
			}
			LCD_Setcursor(2,1);
			if(Neg_Result_flag==1)
			{  
		
					LCD_WriteChar('-');
			}
			LCD_WriteNumber(result);
			Done_operation=1;
			num1=result;
			RESET();
		}
		if(x=='c')
		{
			LCD_Clear();
			RESET();
			num1=0;
			c=0;
			Done_operation=0;
			flag_another_op=0;
			Neg_Result_flag=0;
			flag=0;
		}
		
}


void Convert_string_to_num(u8 x)
{     
	if(Neg_Result_flag==1)
	{
		 Neg_flag=1;
		 Neg_flag_first=1;
		 flag_op++;//first minus
		 Neg_Result_flag=0;
	}
	if(((flag_op==2&&flag==0)||(Pos_flag==1&&flag==0)||((Neg_flag==1)&&(Neg_flag_first==0)&&(flag==0))||(Multi_flag==1&&flag==0)||(Div_flag==1&&flag==0))&&Done_operation==0)
	{
		num1=num;
		num=0;
		flag=1;
	}
	if((x>='0')&& (x<='9'))
	{
		num=((num)*f)+(x-'0');
		f=10;
	}
	else 
	{
		 if ((flag_op==0)&&(x==('+')))                                
		 {
			 Pos_flag=1;
			 flag_op++;//no minus before
		 } 
		else if ((flag_op==0)&&(x==('-'))&&c==0)
		 {
			 Neg_flag=1;
			 Neg_flag_first=1;
			 flag_op++;//first minus
		 }
		  else if ((flag_op==0)&&(x==('-'))&&c!=0)
		  {
			  Neg_flag=1;
			  flag_op++;//first minus
		  }
		 else if((flag_op==1)&&(x==('+')))
		 {
			 	 Pos_flag=1;
			 	 flag_op++;// there is minus before
		 }
		  else if((flag_op==1)&&(x==('-')))
		  {  
			  if(Neg_flag==1)
			  {
				 Neg_flag=2; 
			  } 
			  else
			  {
				  Neg_flag=1;
			  }
			  
			  flag_op++;//second minus
		  }
		   else if((flag_op==2)&&(x==('-')))
		    {
			    Neg_flag=3;
			    flag_op++;//Third minus
		    }
			else if (x==('*'))
			{
				Multi_flag=1;
			}
			else if (x==('/'))
			{
				Div_flag=1;
			}
	}
	if(x=='=')
	{
		num2=num;
		num=0;
	}
	c++;
}


 u64 ADD_SUBSTRACTION(u32 num1_f,u32 num2_f)
 {
	 u64 result1=0;
	 Neg_Result_flag=0;
	 if((Pos_flag==1&&flag_op==1)||((Neg_flag==2)&&(flag_op==2)&&(Neg_flag_first==0)))
	 {
		 result1=num1_f+num2_f;
	 }
	 else if ((Neg_flag==2&&flag_op==2&&Neg_flag_first==1)||(Neg_flag==2&&flag_op==3))
	 {
		 result1=num1_f+num2_f;
		 Neg_Result_flag=1;// TO write Minus
	 } 
	 else if ((Neg_flag==3)||((Neg_flag==1)&&(Neg_flag_first==1)&&(Pos_flag==1)))
	 {
		  if(num1_f>num2_f)
		  {
			  result1=num1_f-num2_f;
				   Neg_Result_flag=1;// TO write Minus 
		  }
		  else if(num2_f>=num1_f)
		   {
			   result1=num2_f-num1_f;
		   } 
	 }
	 else if(((Neg_flag==1)&&(Pos_flag==0)&&(flag_op==1)&&(Neg_flag_first==0))||(Neg_flag_first==0&&Neg_flag==1&&Pos_flag==1))
	 {
		   if(num1_f>num2_f)
		   {
			   result1=num1_f-num2_f;
		   }
		   else if(num2_f>num1_f)
		   {
			   result1=num2_f-num1_f;
			     Neg_Result_flag=1;// TO write Minus
		   }
	 }
	 return result1;
 }
 
 u64 MULTIPLICATION_DIVSION(u32 num1_f,u32 num2_f)
 {
	 u64 result1=0;
	  Neg_Result_flag=0;
	 if(Multi_flag==1)
	 {
		 result1=num1_f*num2_f;
		 if(Neg_flag==1)
		 {
			 Neg_Result_flag=1;
		 }
	 }
	 else if(Div_flag==1)
	 {
		  result1=num1_f/num2_f;
		  if(Neg_flag==1)
		  {
			  Neg_Result_flag=1;
		  }
	 }
	 return result1;
 }
 
 void RESET(void)
 {
	 x=0;
	flag_op=0;
	Neg_flag=0;
	Pos_flag=0;
	Neg_flag_first=0;
	Multi_flag=0;
	Div_flag=0;
	result=0;
	num=0;
	num2=0;
	flag_another_op=0;
 }