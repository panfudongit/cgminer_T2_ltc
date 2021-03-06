
#include <stdlib.h>
#include <string.h>
#include "logging.h"
#include "miner.h"

const uint8_t default_reg[][12] =
{	
	{ 0x02, 0x50, 0x40, 0xc2, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0120MHz, VCO=0960MHz

	{ 0x07, 0x04, 0x40, 0xc2, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0130MHz, VCO=1040MHz

	{ 0x07, 0x18, 0x40, 0xc2, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0140MHz, VCO=1120MHz

	{ 0x07, 0x2c, 0x40, 0xc2, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0150MHz, VCO=1200MHz

	{ 0x07, 0x40, 0x40, 0xc2, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0160MHz, VCO=1280MHz

	{ 0x07, 0x54, 0x40, 0xc2, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0170MHz, VCO=1360MHz

	{ 0x0d, 0x68, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0180MHz, VCO=0720MHz

	{ 0x0d, 0x7c, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0190MHz, VCO=0760MHz

	{ 0x0d, 0x90, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0200MHz, VCO=0800MHz

	{ 0x0d, 0xb0, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0216MHz, VCO=0864MHz

	{ 0x0d, 0xce, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0231MHz, VCO=0924MHz

	{ 0x0d, 0xec, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0246MHz, VCO=0984MHz

	{ 0x07, 0x04, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0260MHz, VCO=1040MHz

	{ 0x07, 0x14, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0276MHz, VCO=1104MHz

	{ 0x07, 0x22, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0290MHz, VCO=1160MHz

	{ 0x07, 0x36, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0310MHz, VCO=1240MHz

	{ 0x07, 0x4a, 0x40, 0x82, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0330MHz, VCO=1320MHz

	{ 0x08, 0xea, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0351MHz, VCO=0702MHz

	{ 0x08, 0xf8, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0372MHz, VCO=0744MHz

	{ 0x09, 0x0c, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0402MHz, VCO=0804MHz

	{ 0x09, 0x20, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0432MHz, VCO=0864MHz

	{ 0x09, 0x36, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0465MHz, VCO=0930MHz

	{ 0x09, 0x48, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0492MHz, VCO=0984MHz

	{ 0x09, 0x62, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0531MHz, VCO=1062MHz

	{ 0x09, 0x80, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0576MHz, VCO=1152MHz

	{ 0x09, 0x9c, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0618MHz, VCO=1236MHz

	{ 0x09, 0xb8, 0x40, 0x42, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0660MHz, VCO=1320MHz

	{ 0x08, 0xee, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0714MHz, VCO=0714MHz

	{ 0x09, 0x04, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0780MHz, VCO=0780MHz

	{ 0x09, 0x18, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0840MHz, VCO=0840MHz

	{ 0x09, 0x2c, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0900MHz, VCO=0900MHz

	{ 0x09, 0x40, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0960MHz, VCO=0960MHz

	{ 0x09, 0x44, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0972MHz, VCO=0972MHz
	{ 0x09, 0x46, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0978MHz, VCO=0978MHz
	{ 0x09, 0x48, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0984MHz, VCO=0984MHz
	{ 0x09, 0x4a, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0990MHz, VCO=0990MHz
	{ 0x09, 0x4c, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=0996MHz, VCO=0996MHz
	{ 0x09, 0x4e, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1002MHz, VCO=1002MHz
	{ 0x09, 0x50, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1008MHz, VCO=1008MHz
	{ 0x09, 0x52, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1014MHz, VCO=1014MHz
	{ 0x09, 0x54, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1020MHz, VCO=1020MHz
	{ 0x09, 0x56, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1026MHz, VCO=1026MHz
	{ 0x09, 0x58, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1032MHz, VCO=1032MHz
	{ 0x09, 0x5a, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1038MHz, VCO=1038MHz
	{ 0x09, 0x5c, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1044MHz, VCO=1044MHz
	{ 0x09, 0x5e, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1050MHz, VCO=1050MHz
	{ 0x09, 0x60, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1056MHz, VCO=1056MHz
	{ 0x09, 0x62, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1062MHz, VCO=1062MHz
	{ 0x09, 0x64, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1068MHz, VCO=1068MHz
	{ 0x09, 0x66, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1074MHz, VCO=1074MHz
	{ 0x09, 0x68, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1080MHz, VCO=1080MHz
	{ 0x09, 0x6a, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1086MHz, VCO=1086MHz
	{ 0x09, 0x6c, 0x40, 0x02, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x24, 0x00, 0x00 },//PLL=1092MHz, VCO=1092MHz
};

int T2_ConfigT2PLLClock(int optPll)
{
	int i;
	int T2Pll;
	int PLL = optPll;
	int default_reg_len;
	uint32_t pll_fbdiv, pll_prediv, pll_postdiv, postdiv;
	uint32_t f_vcc, f_pll;

	default_reg_len = sizeof(default_reg) / 12;

	if(PLL > 120)
	{
		T2Pll=0;
		if(PLL >= 1092)
		{
			T2Pll = default_reg_len - 1;
			return T2Pll;
		}
		else
		{
			for(i = 0; i < default_reg_len; i++)
			{
				pll_fbdiv = ((((uint32_t)default_reg[i][0]) << 8) & 0x00000100) | (((uint32_t)default_reg[i][1]) & 0x000000ff);
				pll_prediv = (((uint32_t)default_reg[i][0]) >> 1) & 0x0000001f;
				pll_postdiv = (((uint32_t)default_reg[i][3]) >> 6) & 0x00000003;
				postdiv = (1 << pll_postdiv);

				f_vcc = 12 * pll_fbdiv / pll_prediv;
				f_pll = f_vcc / postdiv;

				if(PLL <= f_pll)
				{
					T2Pll= i; //found
					break;
				}
			}
		}
	} else {
		f_pll = 120;
		T2Pll = 0;
	}
	applog(LOG_WARNING, "T2 = %d,%d",f_pll,T2Pll);
	applog(LOG_WARNING, "T2 PLL Clock = %dMHz",f_pll);
	return T2Pll;
}
