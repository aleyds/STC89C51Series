#include "base_type.h"
#define "platform.h"


void _TFTInit(void);

void _TFTClear(H_U32 _Color);

void _TFTDrawMatrix(H_U8 x, H_U8 y, H_U8 xLen, H_U8 yLen, H_U32 _Color);

void _TFTDrawPixel(H_U8 x, H_U8 y, H_U32 _Color);

void _TFTDrawHLine(H_U8 x, H_U8 y, H_U8 _Len, H_U32 _Color);

void _TFTDrawVLine(H_U8 x, H_U8 y, H_U8 _Len, H_U32 _Color);

void _TFTDrawChar(H_U8 x, H_U8 y, H_U8 _Char, H_U32 _Color, H_U32 _ColorB);

void _TFTDrawString(H_U8 x, H_U8 y, const H_U8 *_pStr, H_U32 _Color, H_U32 _ColorB);

void _TFTDrawPic(H_U8 x, H_U8 y, H_U8 _xLen, H_U8 _yLen, const H_U8 *_pPicDat);

H_BOOL _TFTWriteDat(H_U8 _SendDat);

H_BOOL _TFTWriteCMD(H_U8 _SendCMD);