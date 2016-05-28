#ifndef __STC89C52_TFT_H__
#define __STC89C52_TFT_H__
#define TFT_RED			(0xF800)
#define TFT_BLUE		(0x001F)
#define TFT_GREEN		(0x07E0)
#define TFT_WHITE		(0xFFFF)
#define TFT_BLACK		(0x0000)

/*
	TFT ��Ļ��ʼ������
	����:��
*/
void _TFTInit(void);

/*
	TFT ��Ļ�������
	����:_Color ָ����ɫ���������Ļ����
*/
void _TFTClear(H_U32 _Color);

/*
	TFT �滭������
	����:x,y (��Ļ�����) ; xLen,yLen (�������򳤶�) ; _Color �滭����ɫֵ  
*/
void _TFTDrawMatrix(H_U8 x, H_U8 y, H_U8 xLen, H_U8 yLen, H_U32 _Color);

/*
	TFT ���㺯��
	����: x,y (��Ļ�����)  _Color �滭��ɫ
*/
void _TFTDrawPixel(H_U8 x, H_U8 y, H_U32 _Color);

/*
	TFT�滭ˮƽ��
	������x,y(ˮƽ���������)  _Len ˮƽ�߳���  _Color ˮƽ����ɫ
*/
void _TFTDrawHLine(H_U8 x, H_U8 y, H_U8 _Len, H_U32 _Color);

/*
	TFT �滭��ֱ��
	����: x,y (��ֱ���������)  _Len ��ֱ�߳���  _Color ��ֱ����ɫ
*/
void _TFTDrawVLine(H_U8 x, H_U8 y, H_U8 _Len, H_U32 _Color);

/*
	TFT ��ʾASCII�룬��ʾֵΪ:20H-7FH (����ֵ��ʾ'')
	����:x,y (��ʾ����) ;_Char ��ʾ�ַ� ; _Color ��ʾ��ɫ  ; _ColorB ��ʾ������ɫ
*/
void _TFTDrawChar(H_U8 x, H_U8 y, H_U8 _Char, H_U32 _Color, H_U32 _ColorB);

/*
	TFT ��ʾ�ַ���
	����:x,y (��ʾ����)  _pStr ��ʾ���ַ���   _Color:�ַ�����ɫ  _ColorB ������ɫ
*/
void _TFTDrawString(H_U8 x, H_U8 y, const H_U8 *_pStr, H_U32 _Color, H_U32 _ColorB);

/*
	TFT ��ʾͼƬ
	����: x,y (��ʾͼƬ����ʼλ��)  _xLen, _yLen (��ʾ��ͼƬ��С)  _pPicDat ��ʾͼƬ����
*/
void _TFTDrawPic(H_U8 x, H_U8 y, H_U8 _xLen, H_U8 _yLen, const H_U8 *_pPicDat);


/*
	TFT����ʾģ�����ݷ���
	����:_SendDat ����1Byte ����
*/
H_BOOL _TFTWriteDat(H_U8 _SendDat);

/*
	TFT ���ͼĴ�������
	������_SendCMD ����ָ���ֽ�
*/
H_BOOL _TFTWriteCMD(H_U8 _SendCMD);

#endif
