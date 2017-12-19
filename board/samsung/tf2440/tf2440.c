#include <common.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/s3c24x0_cpu.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	/* arch number of MINI2440-Board */
        gd->bd->bi_arch_number = MACH_TYPE_MINI2440;

	/* adress of boot parameters */
	gd->bd->bi_boot_params = 0x30000100;

	icache_enable();
	dcache_enable();

	return 0;
}

int dram_init(void)
{
        /* dram_init must store complete ramsize in gd->ram_size */
        gd->ram_size = PHYS_SDRAM_1_SIZE;
	return 0;
}

int board_early_init_f(void)
{
	struct s3c24x0_gpio * const gpio = s3c24x0_get_base_gpio();

	/* set up the I/O ports */
	writel(0x007FFFFF, &gpio->gpacon);
	writel(0x00000000, &gpio->gpbcon);
	writel(0x000007FF, &gpio->gpbup);
	writel(0xAAAAAAAA, &gpio->gpccon);
	writel(0x0000FFFF, &gpio->gpcup);
	writel(0xAAAAAAAA, &gpio->gpdcon);
	writel(0x0000FFFF, &gpio->gpdup);
	writel(0xAAAAAAAA, &gpio->gpecon);
	writel(0x0000FFFF, &gpio->gpeup);
	writel(0x000055AA, &gpio->gpfcon);
	writel(0x000000FF, &gpio->gpfup);
	writel(0xFF95FFBA, &gpio->gpgcon);
	writel(0x0000FFFF, &gpio->gpgup);
	writel(0x002AFAAA, &gpio->gphcon);
	writel(0x000007FF, &gpio->gphup);
	return 0;
}

void coloured_LED_init(void)
{
	struct s3c24x0_gpio * const gpio = s3c24x0_get_base_gpio();
    writel(0x00015400, &gpio->gpbcon);
}

void red_led_on(void)
{
	struct s3c24x0_gpio * const gpio = s3c24x0_get_base_gpio();
    writel(0x00000000,&gpio->gpbdat);
}
