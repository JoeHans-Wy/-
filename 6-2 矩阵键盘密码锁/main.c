#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int PassWord,Count;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)											//如果是S1~S10按键按下,输入密码
			{
				if(Count<4)												//判断输入次数
				{
					PassWord*=10;										//密码左移
					PassWord+=KeyNum%10;						//获取一位密码
				}
				Count++;
				LCD_ShowNum(2,1,PassWord,4);			//更新显示
			}
			if(KeyNum==11)											//如果S11按键按下,为确认键
			{
				if(PassWord==4399)
				{
					LCD_ShowString(1,14,"OK!");			//密码正确时输出OK!
					PassWord=0;											//清零密码和次数
					Count=0;
					LCD_ShowNum(2,1,PassWord,4);		
				}
				else
				{
					LCD_ShowString(1,14,"ERR");			//密码错误时输出ERR
					PassWord=0;											//清零密码和次数
					Count=0;
					LCD_ShowNum(2,1,PassWord,4);
				}
			}
			if(KeyNum==12)											//如果S12按键按下,为取消键	
			{
				PassWord=(int)PassWord/10;				//已输入的密码右移一位
				Count--;													//判断输入次数减一
				LCD_ShowNum(2,1,PassWord,4);			//更新已输入密码显示
			}
		}
	}
	
}
	