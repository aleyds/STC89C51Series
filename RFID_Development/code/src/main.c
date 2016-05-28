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

//单片机系统初始化
static void __SystemInit(void)
{
		//外部中断0 配置
		IT0 = 0; //外部中断低电平触发  IT0 = 1 外部中断0下降沿触发
		EX0 = 1; //打开外部中断0  EX0=0;关闭外部中断0
	 //外部中断1 配置
		IT1 = 0; //外部中断低电平触发  IT1 = 1 外部中断1下降沿触发
		EX1 = 1; //打开外部中断1  EX1=0;关闭外部中断1
	
		EA = 1;	//总中断开关
}

//外灯开启或关闭
static void __ExternalLED(H_U8 _Status)
{
	if(!_Status)
	{
		//TODO:外灯关闭
		EXTERNAL_LED=0;
	}else
	{
		//TODO:外灯开启
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
		_TimerClose(0);//关闭外灯后关闭定时器
	}
}

static void __MotorStop(void)
{
	//开启15分钟定时器
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

