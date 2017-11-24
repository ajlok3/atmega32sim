#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gui.h"
#include "led.h"
#include "button.h"
#include "poti.h"
#include "seg7.h"
#include "chip_atmel_atmega32.h"
#include "flash.h"
#include "sram.h"

int end = 0;

int
main(int argc, char **argv)
{
	struct sig_std_logic *nreset;
	struct sig_std_logic *vcc;
	struct sig_std_logic *gnd;
	struct sig_std_logic *pa[8];
	struct sig_std_logic *pb[8];
	struct sig_std_logic *pc[8];
	struct sig_std_logic *pd[8];
	void *led_red0;
	void *led_green0;
	void *led_yellow0;
	void *led_blue0;
	void *led_red1;
	void *led_green1;
	void *led_yellow1;
	void *led_blue1;
	void *button0;
	void *button1;
	void *poti;
	void *light_sensor;
	void *dis1;
	void *dis2;
	void *cpu;
	void *sram;
	void *flash;
	int i;
	//flash must be initialized before gui_init() because this function erases argv[1]
	
	gui_init(&argc, &argv);
	
	printf("Hallo");

	/* Create signals. */
	nreset = sig_std_logic_create("nreset");
	vcc = sig_std_logic_create("nreset");
	gnd = sig_std_logic_create("nreset");
	for (i = 0; i < 8; i++) {
		char name[8];
	
		sprintf(name, "a%d", i);
		pa[i] = sig_std_logic_create(name);
		sprintf(name, "b%d", i);
		pb[i] = sig_std_logic_create(name);
		sprintf(name, "c%d", i);
		pc[i] = sig_std_logic_create(name);
		sprintf(name, "d%d", i);
		pd[i] = sig_std_logic_create(name);
	}

	/* Create components. */
	led_red0 = led_create("red0", 0xff, 0x00, 0x00, vcc, pd[7]);
	led_green0 = led_create("green0", 0x00, 0xff, 0x00, vcc, pc[0]);
	led_yellow0 = led_create("yellow0", 0xff, 0xff, 0x00, vcc, pc[1]);
	led_blue0 = led_create("blue0", 0x00, 0x00, 0xff, vcc, pc[6]);
	led_red1 = led_create("red1", 0xff, 0x00, 0x00, vcc, pc[7]);
	led_green1 = led_create("green1", 0x00, 0xff, 0x00, vcc, pa[7]);
	led_yellow1 = led_create("yellow1", 0xff, 0xff, 0x00, vcc, pa[6]);
	led_blue1 = led_create("blue1", 0x00, 0x00, 0xff, vcc, pa[5]);

	button0 = button_create("button0", pd[3]);
	button1 = button_create("button1", pd[2]);

	poti = poti_create("potentiometer", gnd, pa[1], vcc);
	light_sensor = poti_create("light sensor", gnd, pa[0], vcc);

	dis2 = seg7_create("dis2",
			pb[1], pb[0], pd[1], pb[6], vcc, pb[5],
			pb[4], pd[1], pb[3], pb[2]);
	dis1 = seg7_create("dis1",
			pb[1], pb[0], pd[0], pb[6], vcc, pb[5],
			pb[4], pd[0], pb[3], pb[2]);

	flash = new_flash();
	//printf("%s\n", argv[1]);
	if(flash_binary(argv[1], flash)){
		printf("Could not load %s\n", argv[1]);
			return 1;
	}	
	
	sram = new_sram();
	
	cpu = chip_atmel_atmega32_create("cpu",
			pb[0], pb[1], pb[2], pb[3], pb[4], pb[5], pb[6], pb[7],
			nreset,
			vcc,
			gnd,
			NULL,
			NULL,
			pd[0], pd[1], pd[2], pd[3], pd[4], pd[5], pd[6], pd[7],
			pc[0], pc[1], pc[2], pc[3], pc[4], pc[5], pc[6], pc[7],
			vcc,
			gnd,
			vcc,
			pa[7], pa[6], pa[5], pa[4], pa[3], pa[2], pa[1], pa[0], sram, flash);
	

	sig_std_logic_connect_out(gnd, main, SIG_STD_LOGIC_0);
	sig_std_logic_connect_out(vcc, main, SIG_STD_LOGIC_0);
	sig_std_logic_connect_out(nreset, main, SIG_STD_LOGIC_0);

	/* Run system. */
	sig_std_logic_set(nreset, main, SIG_STD_LOGIC_0);
	sig_std_logic_set(gnd, main, SIG_STD_LOGIC_0);
	sig_std_logic_set(vcc, main, SIG_STD_LOGIC_1);
	for (i = 0; i < 100; i++) {
		sleep(3);
		chip_atmel_atmega32_step(cpu);
	}
	sig_std_logic_set(nreset, main, SIG_STD_LOGIC_1);
	while (! end) {
		seg7_step(dis1);
		seg7_step(dis2);
		//delay for debugging
		sleep	(3);
		//
		chip_atmel_atmega32_step(cpu);
		gui_step();
	}

	/* Destroy components. */
	chip_atmel_atmega32_destroy(cpu);

	seg7_destroy(dis2);
	seg7_destroy(dis1);

	poti_destroy(light_sensor);
	poti_destroy(poti);

	button_destroy(button1);
	button_destroy(button0);

	led_destroy(led_blue1);
	led_destroy(led_yellow1);
	led_destroy(led_green1);
	led_destroy(led_red1);
	led_destroy(led_blue0);
	led_destroy(led_yellow0);
	led_destroy(led_green0);
	led_destroy(led_red0);
	flash_destroy(flash);
	sram_destroy(sram);	

	/* Destroy signals. */
	for (i = 0; i < 8; i++) {
		sig_std_logic_destroy(pd[i]);
		sig_std_logic_destroy(pc[i]);
		sig_std_logic_destroy(pb[i]);
		sig_std_logic_destroy(pa[i]);
	}
	sig_std_logic_destroy(nreset);
	sig_std_logic_destroy(gnd);
	sig_std_logic_destroy(vcc);

	gui_exit();

	return 0;
}
