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
	unsigned char LEDNum=0;//ֱ�Ӳ���P2������������ķ���
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
