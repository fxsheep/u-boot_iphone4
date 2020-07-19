#include <common.h>
#include <dm.h>
#include <errno.h>
#include <serial.h>
#include <video_fb.h>

GraphicDevice gdev;

/*
 * Routine: a4_kp_init
 */
int a4_kp_init(void)
{
	return 0;
}

/*
 * Routine: a4_kp_tstc
 */
int a4_kp_tstc(void)
{
	return 0;
}

/*
 * Routine: a4_kp_getc
 */
int a4_kp_getc(void)
{
	return 0;
}

/*
 * Routine: video_hw_init
 * Description: Set up the GraphicDevice depending on sys_boot.
 */
void *video_hw_init(void)
{
	/* fill in Graphic Device */

	#define S5L8930X_DP_FB_ADDR		0x89004044
	#define S5L8930X_DP_FB_SIZE		0x89004060
	gdev.frameAdrs = *(uint32_t*)S5L8930X_DP_FB_ADDR;
	gdev.winSizeX = ((*(uint32_t*)S5L8930X_DP_FB_SIZE) & 0xFFFF0000) >> 16;
	gdev.winSizeY = ((*(uint32_t*)S5L8930X_DP_FB_SIZE) & 0x0000FFFF) >> 0;
	gdev.gdfBytesPP = 4;
	gdev.gdfIndex = GDF_32BIT_X888RGB;
	return (void *) &gdev;
}

/*
 * Routine: board_init
 * Description: Early hardware init.
 */
int board_init(void)
{
	return 0;
}

/*
 * Routine: misc_init_r
 * Description: Configure board specific parts.
 */
int misc_init_r(void)
{
	return 0;
}

/*
 * Routine: get_board_revision
 * Description: Return board revision.
 */
u32 get_board_rev(void)
{
	return 0xBEEF;
}

/*
 * Routine: dram_init
 * Description: sets uboots idea of sdram size
 */
int dram_init(void)
{
	gd->ram_size = 256 * 1024 * 1024;
	return 0;
}

int print_cpuinfo(void)
{
	return 0;
}
