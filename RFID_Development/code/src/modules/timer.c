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
			TR0 = 0;//先关闭定时器0
			TMOD = 0x01;//定时器工作在方式1
			TH0 = (T1MS(1)>>8); //设置定时器0初值 5ms
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
			ET0=1;//开启定时器0中断
			TR0=1;//开启定时器0
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
			ET0=0;//关闭定时器0中断
			TR0=0;//关闭定时器0
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

//定时器0中断回调函数
void Timer0_IRQHandler(void) interrupt 1 using 1
{
	TimerManage_t* _Manage = __TimerManage();
	TH0 = (T1MS(1)>>8); //从新装入初值
	TL0 = T1MS(1);
	if(_Manage->_Timer0._TimeCount >= _Manage->_Timer0._TimeInit)
	{
		_Manage->_Timer0._TimeCount = 0;//从新设置COUNTER
		if(_Manage->_Timer0._Call != H_NULL)
		{
			_Manage->_Timer0._Call();//执行Timer回调函数
		}
	}
	_Manage->_Timer0._TimeCount++;
}
