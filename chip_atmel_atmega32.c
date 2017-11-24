/*
 * Copyright (C) 2016 FAUmachine Team <info@faumachine.org>.
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License, either version 2 of
 * the License, or (at your option) any later version. See COPYING.
 */

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "chip_atmel_atmega32.h"
#include "sram.h"
#include "flash.h"

//REG defines
#define X_HIGH			26
#define X_LOW			27
#define Y_HIGH			28
#define Y_LOW			29
#define Z_HIGH			30
#define Z_LOW			31

//IO defines

	
#define SP_L			0x3d
#define SP_H			0x3e
#define SREG			0x3f


#define BE(a, b) __builtin_expect(a, b)

static uint8_t power = 1;
struct cpssp {
	/* FIXME */

	struct sig_std_logic *port_a0;
	struct sig_std_logic *port_a1;
	struct sig_std_logic *port_a2;
	struct sig_std_logic *port_a3;
	struct sig_std_logic *port_a4;
	struct sig_std_logic *port_a5;
	struct sig_std_logic *port_a6;
	struct sig_std_logic *port_a7;

	struct sig_std_logic *port_b0;
	struct sig_std_logic *port_b1;
	struct sig_std_logic *port_b2;
	struct sig_std_logic *port_b3;
	struct sig_std_logic *port_b4;
	struct sig_std_logic *port_b5;
	struct sig_std_logic *port_b6;
	struct sig_std_logic *port_b7;

	struct sig_std_logic *port_c0;
	struct sig_std_logic *port_c1;
	struct sig_std_logic *port_c2;
	struct sig_std_logic *port_c3;
	struct sig_std_logic *port_c4;
	struct sig_std_logic *port_c5;
	struct sig_std_logic *port_c6;
	struct sig_std_logic *port_c7;

