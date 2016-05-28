#include "base_type.h"
#include <platform.h>
#include "intrins.h"
#include "adc.h"
#include "timer.h"

#define TIME_15MIN		(15*60*1000)

static void __Delay(H_U32 ms)
{
	H_U32 i = 0;
	H_U32 j = 0;
	for(i = ms; i> 0; i--)
	{
		for(j = 110; j > 0; j--)
		{
			_nop_();
		}
	}
}

//��Ƭ��ϵͳ��ʼ��
static void __SystemInit(void)
{
		//�ⲿ�ж�0 ����
		IT0 = 0; //�ⲿ�жϵ͵�ƽ����  IT0 = 1 �ⲿ�ж�0�½��ش���
		EX0 = 1; //���ⲿ�ж�0  EX0=0;�ر��ⲿ�ж�0
	 //�ⲿ�ж�1 ����
		IT1 = 0; //�ⲿ�жϵ͵�ƽ����  IT1 = 1 �ⲿ�ж�1�½��ش���
		EX1 = 1; //���ⲿ�ж�1  EX1=0;�ر��ⲿ�ж�1
	
		EA = 1;	//���жϿ���
}

//��ƿ�����ر�
static void __ExternalLED(H_U8 _Status)
{
	if(!_Status)
	{
		//TODO:��ƹر�
		EXTERNAL_LED=0;
	}else
	{
		//TODO:��ƿ���
		EXTERNAL_LED=1;
	}
}

static void __Timer0Callback(void)
{
	//TODO:
	if(!EXTERNAL_LED)
	{
		__ExternalLED(H_TRUE);
	}else 
	{
		__ExternalLED(H_FAUSE);
		_TimerClose(0);//�ر���ƺ�رն�ʱ��
	}
}

static void __MotorStop(void)
{
	//����15���Ӷ�ʱ��
	_TimerCreat(0, TIME_15MIN, __Timer0Callback);
	_TimerStart(0);
	
}

void main()
{
		__SystemInit();
		_ADCInit();
		while(1)
		{
			
		}
}

