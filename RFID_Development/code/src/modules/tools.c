#include "base_type.h"
#include "tools.h"

void _SystemReset(void)
{
	ISP_CONTR = 0x20;// ISP/IAP禁止读写  SWBS配置从用户场景启动  SWRST产生软件系统复位
}

void _SystemWDT(void)
{
	WDG_REGISTER=(WDT_ENABLE|WDT_CLEAR|WDT_IDLE|_WDT_SCALE64);
}