	struct sig_std_logic *port_d0;
	struct sig_std_logic *port_d1;
	struct sig_std_logic *port_d2;
	struct sig_std_logic *port_d3;
	struct sig_std_logic *port_d4;
	struct sig_std_logic *port_d5;
	struct sig_std_logic *port_d6;
	struct sig_std_logic *port_d7;
	struct flash *flash;
	struct sram *sram;
	uint8_t REGS[0x20];
	uint8_t IO[0x40];
};
static void
chip_atmel_atmega32_port_a0_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_a1_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_a2_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_a3_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_a4_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_a5_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_a6_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_a7_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b0_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b1_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b2_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b3_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b4_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b5_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b6_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_b7_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c0_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c1_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c2_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c3_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c4_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c5_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c6_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_c7_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d0_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d1_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d2_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d3_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d4_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d5_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d6_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_port_d7_out_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void chip_atmel_atmega32_exec_inst(struct cpssp *cpssp){

	struct sram *sram = cpssp->sram;
	struct flash *flash = cpssp->flash;

	uint16_t inst = load_inst(flash);	
	uint8_t res, sreg_val, reg_val_r, reg_val_d, im_val;

	//Read out Opcode
	switch((inst & 0xf000)>>12){
		case 0x9: //jmp
			inst = load_inst(flash);
			set_pc(flash, inst);
			printf("jmp to pc=%x\n", flash->pc);
			break;

		case 0x2: //eor
			printf("eor: dest=%x, source=%x\n", (inst>>4)&0x1f, (inst&0xf)|((0x200&inst))>>5);
			cpssp->REGS[(inst>>4)&0x1f] = cpssp->REGS[(inst>>4)&0x1f]^cpssp->REGS[(inst&0xf)|((0x200&inst))>>5];
			break;

		case 0xb: //out
			printf("out: dest=%x, source=%x\n",((inst&0x600)>>5)|(inst&0xf), (inst & 0x01f0)>>4);
			cpssp->IO[((inst&0x600)>>5)|(inst&0xf)] = cpssp->REGS[(inst & 0x01f0)>>4];
			break;

		case 0xe: //ldi
			printf("ldi: dest=%x, value=%x\n", ((inst&0xf0)>>4)|0x10, (inst&0xf) | ((inst&0xf00)>>4));
			cpssp->REGS[((inst&0xf0)>>4)|0x10] = (inst&0xf) | ((inst&0xf00)>>4);
			break;

		case 0xc: //rjmp
			printf("rjmp: pc=pc+%x\n",(inst&0xfff));
			set_pc(flash, flash->pc+(inst&0xfff));			
			break;

		case 0x3: //cpi
			res = 0; sreg_val=0; reg_val_d=0; im_val = 0;			
			reg_val_d = cpssp->REGS[((inst&0xf0)>>4)|0x10];
			im_val = (inst&0xf) | ((inst&0xf00)>>4);
			res = reg_val_d - im_val;
			sreg_val |= ((!res)<<1); //zero-Flag
			sreg_val |= (((~reg_val_d)&im_val) | (res&im_val) | (res&(~reg_val_d)))>>7; //carry-Flag
			//TODO: other flags, 0x3 is the mask for set or cleared flags
			cpssp->IO[SREG] &= ~0x3;
			cpssp->IO[SREG] |= (sreg_val&0x3);
			printf("cpi: reg_d=%x, value=%x, res=%x, SREG=%x\n",reg_val_d, im_val, res, cpssp->IO[SREG]);
			break;

		case 0x0: //cpc
			res=0; sreg_val=0; reg_val_r=0; reg_val_d=0;
			reg_val_d = cpssp->REGS[(inst>>4)&0x1f];
			reg_val_r = cpssp->REGS[(inst&0xf)|((0x200&inst))>>5];
			res = reg_val_d - reg_val_r - (cpssp->IO[SREG]&0x1);
			sreg_val |= ((!res)&&(cpssp->IO[SREG]&0x2))<<1; //zero-flag
			sreg_val |= (((~reg_val_d)&reg_val_r) | (res&reg_val_r) | (res&(~reg_val_d)))>>7; //carry-flag
			//TODO: other flags, 0x3 is the mask for set or cleared flags		
			cpssp->IO[SREG] &= ~0x3;
			cpssp->IO[SREG] |= (sreg_val&0x3);
			printf("cpc: reg_d=%x, reg_r=%x, res=%x, SREG=%x\n",reg_val_d, reg_val_r, res, cpssp->IO[SREG]);
			break;

		default:
			printf("unknown inst, pc=%x\n",flash->pc);
			return;
	}
	
}

void
chip_atmel_atmega32_step(void *_cpssp)
{
	struct cpssp *cpssp = _cpssp;
	if(BE(!power, 0)){
	} else{
		chip_atmel_atmega32_exec_inst(cpssp);
	}
}



static void
chip_atmel_atmega32_vcc_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_avcc_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

static void
chip_atmel_atmega32_nreset_set(void *_cpssp, unsigned int nval)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */
}

