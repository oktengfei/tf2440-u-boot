/* 
 * Add at 2017.12.17 By tengfei
 * Modified from u-boot2016.7/smdk2410.h
 * 
 * Configuration settings for the SAMSUNG Mini2440 Board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_S3C24X0      /* This is a SAMSUNG s3c24x0-type SoC */
#define CONFIG_S3C2440      /* specifically a samsung s3c2440 soc */
/*#define CONFIG_TF2440       / * on my tf2440 board */

/* base addr setting */
#define CONFIG_SYS_TEXT_BASE    0x30000000      /* u-boot runing base addr */
#define CONFIG_SYS_LOAD_ADDR    0x30800000      /* default system file load addr */

/* system clk */
#define CONFIG_SYS_CLK_FREQ     12000000        /* 12MHz clock input */

/* enable spl */
#define CONFIG_SPL
#define CONFIG_SPL_STACK        0x40001000

/* physical memory map setting */
#define CONFIG_NR_DRAM_BANKS    1
#define PHYS_SDRAM_1            0x30000000      /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE       0x04000000      /* 64 MB         */

/* INIT options */

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_SYS_SDRAM_BASE   PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR (CONFIG_SYS_SDRAM_BASE + 0x00500000 - \
                                GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_CBSIZE       256
#define CONFIG_SYS_PBSIZE       (CONFIG_SYS_CBSIZE + \
                                sizeof(CONFIG_SYS_PROMPT) + 16)

/* env setting */
#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE         (128 << 10)     /* 128KB , 0x20000 */


/* Miscellaneous configureble options */
#define CONFIG_SYS_MAXARGS      16              /* max. Number of arguments accepted for monitor command */

/* size of malloc pool */
#define CONFIG_SYS_MALLOC_LEN   (4 * 1024 * 1024)

/* define serial console configuration */
/* #define CONFIG_S3C24X0_SERIAL */
#define CONFIG_SERIAL1          1               /* use serial 1 on tf2440 board*/
#define CONFIG_BAUDRATE         115200          

/* Flash configuration */
/* #define CONFIG_SYS_NO_FLASH                     / * no flash */
#define CONFIG_SYS_MAX_FLASH_BANKS  0           /* no flash */

#endif

