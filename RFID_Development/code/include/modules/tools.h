#ifndef __STC90C52AD_TOOLS_H__
#define __STC90C52AD_TOOLS_H__

//ø¥√≈π∑∏¥Œª
#define WDT_ENABLE		(0x20)
#define WDT_CLEAR		(0x10)
#define WDT_IDLE		(0x08)
enum{
	_WDT_SCALE2 = 0x0,
	_WDT_SCALE4,
	_WDT_SCALE8,
	_WDT_SCALE16,
	_WDT_SCALE32,
	_WDT_SCALE64,
	_WDT_SCALE128,
	_WDT_SCALE256,
};

void _SystemReset(void);
void _SystemWDT(void);
#endif