void *
chip_atmel_atmega32_create(
	const char *name,
	struct sig_std_logic *port_b0,
	struct sig_std_logic *port_b1,
	struct sig_std_logic *port_b2,
	struct sig_std_logic *port_b3,
	struct sig_std_logic *port_b4,
	struct sig_std_logic *port_b5,
	struct sig_std_logic *port_b6,
	struct sig_std_logic *port_b7,
	struct sig_std_logic *port_nreset,
	struct sig_std_logic *port_vcc,
	struct sig_std_logic *port_gnd0,
	struct sig_std_logic *port_xtal2,
	struct sig_std_logic *port_xtal1,
	struct sig_std_logic *port_d0,
	struct sig_std_logic *port_d1,
	struct sig_std_logic *port_d2,
	struct sig_std_logic *port_d3,
	struct sig_std_logic *port_d4,
	struct sig_std_logic *port_d5,
	struct sig_std_logic *port_d6,
	struct sig_std_logic *port_d7,
	struct sig_std_logic *port_c0,
	struct sig_std_logic *port_c1,
	struct sig_std_logic *port_c2,
	struct sig_std_logic *port_c3,
	struct sig_std_logic *port_c4,
	struct sig_std_logic *port_c5,
	struct sig_std_logic *port_c6,
	struct sig_std_logic *port_c7,
	struct sig_std_logic *port_avcc,
	struct sig_std_logic *port_gnd1,
	struct sig_std_logic *port_aref,
	struct sig_std_logic *port_a7,
	struct sig_std_logic *port_a6,
	struct sig_std_logic *port_a5,
	struct sig_std_logic *port_a4,
	struct sig_std_logic *port_a3,
	struct sig_std_logic *port_a2,
	struct sig_std_logic *port_a1,
	struct sig_std_logic *port_a0,
	struct sram *sram,
	struct flash *flash
)
{
	static const struct sig_std_logic_funcs port_vcc_funcs = {
		.boolean_or_set = chip_atmel_atmega32_vcc_set,
	};
	static const struct sig_std_logic_funcs port_avcc_funcs = {
		.std_logic_set = chip_atmel_atmega32_avcc_set,
	};
	static const struct sig_std_logic_funcs port_nreset_funcs = {
		.boolean_or_set = chip_atmel_atmega32_nreset_set,
	};
	static const struct sig_std_logic_funcs port_a0_funcs = {
		.set_ext = chip_atmel_atmega32_port_a0_out_set,
	};
	static const struct sig_std_logic_funcs port_a1_funcs = {
		.set_ext = chip_atmel_atmega32_port_a1_out_set,
	};
	static const struct sig_std_logic_funcs port_a2_funcs = {
		.set_ext = chip_atmel_atmega32_port_a2_out_set,
	};
	static const struct sig_std_logic_funcs port_a3_funcs = {
		.set_ext = chip_atmel_atmega32_port_a3_out_set,
	};
	static const struct sig_std_logic_funcs port_a4_funcs = {
		.set_ext = chip_atmel_atmega32_port_a4_out_set,
	};
	static const struct sig_std_logic_funcs port_a5_funcs = {
		.set_ext = chip_atmel_atmega32_port_a5_out_set,
	};
	static const struct sig_std_logic_funcs port_a6_funcs = {
		.set_ext = chip_atmel_atmega32_port_a6_out_set,
	};
	static const struct sig_std_logic_funcs port_a7_funcs = {
		.set_ext = chip_atmel_atmega32_port_a7_out_set,
	};
	static const struct sig_std_logic_funcs port_b0_funcs = {
		.set_ext = chip_atmel_atmega32_port_b0_out_set,
	};
	static const struct sig_std_logic_funcs port_b1_funcs = {
		.set_ext = chip_atmel_atmega32_port_b1_out_set,
	};
	static const struct sig_std_logic_funcs port_b2_funcs = {
		.set_ext = chip_atmel_atmega32_port_b2_out_set,
	};
	static const struct sig_std_logic_funcs port_b3_funcs = {
		.set_ext = chip_atmel_atmega32_port_b3_out_set,
	};
	static const struct sig_std_logic_funcs port_b4_funcs = {
		.set_ext = chip_atmel_atmega32_port_b4_out_set,
	};
	static const struct sig_std_logic_funcs port_b5_funcs = {
		.set_ext = chip_atmel_atmega32_port_b5_out_set,
	};
	static const struct sig_std_logic_funcs port_b6_funcs = {
		.set_ext = chip_atmel_atmega32_port_b6_out_set,
	};
	static const struct sig_std_logic_funcs port_b7_funcs = {
		.set_ext = chip_atmel_atmega32_port_b7_out_set,
	};
	static const struct sig_std_logic_funcs port_c0_funcs = {
		.set_ext = chip_atmel_atmega32_port_c0_out_set,
	};
	static const struct sig_std_logic_funcs port_c1_funcs = {
		.set_ext = chip_atmel_atmega32_port_c1_out_set,
	};
	static const struct sig_std_logic_funcs port_c2_funcs = {
		.set_ext = chip_atmel_atmega32_port_c2_out_set,
	};
	static const struct sig_std_logic_funcs port_c3_funcs = {
		.set_ext = chip_atmel_atmega32_port_c3_out_set,
	};
	static const struct sig_std_logic_funcs port_c4_funcs = {
		.set_ext = chip_atmel_atmega32_port_c4_out_set,
	};
	static const struct sig_std_logic_funcs port_c5_funcs = {
		.set_ext = chip_atmel_atmega32_port_c5_out_set,
	};
	static const struct sig_std_logic_funcs port_c6_funcs = {
		.set_ext = chip_atmel_atmega32_port_c6_out_set,
	};
	static const struct sig_std_logic_funcs port_c7_funcs = {
		.set_ext = chip_atmel_atmega32_port_c7_out_set,
	};
	static const struct sig_std_logic_funcs port_d0_funcs = {
		.set_ext = chip_atmel_atmega32_port_d0_out_set,
	};
	static const struct sig_std_logic_funcs port_d1_funcs = {
		.set_ext = chip_atmel_atmega32_port_d1_out_set,
	};
	static const struct sig_std_logic_funcs port_d2_funcs = {
		.set_ext = chip_atmel_atmega32_port_d2_out_set,
	};
	static const struct sig_std_logic_funcs port_d3_funcs = {
		.set_ext = chip_atmel_atmega32_port_d3_out_set,
	};
	static const struct sig_std_logic_funcs port_d4_funcs = {
		.set_ext = chip_atmel_atmega32_port_d4_out_set,
	};
	static const struct sig_std_logic_funcs port_d5_funcs = {
		.set_ext = chip_atmel_atmega32_port_d5_out_set,
	};
	static const struct sig_std_logic_funcs port_d6_funcs = {
		.set_ext = chip_atmel_atmega32_port_d6_out_set,
	};
	static const struct sig_std_logic_funcs port_d7_funcs = {
		.set_ext = chip_atmel_atmega32_port_d7_out_set,
	};
	struct cpssp *cpssp = (struct cpssp*)malloc(sizeof(*cpssp));
	for(int i=0; i<0x20; i++) cpssp->REGS[i]=0;
	for(int i=0; i<0x40; i++) cpssp->IO[i]=0;

	assert(cpssp);

	/* FIXME */

	sig_std_logic_connect_in(port_vcc, cpssp, &port_vcc_funcs);
	sig_std_logic_connect_in(port_nreset, cpssp, &port_nreset_funcs);

	sig_std_logic_connect_in(port_avcc, cpssp, &port_avcc_funcs);

	cpssp->port_a0 = port_a0;
	sig_std_logic_connect_out(port_a0, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a0, cpssp, &port_a0_funcs);
	cpssp->port_a1 = port_a1;
	sig_std_logic_connect_out(port_a1, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a1, cpssp, &port_a1_funcs);
	cpssp->port_a2 = port_a2;
	sig_std_logic_connect_out(port_a2, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a2, cpssp, &port_a2_funcs);
	cpssp->port_a3 = port_a3;
	sig_std_logic_connect_out(port_a3, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a3, cpssp, &port_a3_funcs);
	cpssp->port_a4 = port_a4;
	sig_std_logic_connect_out(port_a4, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a4, cpssp, &port_a4_funcs);
	cpssp->port_a5 = port_a5;
	sig_std_logic_connect_out(port_a5, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a5, cpssp, &port_a5_funcs);
	cpssp->port_a6 = port_a6;
	sig_std_logic_connect_out(port_a6, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a6, cpssp, &port_a6_funcs);
	cpssp->port_a7 = port_a7;
	sig_std_logic_connect_out(port_a7, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_a7, cpssp, &port_a7_funcs);

	cpssp->port_b0 = port_b0;
	sig_std_logic_connect_out(port_b0, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b0, cpssp, &port_b0_funcs);
	cpssp->port_b1 = port_b1;
	sig_std_logic_connect_out(port_b1, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b1, cpssp, &port_b1_funcs);
	cpssp->port_b2 = port_b2;
	sig_std_logic_connect_out(port_b2, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b2, cpssp, &port_b2_funcs);
	cpssp->port_b3 = port_b3;
	sig_std_logic_connect_out(port_b3, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b3, cpssp, &port_b3_funcs);
	cpssp->port_b4 = port_b4;
	sig_std_logic_connect_out(port_b4, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b4, cpssp, &port_b4_funcs);
	cpssp->port_b5 = port_b5;
	sig_std_logic_connect_out(port_b5, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b5, cpssp, &port_b5_funcs);
	cpssp->port_b6 = port_b6;
	sig_std_logic_connect_out(port_b6, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b6, cpssp, &port_b6_funcs);
	cpssp->port_b7 = port_b7;
	sig_std_logic_connect_out(port_b7, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_b7, cpssp, &port_b7_funcs);

	cpssp->port_c0 = port_c0;
	sig_std_logic_connect_out(port_c0, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c0, cpssp, &port_c0_funcs);
	cpssp->port_c1 = port_c1;
	sig_std_logic_connect_out(port_c1, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c1, cpssp, &port_c1_funcs);
	cpssp->port_c2 = port_c2;
	sig_std_logic_connect_out(port_c2, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c2, cpssp, &port_c2_funcs);
	cpssp->port_c3 = port_c3;
	sig_std_logic_connect_out(port_c3, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c3, cpssp, &port_c3_funcs);
	cpssp->port_c4 = port_c4;
	sig_std_logic_connect_out(port_c4, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c4, cpssp, &port_c4_funcs);
	cpssp->port_c5 = port_c5;
	sig_std_logic_connect_out(port_c5, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c5, cpssp, &port_c5_funcs);
	cpssp->port_c6 = port_c6;
	sig_std_logic_connect_out(port_c6, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c6, cpssp, &port_c6_funcs);
	cpssp->port_c7 = port_c7;
	sig_std_logic_connect_out(port_c7, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_c7, cpssp, &port_c7_funcs);

	cpssp->port_d0 = port_d0;
	sig_std_logic_connect_out(port_d0, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d0, cpssp, &port_d0_funcs);
	cpssp->port_d1 = port_d1;
	sig_std_logic_connect_out(port_d1, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d1, cpssp, &port_d1_funcs);
	cpssp->port_d2 = port_d2;
	sig_std_logic_connect_out(port_d2, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d2, cpssp, &port_d2_funcs);
	cpssp->port_d3 = port_d3;
	sig_std_logic_connect_out(port_d3, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d3, cpssp, &port_d3_funcs);
	cpssp->port_d4 = port_d4;
	sig_std_logic_connect_out(port_d4, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d4, cpssp, &port_d4_funcs);
	cpssp->port_d5 = port_d5;
	sig_std_logic_connect_out(port_d5, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d5, cpssp, &port_d5_funcs);
	cpssp->port_d6 = port_d6;
	sig_std_logic_connect_out(port_d6, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d6, cpssp, &port_d6_funcs);
	cpssp->port_d7 = port_d7;
	sig_std_logic_connect_out(port_d7, cpssp, SIG_STD_LOGIC_Z);
	sig_std_logic_connect_in(port_d7, cpssp, &port_d7_funcs);
	cpssp->flash = flash;
	cpssp->sram = sram;
	
	return cpssp;
}

void
chip_atmel_atmega32_destroy(void *_cpssp)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */

	free(cpssp);
}
