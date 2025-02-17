#include <REGX52.H>

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
			i = 2;
			j = 199;
			do
			{
				while (--j);
			} while (--i);
			xms--;
	}
	
}


void main()
{
	while(1)
	{
		if(TXD==0)//按键时即为零,松手为一
		{
			Delay(20);//排除垫片按时抖动
			while(TXD==0);//按键时一直保持该状态,直到松手
			Delay(20);//排除垫片按后抖动
			
			P2_0=~P2_0;//每次按键时将P2_0控制的LED电平取反
			//
		}
	}
}
