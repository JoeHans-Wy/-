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

unsigned char LEDNum;
void main()
{
	P2=0xFE;
	while(1)
	{
		if(RXD==0)
		{
			Delay(20);
			while(RXD==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
				LEDNum=0;
			P2=~(0x01<<LEDNum);
		}
		
		if(TXD==0)
		{
			Delay(20);
			while(TXD==0);
			Delay(20);
			
			if(LEDNum==0)
			{
				LEDNum=7;
			}
			else 
			{
				LEDNum--;
			}
				
			P2=~(0x01<<LEDNum);
		}
	}
}