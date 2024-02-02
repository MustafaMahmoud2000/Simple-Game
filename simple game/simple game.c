/*
 * simple_game.c
 *
 * Created: 11/17/2023 1:37:30 AM
 *  Author: Mustafa mahmoud saad
 */ 
#include "Timre.h"
#include "LCD 8BIT.h"
#include "keybad.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
volatile unsigned short counter=0 ,counter1=0 ,counter2=0;
volatile unsigned char flag=0;
unsigned char flag1=0;
unsigned char flag2=0;
unsigned char flag3=0;
unsigned char flag4=0;
int main(void)
{
	int value_read;
	LCD_INIT();
	TIMER_CTC_INIT();
	keybad_vinit();
	LCD_MOVE_CURSOR(1,5);
    LCD_SEND_STRING("Welcome");
	LCD_MOVE_CURSOR(2,3);
	LCD_SEND_STRING("Simple Game");
	_delay_ms(1000);
  L1:LCD_clear_screen();
	LCD_SEND_STRING("1-Test1  2-Test2 ");
	LCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("3-Test3  4-Test4 ");
	//_delay_ms(800);
	while(1)
	 {
	   value_read=notpassed;
       value_read=keybad_u8read_press();
	   //_delay_ms(30);
	  // counter=0;
	 if (value_read == '1' && flag1==0)
	 {
		// counter=0;
	    if (value_read == '1')
		{
		flag1=1;
		counter=0;
		LCD_clear_screen();
		LCD_MOVE_CURSOR(1,4);
		LCD_SEND_STRING("Test(1)");
		_delay_ms(200);
		LCD_clear_screen();
		LCD_SEND_STRING("1) 3+..=10");
			do 
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read == notpassed && flag == 0);
		if(value_read == notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read == '7')
	   {
		  LCD_clear_screen();
		  LCD_MOVE_CURSOR(2,4);
		  LCD_SEND_STRING("well done");
		  counter1++;
	   }
	   else 
	   {
		   LCD_clear_screen();
		   LCD_MOVE_CURSOR(2,4);
		   LCD_SEND_STRING("wrong answer");
		   counter2++;
	   }
	   _delay_ms(150);
	   counter =0;
	   flag =0;
	   LCD_clear_screen();
	   LCD_SEND_STRING("2) 13-..=10");
	   _delay_ms(100);
	   do
	   {
		   if (counter >= 200)
		   {
			   flag=1;
		   }
		   value_read=keybad_u8read_press();
	   } while (value_read == notpassed && flag == 0);
	   if (value_read == notpassed)
	   {
		   LCD_clear_screen();
		   LCD_MOVE_CURSOR(2,4);
		   LCD_SEND_STRING("time over");
		   counter2++;
	   }
	   else if (value_read=='3')
	   {
		   LCD_clear_screen();
		   LCD_MOVE_CURSOR(2,4);
		   LCD_SEND_STRING("well done");
			 counter1++;
	   }
	   else
	   {
		   LCD_clear_screen();
		   LCD_MOVE_CURSOR(2,4);
		   LCD_SEND_STRING("wrong answer");
		   counter2++;
	   }
	   _delay_ms(150);
	   counter = 0;
	   flag = 0;
	   LCD_clear_screen();
	   LCD_SEND_STRING("3) 2*..=10");
	   _delay_ms(100);
	   do
	   {
		   if (counter >= 200)
		   {
			   flag=1;
		   }
		   value_read=keybad_u8read_press();
	   } while (value_read == notpassed && flag == 0);
	   if (value_read==notpassed)
	   {
		   LCD_clear_screen();
		   LCD_MOVE_CURSOR(2,4);
		   LCD_SEND_STRING("time over");
		   counter2++;
	   }
	   else if (value_read =='5')
	   {
		   LCD_clear_screen();
		   LCD_MOVE_CURSOR(2,4);
		   LCD_SEND_STRING("well done");
			 counter1++;
	   }
	   else
	   {
		   LCD_clear_screen();
		   LCD_MOVE_CURSOR(2,4);
		   LCD_SEND_STRING("wrong answer");
		   counter2++;
	   }
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("4) 50/..=10");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read =='5')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		 counter=0;
		 flag=0;
		 LCD_clear_screen();
		 LCD_SEND_STRING("5) 14%..=0");
		 _delay_ms(100);
		 do
		 {
			 if (counter>=200)
			 {
				 flag=1;
			 }
			 value_read=keybad_u8read_press();
		 } while (value_read==notpassed && flag==0);
		 if (value_read==notpassed)
		 {
			 LCD_clear_screen();
			 LCD_MOVE_CURSOR(2,4);
			 LCD_SEND_STRING("time over");
			 counter2++;
		 }
		 else if (value_read=='7')
		 {
			 LCD_SEND_CHAR(value_read);
			 LCD_clear_screen();
			 LCD_MOVE_CURSOR(2,4);
			 LCD_SEND_STRING("well done");
			 counter1++;
		 }
		 else
		 {
			 LCD_clear_screen();
			 LCD_MOVE_CURSOR(2,4);
			 LCD_SEND_STRING("wrong answer");
			 counter2++;
		 }
		 _delay_ms(150);
		  counter=0;
		  flag=0;
		  LCD_clear_screen();
		  LCD_SEND_STRING("6) 50+4+...=60");
		  _delay_ms(100);
		  do
		  {
			  if (counter>=200)
			  {
				  flag=1;
			  }
			  value_read=keybad_u8read_press();
		  } while (value_read==notpassed && flag==0);
		  if (value_read==notpassed)
		  {
			  LCD_clear_screen();
			  LCD_MOVE_CURSOR(2,4);
			  LCD_SEND_STRING("time over");
			  counter2++;
		  }
		  else if (value_read=='6')
		  {
			  LCD_SEND_CHAR(value_read);
			  LCD_clear_screen();
			  LCD_MOVE_CURSOR(2,4);
			  LCD_SEND_STRING("well done");
			  counter1++;
		  }
		  else
		  {
			  LCD_clear_screen();
			  LCD_MOVE_CURSOR(2,4);
			  LCD_SEND_STRING("wrong answer");
			  counter2++;
		  }
		   _delay_ms(150);
		   counter=0;
		   flag=0;
		   LCD_clear_screen();
		   LCD_SEND_STRING("7) 50*2+...=108");
		   _delay_ms(100);
		   do
		   {
			   if (counter>=200)
			   {
				   flag=1;
			   }
			   value_read=keybad_u8read_press();
		   } while (value_read==notpassed && flag==0);
		   if (value_read==notpassed)
		   {
			   LCD_clear_screen();
			   LCD_MOVE_CURSOR(2,4);
			   LCD_SEND_STRING("time over");
			   counter2++;
		   }
		   else if (value_read=='8')
		   {
			   LCD_SEND_CHAR(value_read);
			   LCD_clear_screen();
			   LCD_MOVE_CURSOR(2,4);
			   LCD_SEND_STRING("well done");
			   counter1++;
		   }
		   else
		   {
			   LCD_clear_screen();
			   LCD_MOVE_CURSOR(2,4);
			   LCD_SEND_STRING("wrong answer");
			   counter2++;
		   }
		   _delay_ms(150);
		   counter=0;
		   flag=0;
		   LCD_clear_screen();
		   LCD_SEND_STRING("8) 14+4-1*...=14");
		   _delay_ms(100);
		   do
		   {
			   if (counter>=200)
			   {
				   flag=1;
			   }
			   value_read=keybad_u8read_press();
		   } while (value_read==notpassed && flag==0);
		   if (value_read==notpassed)
		   {
			   LCD_clear_screen();
			   LCD_MOVE_CURSOR(2,4);
			   LCD_SEND_STRING("time over");
			   counter2++;
		   }
		   else if (value_read=='4')
		   {
			   LCD_SEND_CHAR(value_read);
			   LCD_clear_screen();
			   LCD_MOVE_CURSOR(2,4);
			   LCD_SEND_STRING("well done");
			   counter1++;
		   }
		   else
		   {
			   LCD_clear_screen();
			   LCD_MOVE_CURSOR(2,4);
			   LCD_SEND_STRING("wrong answer");
			   counter2++;
		   }
			_delay_ms(150);
			counter=0;
			flag=0;
			LCD_clear_screen();
			LCD_SEND_STRING("9) 1*4+10/...=9");
			_delay_ms(100);
			do
			{
				if (counter>=200)
				{
					flag=1;
				}
				value_read=keybad_u8read_press();
			} while (value_read==notpassed && flag==0);
			if (value_read==notpassed)
			{
				LCD_clear_screen();
				LCD_MOVE_CURSOR(2,4);
				LCD_SEND_STRING("time over");
				counter2++;
			}
			else if (value_read=='2')
			{
				LCD_SEND_CHAR(value_read);
				LCD_clear_screen();
				LCD_MOVE_CURSOR(2,4);
				LCD_SEND_STRING("well done");
				counter1++;
			}
			else
			{
				LCD_clear_screen();
				LCD_MOVE_CURSOR(2,4);
				LCD_SEND_STRING("wrong answer");
				counter2++;
			}
			 _delay_ms(150);
			 counter=0;
			 flag=0;
			 LCD_clear_screen();
			 LCD_SEND_STRING("10) 14-4/1+..=10");
			 _delay_ms(100);
			 do
			 {
				 if (counter>=200)
				 {
					 flag=1;
				 }
				 value_read=keybad_u8read_press();
			 } while (value_read==notpassed && flag==0);
			 if (value_read==notpassed)
			 {
				 LCD_clear_screen();
				 LCD_MOVE_CURSOR(2,4);
				 LCD_SEND_STRING("time over");
				 counter2++;
			 }
			 else if (value_read=='0')
			 {
				 LCD_SEND_CHAR(value_read);
				 LCD_clear_screen();
				 LCD_MOVE_CURSOR(2,4);
				 LCD_SEND_STRING("well done");
				 counter1++;
			 }
			 else
			 {
				 LCD_clear_screen();
				 LCD_MOVE_CURSOR(2,4);
				 LCD_SEND_STRING("wrong answer");
				 counter2++;
			 }
			_delay_ms(150);
			 LCD_clear_screen();
			LCD_SEND_STRING("the correct=");
			LCD_MOVE_CURSOR(1,13);
			LCD_SEND_CHAR(counter1+48);
			LCD_MOVE_CURSOR(2,1);
			LCD_SEND_STRING("the wrong=");
			LCD_MOVE_CURSOR(2,11);
			LCD_SEND_CHAR(counter2+48);
			_delay_ms(800);
			LCD_clear_screen();
			if(counter1>counter2)
			{
			counter=0;
			counter1=0;
			counter2=0;
			LCD_SEND_STRING("succed");
			_delay_ms(150);
			LCD_clear_screen();
			LCD_SEND_STRING("up to test(2)");	
			_delay_ms(200);
			LCD_clear_screen();
			}
			else
			{
				flag1=0;
				LCD_MOVE_CURSOR(1,5);
				LCD_SEND_STRING("failed");
				LCD_MOVE_CURSOR(2,4);
				LCD_SEND_STRING("Try again");
				_delay_ms(400);
			}
			goto L1;		
		}
	}	
		
		
		
		
			
		
		else if (value_read == '2' )
		{
			//counter=0;
			if (value_read == '2'&& flag1==1)
			{
				counter=0;
				LCD_clear_screen();
				LCD_MOVE_CURSOR(1,4);
				LCD_SEND_STRING("Test(2)");
				_delay_ms(200);
				LCD_clear_screen();
				LCD_SEND_STRING("1) 3+5*2-..=10");
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='3')
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("2)16*2/4+..=10");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='2')
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("3)4+3*3-5+..=14");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='6')
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("4)50/5+2*4-..=9");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='9')
				{
					LCD_SEND_CHAR(value_read);
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("5) 7+22*2-42=..");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='9')
				{
					LCD_SEND_CHAR(value_read);
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("6) 8/4+3*6+..=25");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='5')
				{
					LCD_SEND_CHAR(value_read);
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("7) 50*2/25+4=..");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='8')
				{
					LCD_SEND_CHAR(value_read);
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("8)14/2-1+9-..=14");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='1')
				{
					LCD_SEND_CHAR(value_read);
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("9)4*6/2-8+..=9");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag == 0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='5')
				{
					LCD_SEND_CHAR(value_read);
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				counter=0;
				flag=0;
				LCD_clear_screen();
				LCD_SEND_STRING("10)4+6-4*2+..=10");
				_delay_ms(100);
				do
				{
					if (counter>=200)
					{
						flag=1;
					}
					value_read=keybad_u8read_press();
				} while (value_read==notpassed && flag==0);
				if (value_read==notpassed)
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("time over");
					counter2++;
				}
				else if (value_read=='8')
				{
					LCD_SEND_CHAR(value_read);
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("well done");
					counter1++;
				}
				else
				{
					LCD_clear_screen();
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("wrong answer");
					counter2++;
				}
				_delay_ms(150);
				LCD_clear_screen();
				LCD_SEND_STRING("the correct=");
				LCD_MOVE_CURSOR(1,13);
				LCD_SEND_CHAR(counter1+48);
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("the wrong=");
				LCD_MOVE_CURSOR(2,11);
				LCD_SEND_CHAR(counter2+48);
				_delay_ms(800);
				LCD_clear_screen();
				if (counter1>counter2)
				{
		
					LCD_SEND_STRING("succed");
					_delay_ms(150);	
					LCD_clear_screen();
					LCD_SEND_STRING("up to test(3)");
					_delay_ms(200);
					flag2=1;
				}
				else
				{
					LCD_MOVE_CURSOR(1,5);
					LCD_SEND_STRING("failed");
					LCD_MOVE_CURSOR(2,4);
					LCD_SEND_STRING("Try again");
					_delay_ms(400);
					flag1=0;
				}
				goto L1;
     	}
		 else
		 {
			 LCD_clear_screen();
			 LCD_SEND_STRING("  Test2 locked  ");
			_delay_ms(700);
			LCD_clear_screen();
			 goto L1;
		 }
	}	






    else if (value_read == '3')
	{
		//counter=0;
		if (value_read == '3' &&  flag1==1 && flag2==1)
		{
		flag2=1;
		counter=0;
		LCD_clear_screen();
		LCD_MOVE_CURSOR(1,4);
		LCD_SEND_STRING("Test(3)");
		_delay_ms(200);
		LCD_clear_screen();
		LCD_SEND_STRING("1) 4+4*(7-6)+..=10");
		
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='2')
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("2) 8-6\(2+1)+..=10");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='4')
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("3) 2+(5*3)-9=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='8')
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("4) ((3*8+4)-3)\5=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='5')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("5) 14-2*6+5=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='7')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("6) 50\5+4*10-41=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='9')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("7) 50*2-190\2=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='5')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("8) 14*2-28=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='0')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("9) 3*4-10\2=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='7')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("10) 14-1*6+1=");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='9')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		LCD_clear_screen();
		LCD_SEND_STRING("the correct=");
		LCD_MOVE_CURSOR(1,13);
		LCD_SEND_CHAR(counter1+48);
		LCD_MOVE_CURSOR(2,1);
		LCD_SEND_STRING("the wrong=");
		LCD_MOVE_CURSOR(2,11);
		LCD_SEND_CHAR(counter2+48);
		_delay_ms(800);
		LCD_clear_screen();
		if(counter1>counter2)
		{
			counter=0;
			counter1=0;
			counter2=0;
			LCD_SEND_STRING("succed");
			_delay_ms(150);
			LCD_clear_screen();
			LCD_SEND_STRING("up to test(4)");
			_delay_ms(200);
			LCD_clear_screen();
			flag3=1;
			
		}
		else
		{
			flag2=0;
			LCD_MOVE_CURSOR(1,5);
			LCD_SEND_STRING("failed");
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("Try again");
			_delay_ms(400);
			
		}
		
		goto L1;		
	}	
	else
	{
		LCD_clear_screen();
		LCD_SEND_STRING("  Test3 locked  ");
		_delay_ms(700);
		LCD_clear_screen();
		goto L1;
	}
}
	
	
	
	
	else if (value_read == '4')
	{
		if (value_read=='4'&& flag1==1 && flag2==1 && flag3==1)
		{
		flag3=1;
		counter=0;
		LCD_clear_screen();
		LCD_MOVE_CURSOR(1,4);
		LCD_SEND_STRING("Test(4)");
		_delay_ms(200);
		LCD_clear_screen();
		LCD_SEND_STRING("1) 3+..=10");
		
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='7')
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("2) 13-..=10");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='3')
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("3) 2*..=10");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='5')
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("4) 50/..=10");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='5')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("5) 14%..=0");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='7')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("6) 50+4+...=60");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='6')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("7) 50*2+...=108");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='8')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("8) 14+4-1*...=14");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='4')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("9) 1*4+10/...=9");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='2')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		counter=0;
		flag=0;
		LCD_clear_screen();
		LCD_SEND_STRING("10) 14-4/1+..=10");
		_delay_ms(100);
		do
		{
			if (counter>=200)
			{
				flag=1;
			}
			value_read=keybad_u8read_press();
		} while (value_read==notpassed && flag==0);
		if (value_read==notpassed)
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("time over");
			counter2++;
		}
		else if (value_read=='0')
		{
			LCD_SEND_CHAR(value_read);
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("well done");
			counter1++;
		}
		else
		{
			LCD_clear_screen();
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("wrong answer");
			counter2++;
		}
		_delay_ms(150);
		LCD_clear_screen();
		LCD_SEND_STRING("the correct=");
		LCD_MOVE_CURSOR(1,13);
		LCD_SEND_CHAR(counter1+48);
		LCD_MOVE_CURSOR(2,1);
		LCD_SEND_STRING("the wrong=");
		LCD_MOVE_CURSOR(2,11);
		LCD_SEND_CHAR(counter2+48);
		_delay_ms(800);
		LCD_clear_screen();
		if(counter1>counter2)
		{
			counter=0;
			counter1=0;
			counter2=0;
			LCD_SEND_STRING("succed");
			_delay_ms(150);
			LCD_clear_screen();
		}
		else
		{
			flag2=0;
			LCD_MOVE_CURSOR(1,5);
			LCD_SEND_STRING("failed");
			LCD_MOVE_CURSOR(2,4);
			LCD_SEND_STRING("Try again");
			_delay_ms(400);
			
		}
		goto L1; 
  }
  else
  {
	  LCD_clear_screen();
	  LCD_SEND_STRING("  Test4 locked  ");
	  _delay_ms(700);
	  LCD_clear_screen();
	  goto L1;
  }
}  
} 	
} 

ISR(TIMER0_COMP_vect)
{
	counter++;
}