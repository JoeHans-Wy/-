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
		if(TXD==0)//����ʱ��Ϊ��,����Ϊһ
		{
			Delay(20);//�ų���Ƭ��ʱ����
			while(TXD==0);//����ʱһֱ���ָ�״̬,ֱ������
			Delay(20);//�ų���Ƭ���󶶶�
			
			P2_0=~P2_0;//ÿ�ΰ���ʱ��P2_0���Ƶ�LED��ƽȡ��
			//
		}
	}
}
