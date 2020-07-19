#ifndef __IPHONE_4_CONFIG_H
#define __IPHONE_4_CONFIG_H

#define CONFIG_SYS_TEXT_BASE    0x40004000
#define CONFIG_SYS_LOAD_ADDR    0x44000000

#define CONFIG_SYS_MALLOC_LEN   (CONFIG_ENV_SIZE + (80 << 20))

#define CONFIG_SYS_INIT_RAM_ADDR	0x43000000
#define CONFIG_SYS_INIT_RAM_SIZE	0x8000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
			CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)

#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE		0x40000000

#ifdef CONFIG_VIDEO
#define CONFIG_VIDEO_LOGO
/* functions for cfb_console */
#define VIDEO_KBD_INIT_FCT		a4_kp_init()
#define VIDEO_TSTC_FCT			a4_kp_tstc
#define VIDEO_GETC_FCT			a4_kp_getc
#ifndef __ASSEMBLY__
int a4_kp_init(void);
int a4_kp_tstc(void);
int a4_kp_getc(void);
#endif
#endif

#endif /* !__IPHONE_4_CONFIG_H */
