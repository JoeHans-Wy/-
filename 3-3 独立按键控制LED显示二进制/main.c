#include <REGX52.H>

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{
			i = 2;
			j = 199;
			do
			{
				while (--j);
			} while (--i);
	}
	
}

void main()
{
	unsigned char LEDNum=0;//直接操作P2会有数据溢出的风险
	while(1)
	{
		if(TXD==0)
		{
			Delay(20);
			while(TXD==0);
			Delay(20);
			
			LEDNum++;
			P2=~LEDNum;
		}
	}
}
