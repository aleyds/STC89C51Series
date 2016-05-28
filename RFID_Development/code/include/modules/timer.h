#ifndef __STC90C52AD_TIMER_H__
#define __STC90C52AD_TIMER_H__

#define T1MAX0		(8192)	//������ʽ0
#define T1MAX1		(65536)  //������ʽ1
#define T1MAX2		(256)	//������ʽ2
#define T1MS(ms)	(T1MAX1-(FOSC/12/(ms*1000)))	

enum {
	_TYPE_TIMER_0 = 0,
	_TYPE_TIMER_1,
	_TYPE_TIMER_2,
};

typedef void (*TimerCallback)(void);
/*
	������ʱ��
	_Number: ��ʱ�����   ֧��0 1 2 ����оƬ�ڲ���ʱ��
	_TimeOut: ��ʱ����ʱ�ж�ʱ�� ms
	_Call:��ʱ����ʱ�жϴ�����
*/
H_U32 _TimerCreat(H_U8 _Number, H_U32 _TimeOut, TimerCallback _Call);

/*
	������ʱ��
	_Number:������ʱ���ı��
*/
H_U32 _TimerStart(H_U8 _Number);

/*
	�رն�ʱ��
*/
H_U32 _TimerClose(H_U8 _Number);

#endif