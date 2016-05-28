#ifndef __STC90C52AD_TIMER_H__
#define __STC90C52AD_TIMER_H__

#define T1MAX0		(8192)	//工作方式0
#define T1MAX1		(65536)  //工作方式1
#define T1MAX2		(256)	//工作方式2
#define T1MS(ms)	(T1MAX1-(FOSC/12/(ms*1000)))	

enum {
	_TYPE_TIMER_0 = 0,
	_TYPE_TIMER_1,
	_TYPE_TIMER_2,
};

typedef void (*TimerCallback)(void);
/*
	创建定时器
	_Number: 定时器编号   支持0 1 2 三个芯片内部定时器
	_TimeOut: 定时器超时中断时间 ms
	_Call:定时器超时中断处理函数
*/
H_U32 _TimerCreat(H_U8 _Number, H_U32 _TimeOut, TimerCallback _Call);

/*
	启动定时器
	_Number:启动定时器的编号
*/
H_U32 _TimerStart(H_U8 _Number);

/*
	关闭定时器
*/
H_U32 _TimerClose(H_U8 _Number);

#endif