#include <REGX52.H>

void main()
{
	while(1)
	{
		if(TXD==0)
		{
			P2_0=0;
		}
		else
		{
			P2_0=1;
		}
	}
}