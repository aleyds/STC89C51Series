#ifndef __STC89C52_TFT_H__
#define __STC89C52_TFT_H__
#define TFT_RED			(0xF800)
#define TFT_BLUE		(0x001F)
#define TFT_GREEN		(0x07E0)
#define TFT_WHITE		(0xFFFF)
#define TFT_BLACK		(0x0000)

/*
	TFT 屏幕初始化函数
	参数:无
*/
void _TFTInit(void);

/*
	TFT 屏幕清除函数
	参数:_Color 指定颜色进行清除屏幕操作
*/
void _TFTClear(H_U32 _Color);

/*
	TFT 绘画矩阵函数
	参数:x,y (屏幕坐标点) ; xLen,yLen (横向纵向长度) ; _Color 绘画的颜色值  
*/
void _TFTDrawMatrix(H_U8 x, H_U8 y, H_U8 xLen, H_U8 yLen, H_U32 _Color);

/*
	TFT 画点函数
	参数: x,y (屏幕坐标点)  _Color 绘画颜色
*/
void _TFTDrawPixel(H_U8 x, H_U8 y, H_U32 _Color);

/*
	TFT绘画水平线
	参数：x,y(水平线起点坐标)  _Len 水平线长度  _Color 水平线颜色
*/
void _TFTDrawHLine(H_U8 x, H_U8 y, H_U8 _Len, H_U32 _Color);

/*
	TFT 绘画竖直线
	参数: x,y (竖直线起点坐标)  _Len 竖直线长度  _Color 竖直线颜色
*/
void _TFTDrawVLine(H_U8 x, H_U8 y, H_U8 _Len, H_U32 _Color);

/*
	TFT 显示ASCII码，显示值为:20H-7FH (其他值显示'')
	参数:x,y (显示坐标) ;_Char 显示字符 ; _Color 显示颜色  ; _ColorB 显示背景颜色
*/
void _TFTDrawChar(H_U8 x, H_U8 y, H_U8 _Char, H_U32 _Color, H_U32 _ColorB);

/*
	TFT 显示字符串
	参数:x,y (显示坐标)  _pStr 显示的字符串   _Color:字符串颜色  _ColorB 背景颜色
*/
void _TFTDrawString(H_U8 x, H_U8 y, const H_U8 *_pStr, H_U32 _Color, H_U32 _ColorB);

/*
	TFT 显示图片
	参数: x,y (显示图片的起始位置)  _xLen, _yLen (显示的图片大小)  _pPicDat 显示图片数据
*/
void _TFTDrawPic(H_U8 x, H_U8 y, H_U8 _xLen, H_U8 _yLen, const H_U8 *_pPicDat);


/*
	TFT　显示模块数据发送
	参数:_SendDat 发送1Byte 数据
*/
H_BOOL _TFTWriteDat(H_U8 _SendDat);

/*
	TFT 发送寄存器命令
	参数：_SendCMD 发送指令字节
*/
H_BOOL _TFTWriteCMD(H_U8 _SendCMD);

#endif
