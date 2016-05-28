#include "base_type.h"
#include "timer.h"

typedef struct TimerSt{
	H_U32 _TimeInit;
	H_U32 _TimeCount;
	TimerCallback _Call;
}TimerSt_t;

typedef struct TimerManage{
	TimerSt_t _Timer0;
}TimerManage_t;

static TimerManage_t g_TimerManage;
static TimerManage_t* __TimerManage(void)
{
	return (TimerManage_t *)&g_TimerManage;
}

H_U32 _TimerCreat(H_U8 _Number, H_U32 _TimeOut, TimerCallback _Call)
{
	TimerManage_t* _Manage = __TimerManage();
	switch(_Number)
	{
		case _TYPE_TIMER_0:
			TR0 = 0;//�ȹرն�ʱ��0
			TMOD = 0x01;//��ʱ�������ڷ�ʽ1
			TH0 = (T1MS(1)>>8); //���ö�ʱ��0��ֵ 5ms
			TL0 = T1MS(1);
			_Manage->_Timer0._TimeInit = _TimeOut;
			_Manage->_Timer0._TimeCount = 0;
			_Manage->_Timer0._Call = _Call;
			break;
		default:
			break;
	}
	return H_SUCCESS;
}

H_U32 _TimerStart(H_U8 _Number)
{
	switch(_Number)
	{
		case _TYPE_TIMER_0:
			ET0=1;//������ʱ��0�ж�
			TR0=1;//������ʱ��0
			break;
		case 
		default:
			break;
	}
	return H_SUCCESS;
}

H_U32 _TimerClose(H_U8 _Number)
{
	switch(_Number)
	{
		case _TYPE_TIMER_0:
			ET0=0;//�رն�ʱ��0�ж�
			TR0=0;//�رն�ʱ��0
			break;
		case _TYPE_TIMER_1:
			break;
		case _TYPE_TIMER_2:
			break;
		default:
			break;
	}
	return H_SUCCESS;
}

//��ʱ��0�жϻص�����
void Timer0_IRQHandler(void) interrupt 1 using 1
{
	TimerManage_t* _Manage = __TimerManage();
	TH0 = (T1MS(1)>>8); //����װ���ֵ
	TL0 = T1MS(1);
	if(_Manage->_Timer0._TimeCount >= _Manage->_Timer0._TimeInit)
	{
		_Manage->_Timer0._TimeCount = 0;//��������COUNTER
		if(_Manage->_Timer0._Call != H_NULL)
		{
			_Manage->_Timer0._Call();//ִ��Timer�ص�����
		}
	}
	_Manage->_Timer0._TimeCount++;
}
