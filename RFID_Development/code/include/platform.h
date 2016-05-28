#ifndef __PLATFOEM_H__
#define __PLATFOEM_H__
#include "REG51.H"
#define STC90C52AD

#ifdef STC90C52AD
#define FOSC		(16000000L) //16M 芯片晶振大小Hz
sfr WDG_REGISTER=0xe1;//看门狗
sfr ISP_CONTR=0xe7; //ISP/IAP功能及软件复位

//微动开关
sbit M_SWITCH1=P0^2;//A点1号微动开关
sbit M_SWITCH2=P0^3;//B点2号微动开关
sbit M_SWITCH3=P0^4;//C点3号微动开关
sbit T_SWITCH =P0^6;//触摸开关

//LED
sbit EXTERNAL_LED=P2^0;
sbit SWITCH1_LED=P2^1;//1号微动开关显示灯，离开开关时LED点亮  接触1号开关时LED熄灭
sbit SWITCH2_LED=P2^2;

//继电器开关
sbit RELAY_A = P2^0;
sbit RELAY_B = P2^1;

//ADC寄存器
sfr P1_ADC_EN = 0x97; // P1口模拟配置寄存器，配置对应的端口为ADC输入口
sfr ADC_CONTER = 0xC5; //ADC 控制寄存器
sfr ADC_DATA_HIGHT = 0xC6; //ADC 转换结果，10位高8位数据
sfr ADC_DATA_LOW = 0xC7; //ADC 转换结果，10位数据的低2位
#endif

#endif