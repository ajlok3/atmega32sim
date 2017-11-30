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
#define X_LOW			26
#define X_HIGH			27
#define Y_LOW			28
#define Y_HIGH			29
#define Z_LOW			30
#define Z_HIGH			31

//IO defines

	
#define SP_L			0x3d
#define SP_H			0x3e
#define SREG			0x3f

#define STACK			sram->SRAM[(cpssp->IO[SP_H]<<8)|cpssp->IO[SP_L]]
#define STACK_inc		if(!(~(cpssp->IO[SP_L]))) cpssp->IO[SP_H]++; cpssp->IO[SP_L]++;
#define STACK_dec		if(!(cpssp->IO[SP_L])) cpssp->IO[SP_H]--; cpssp->IO[SP_L]--
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
	printf("pc=%x, sp=%x: ",flash->pc, (cpssp->IO[SP_H]<<8)|cpssp->IO[SP_L]);
	uint16_t inst = load_inst(flash);	
	static uint8_t res, sreg_val, reg_val_r, reg_val_d, im_val, reg_d, reg_r, disp;
	static uint16_t val_16;
	static int val_signed;
	//Read Opcode
	switch((inst & 0xf000)>>12){
		case 0x9: //jmp, lpm, st, call, pop & much much more....
			switch ((inst & 0x0f00)>>8){
				case 0x0: case 0x1: //lpm (ii),(iii), pop
					switch(inst&0xf){
						case 0x4: case 0x5: //lpm
							reg_d = (inst&0x1f0)>>4;
							im_val = ((flash->FLASH[(cpssp->REGS[Z_HIGH]<<7)|(cpssp->REGS[Z_LOW]>>1)])>>((cpssp->REGS[Z_LOW]&0x1)*8))&0xff;
							cpssp->REGS[reg_d] = im_val;
							if(inst &0x1){
								cpssp->REGS[Z_LOW]++; //lpm (iii)
								if(!(cpssp->REGS[Z_LOW])){
									cpssp->REGS[Z_HIGH]++; //low overflow
								}
							}
							printf("lpm: dest:%x, val=%c, z_high:%x, z_low:%x\n", reg_d, im_val, cpssp->REGS[Z_HIGH], cpssp->REGS[Z_LOW]);
							break;
						case 0xf: //pop
							reg_d = (inst&0x1f0)>>4;
							STACK_inc;
							cpssp->REGS[reg_d] = STACK;							
							printf("pop: sp=%x, reg_d=%x, val=%x\n", (cpssp->IO[SP_H]<<8)|cpssp->IO[SP_L], reg_d, cpssp->REGS[reg_d]);
							break;
						case 0x0: //lds
							reg_d = (inst&0x1f0)>>4;
							val_16 = load_inst(flash);
							cpssp->REGS[reg_d] = sram->SRAM[val_16];
							printf("lds: dest=%x, val=%x, addr=%x\n", reg_d, cpssp->REGS[reg_d], val_16);
							break;
						default: //ld X, Y, Z, +- //caution: elpm not implemented
							reg_d = (inst&0x1f0)>>4;
							switch(inst&0xf){
								case 0x1: case 0x2:
									reg_r = Z_LOW;
									printf("st Z");
									break;
								case 0x9: case 0xa:
									reg_r = Y_LOW;
									printf("st Y");
									break;
								case 0xd: case 0xe:
									reg_r = X_LOW;
									printf("st X");
									break;
							}
							if(!(inst&0x1)){
								if(!cpssp->REGS[reg_r]) cpssp->REGS[reg_r+1]--;
								cpssp->REGS[reg_r]--;
								printf("-: ");
							}
							cpssp->REGS[reg_d] = sram->SRAM[(cpssp->REGS[reg_r+1]<<8)|cpssp->REGS[reg_r]];
							if(inst&0x1){
								cpssp->REGS[reg_r]++;
								if(!(cpssp->REGS[reg_r])) cpssp->REGS[reg_r+1]++;
								printf("+: ");
							}
							printf("XYZ_HIGH=%x, XYZ_LOW=%x, dest=%x, dest_val=%x\n", cpssp->REGS[reg_r+1], cpssp->REGS[reg_r], reg_d, cpssp->REGS[reg_d]);
							break;
					}
					break;

				case 0x2: case 0x3: //st, push	
					if((inst&0xf) == 0xf){ //push
						STACK = cpssp->REGS[(inst>>4)&0x1f];
						STACK_dec;
						printf("push: reg=%x, sp=%x\n", (inst>>4)&0x1f, (cpssp->IO[SP_H]<<8)|cpssp->IO[SP_L]);
						return;
					}
					switch((inst&0xc)>>2){ //st
						case 0x3: //st X
							reg_d = X_LOW;
							break;
						case 0x2: //st Y
							reg_d = Y_LOW;
							break;
						case 0x0: //st z
							reg_d = Z_LOW;
							break;
					}
					if((inst&0x3) == 0x2){ //pre decrement
						cpssp->REGS[reg_d]--;
						if(cpssp->REGS[reg_d] == 0xff) cpssp->REGS[reg_d+1]--; //decrement high byte
					}
					sram->SRAM[(cpssp->REGS[reg_d+1]<<8)|cpssp->REGS[reg_d]] = cpssp->REGS[(inst&0x1f0)>>4];
					if(inst&0x1){ //post increment
						cpssp->REGS[reg_d]++;
						if(!cpssp->REGS[reg_d]) cpssp->REGS[reg_d+1]++; //increment high byte					
					}
					printf("st: reg_d:%x, SRAM:%x, val:%c\n", reg_d, (cpssp->REGS[reg_d+1]<<8)|cpssp->REGS[reg_d], cpssp->REGS[(inst&0x1f0)>>4]);	
					break;

				case 0x4: case 0x5: //jmp, call, bclr, ret
					switch(inst&0xf){
						case 0xa: //dec
							sreg_val = 0;
							reg_d = (inst&0x1f0)>>4;
							cpssp->REGS[reg_d]--;
							sreg_val |= (!cpssp->REGS[reg_d])<<1; //zero
							cpssp->IO[SREG] &= ~0x2;
							cpssp->IO[SREG]|= sreg_val&0x2;
							printf("dec: reg=%x, new_val=%x, SREG=%x\n", reg_d, cpssp->REGS[reg_d], cpssp->IO[SREG]);
							break;
						case 0x0: //com
							reg_d = (inst&0x1f0)>>4;							
							sreg_val = 0x1; //carry-flag always set
							res = ~cpssp->REGS[reg_d];
							sreg_val |= (!res)<<1; //zero-flag
							cpssp->IO[SREG] &= ~0x3;
							cpssp->IO[SREG] |= sreg_val&0x3;
							printf("com: reg=%x, old_val=%x, new_val=%x, SREG=%x\n", reg_d, cpssp->REGS[reg_d], res, cpssp->IO[SREG]);			
							cpssp->REGS[reg_d] = res;
							break;
						case 0x1: //neg
							reg_d = (inst&0x1f0)>>4;							
							res = 0x0 - cpssp->REGS[reg_d];
							sreg_val |= (!res)<<1; //zero-flag
							sreg_val |= (!res)^0x1; //carry-flag always set expect when res=0
							cpssp->IO[SREG] &= ~0x3;
							cpssp->IO[SREG] |= sreg_val&0x3;
							printf("neg: reg=%x, old_val=%x, new_val=%x, SREG=%x\n", reg_d, cpssp->REGS[reg_d], res, cpssp->IO[SREG]);			
							cpssp->REGS[reg_d] = res;
							break;
					}					
					if(!((inst&0xe)^0xe)){ //call
						inst = load_inst(flash);
						//save pc						
						STACK = ((flash->pc)&0xff00)>>8;
						STACK_dec;
						STACK = (flash->pc)&0xff;
						STACK_dec;
						set_pc(flash, inst);
						printf("call: sp=%x, pc=%x\n", ((cpssp->IO[SP_H])<<8)|(cpssp->IO[SP_L]), flash->pc);						 
					}else if(!((inst&0xe)^0xc)){ //jmp
						inst = load_inst(flash);
						set_pc(flash, inst);
						printf("jmp to pc=%x\n", flash->pc);
					}
					if(((inst&0xf00)>>8) == 0x4){ //bclr: cli
						if((inst&0xf) == 0x8){
							switch((inst&0xf0)>>4){
								case 0x0: //sec
									printf("sec: not implemented\n");
									break;
							}
							if(inst&0x80){//bclr
								cpssp->IO[SREG] &= ~((0x1)<<((inst&0x70)>>4));
								printf("bclr: s=%x\n", (inst&0x70)>>4);
							}
						}
					} else { //0x5
						if((inst&0xf) == 0x8){
							switch((inst&0xf0)>>4){
								case 0x0: //ret
									STACK_inc;
									val_16 = STACK;
									STACK_inc;
									val_16 |= (STACK)<<8;
									set_pc(flash, val_16);
									printf("ret: sp=%x, pc=%x\n", (cpssp->IO[SP_H]<<8)|cpssp->IO[SP_L], val_16);
									break;
							}
						} 
					}
					break;
				case 0x6: case 0x7://adiw, sbiw
					sreg_val=0;					
					reg_d = 0x18|((inst&0x30)>>3);
					val_16 = (inst&0xf)|((inst&0xc0)>>2);
					if(inst&0x100){ //sbiw
						val_16 = ((cpssp->REGS[reg_d+1]<<8)|cpssp->REGS[reg_d])-val_16;
						sreg_val |= ((val_16>>8)&(~cpssp->REGS[reg_d+1]))>>7; //carry-flag sbiw		
						printf("sbiw: ");
					}else{ //adiw
						val_16 = ((cpssp->REGS[reg_d+1]<<8)|cpssp->REGS[reg_d])+val_16;
						sreg_val |= ((~(val_16>>8))&(cpssp->REGS[reg_d+1]))>>7;						
						printf("adiw: ");
					}
					if(!val_16) sreg_val |= 0x2; //zero-flag
					cpssp->REGS[reg_d] = val_16&0xff;
					cpssp->REGS[reg_d+1] = (val_16&0xff00)>>8;
					cpssp->IO[SREG] &= ~0x3;
					cpssp->IO[SREG] |= sreg_val&0x3;
					printf("reg=%x, val=%x, SREG=%x\n", reg_d, (cpssp->REGS[reg_d+1]<<8)|cpssp->REGS[reg_d], cpssp->IO[SREG]);								
					break;
				case 0xc: case 0xd: case 0xe: case 0xf: //mul
					sreg_val = 0;
					reg_r = (inst&0xf)|((inst&0x200)>>5);
					reg_d = (inst&0x1f0)>>4;
					val_16 = cpssp->REGS[reg_d]*cpssp->REGS[reg_r];
					cpssp->REGS[0] = val_16&0xff;
					cpssp->REGS[1] = (val_16&0xff00)>>8;
					sreg_val |= (!val_16)<<1;
					sreg_val |= val_16>>15;
					cpssp->IO[SREG] &= ~0x3;
					cpssp->IO[SREG] |= sreg_val&0x3;
					printf("mul: reg_d=%x, reg_r=%x, d_val=%x, r_val=%x, res=%x, SREG=%x\n",
								reg_d, reg_r, cpssp->REGS[reg_d], cpssp->REGS[reg_r], val_16, cpssp->IO[SREG]);
					break;
			}
			break; //case 0x9
		
		case 0x8:case 0xa: //std, ldd (with displacement)
			reg_r = (inst>>4)&0x1f;			
			reg_val_r = cpssp->REGS[reg_r];
			disp = (inst&0x7)|((inst>>7)&0x18)|((inst>>8)&0x20);						
			if(inst & 0x200){ //10th bit //std
				if(inst & 0x8){ //std Y+q
					val_16 = (cpssp->REGS[Y_HIGH]<<8)|cpssp->REGS[Y_LOW];
					printf("std Y+q: reg_r=%x, reg_val_r=%x, addr=%x, disp=%x\n", reg_r, reg_val_r, val_16, disp);
				}else{ //std Z+q
					val_16 = (cpssp->REGS[Z_HIGH]<<8)|cpssp->REGS[Z_LOW];
					printf("std Z+q: reg_r=%x, reg_val_r=%x, addr=%x, disp=%x\n", reg_r, reg_val_r, val_16, disp);
				}
				if(val_16+disp>=0x60) {sram->SRAM[val_16+disp] = reg_val_r;}
				else if(val_16+disp>=0x20) {
					cpssp->IO[val_16+disp-0x20] = reg_val_r;
					if(val_16+disp-0x20 == 0x0c) fprintf(stderr, "%c", reg_val_r);
				}
				else {cpssp->REGS[val_16+disp] = reg_val_r;}
			} else { //ldd
				if(inst & 0x8){ //ldd Y+q
					val_16 = (cpssp->REGS[Y_HIGH]<<8)|cpssp->REGS[Y_LOW];
					printf("ldd Y+q: dest=%x, reg_val_r=%x, addr=%x, disp=%x, ", reg_r, reg_val_r, val_16, disp);
				}else{ //ldd Z+q
					val_16 = (cpssp->REGS[Z_HIGH]<<8)|cpssp->REGS[Z_LOW];
					printf("ldd Z+q: dest=%x, reg_val_r=%x, addr=%x, disp=%x, ", reg_r, reg_val_r, val_16, disp);
				}
				if(val_16+disp>=0x60) {cpssp->REGS[reg_r] = sram->SRAM[val_16+disp];}
				else if(val_16+disp>=0x20) {cpssp->REGS[reg_r] = cpssp->IO[val_16+disp-0x20];}
				else {cpssp->REGS[reg_r] = cpssp->REGS[val_16+disp];}
				printf("val=%x\n", cpssp->REGS[reg_r]);
				break;		
			}
			break;
		
		case 0x2: //and, eor, mov, or
			reg_r = (inst&0xf)|((0x200&inst)>>5);
			reg_d = (inst>>4)&0x1f;
			sreg_val = 0; reg_val_r=cpssp->REGS[reg_r];
			switch((inst&0xc00)>>10){
				case 0x0: //and
					cpssp->REGS[reg_d] &= reg_val_r;
					if(!(cpssp->REGS[reg_d])) sreg_val|=0x2; //zero flag
					printf("and: src=%x, dest=%x, val=%x\n", reg_r, reg_d, cpssp->REGS[reg_d]);
					break;
				case 0x1: //eor
					cpssp->REGS[reg_d] ^= reg_val_r;
					if(!(cpssp->REGS[reg_d])) sreg_val|=0x2; 
					printf("eor: src=%x, dest=%x, val=%x\n", reg_r, reg_d, cpssp->REGS[reg_d]);
					break;
				case 0x2: //or
					cpssp->REGS[reg_d] |= reg_val_r;
					if(!(cpssp->REGS[reg_d])) sreg_val|=0x2; 
					printf("or: src=%x, dest=%x, val=%x\n", reg_r, reg_d, cpssp->REGS[reg_d]);
					break;
				case 0x3: //mov
					cpssp->REGS[reg_d] = reg_val_r;
					printf("mov: src=%x, dest=%x, val=%x\n", reg_r, reg_d, cpssp->REGS[reg_d]);
					return; //ret, because we don't have to set any flags	
			}
			//and, eor, or
			cpssp->IO[SREG] &= ~(0x2);
			cpssp->IO[SREG] |= sreg_val&0x2;
			break;

		case 0xb: //in, out
			if(inst & 0x800){ //out
				reg_d = ((inst&0x600)>>5)|(inst&0xf);				
				printf("out: dest=%x, src=%x, val=%x\n",((inst&0x600)>>5)|(inst&0xf), (inst & 0x01f0)>>4, cpssp->REGS[(inst & 0x01f0)>>4]);
				cpssp->IO[((inst&0x600)>>5)|(inst&0xf)] = cpssp->REGS[(inst & 0x01f0)>>4];
				if(reg_d==0x0c) fprintf(stderr, "%c",cpssp->IO[reg_d]);//debug output
			} else { //in
				cpssp->REGS[(inst & 0x01f0)>>4] = cpssp->IO[((inst&0x600)>>5)|(inst&0xf)];
				printf("in: dest=%x, src=%x, val=%x\n", (inst & 0x01f0)>>4, ((inst&0x600)>>5)|(inst&0xf), cpssp->IO[((inst&0x600)>>5)|(inst&0xf)]);
			}
			break;

		case 0xe: //ldi
			printf("ldi: dest=%x, value=%x\n", ((inst&0xf0)>>4)|0x10, (inst&0xf) | ((inst&0xf00)>>4));
			cpssp->REGS[((inst&0xf0)>>4)|0x10] = (inst&0xf) | ((inst&0xf00)>>4);
			break;

		case 0xc: //rjmp
			val_signed = (!(inst&0x800))*(inst&0x7ff) - (!(!(inst&0x800)))*(((~inst)&0x7ff)+1);
			printf("rjmp: pc=pc%+d\n",val_signed); 
			set_pc(flash, flash->pc+val_signed);			
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

		case 0x0: //add, cpc, nop, movw
			sreg_val = 0;			
			switch((inst & 0xc00)>>10){
				case 0x3: //add
					reg_d = (inst&0x1f0)>>4;
					reg_r = (inst&0xf)|((inst&0x200)>>5);
					res = cpssp->REGS[reg_d] + cpssp->REGS[reg_r];
					sreg_val |= (!res)<<1; //zero-flag
					sreg_val |= ((cpssp->REGS[reg_d]&cpssp->REGS[reg_r]) ^ ((~res)&cpssp->REGS[reg_r]) ^ ((~res)&cpssp->REGS[reg_d]))>>7; //carry-flag
					cpssp->IO[SREG] &= ~0x3;
					cpssp->IO[SREG] |= (sreg_val&0x3);
					printf("add: src=%x, dest=%x, src_val=%x, dest_val=%x, res=%x, SREG=%x\n", reg_r, reg_d, cpssp->REGS[reg_r], cpssp->REGS[reg_d], res, cpssp->IO[SREG]);
					cpssp->REGS[reg_d] = res;					
					break;
				case 0x1: //cpc				
					reg_val_d = cpssp->REGS[(inst>>4)&0x1f];
					reg_val_r = cpssp->REGS[(inst&0xf)|((0x200&inst))>>5];
					res = reg_val_d - reg_val_r - (cpssp->IO[SREG]&0x1);
					sreg_val |= ((!res)&&(cpssp->IO[SREG]&0x2))<<1; //zero-flag
					sreg_val |= (((~reg_val_d)&reg_val_r) ^ (res&reg_val_r) ^ (res&(~reg_val_d)))>>7; //carry-flag
					//TODO: other flags, 0x3 is the mask for set or cleared flags		
					cpssp->IO[SREG] &= ~0x3;
					cpssp->IO[SREG] |= (sreg_val&0x3);
					printf("cpc: reg_d=%x, reg_r=%x, res=%x, SREG=%x\n",reg_val_d, reg_val_r, res, cpssp->IO[SREG]);
					break;
				case 0x0: //nop, movw
					if (!inst){ //nop
						printf("nop\n");
						return;
					}
					if ((inst & 0x300)==0x100){ //movw
						reg_d = (inst & 0xf0)>>3;
						reg_r = (inst & 0xf)<<1;
						cpssp->REGS[reg_d] = cpssp->REGS[reg_r];
						cpssp->REGS[reg_d+1] = cpssp->REGS[reg_r+1];
						printf("movw: src=%x, dest=%x, word=%x\n", reg_r, reg_d, (cpssp->REGS[reg_d+1]<<8)|cpssp->REGS[reg_d]);
					}
					break;
				case 0x2: //sbc
					sreg_val = 0;
					reg_d = (inst&0x1f0)>>4;
					reg_r = (inst&0xf)|((inst&0x200)>>5);
					reg_val_r = cpssp->REGS[reg_r];
					reg_val_d = cpssp->REGS[reg_d];
					res = reg_val_d - reg_val_r - (cpssp->IO[SREG]&0x1);
					sreg_val |= (!res)>>1; //zero-flag
					sreg_val |= ((~reg_val_d)&reg_val_r)^(reg_val_r&res)^(res&(~reg_val_d));
					cpssp->IO[SREG] &= ~0x3;
					cpssp->IO[SREG] |= sreg_val&0x3;
					printf("sbc: reg_d=%x, reg_r=%x, val_d=%x, val_r=%x, res=%x, SREG=%x\n", 
							  reg_d, reg_r, reg_val_d, reg_val_r, res, cpssp->IO[SREG]);
					cpssp->REGS[reg_d] = res;
					break;
			}
			break;
		case 0xf: //bld, bst, sbrc, sbrs, brbc, brbs
			if(inst&0x800){ //bld, bst, sbrc, sbrs
			
			}else{ //brbc, brbs
				val_16 = (inst&0x3f8)>>3; //pc_offset
				//printf("(!(inst&0x400))=%x, !(cpssp->IO[SREG]&(0x1<<(inst&0x7)))=%x\n", !(inst&0x400), !(cpssp->IO[SREG]&(0x1<<(inst&0x7))));
				val_signed = (((val_16&0x40)>>6)!=1)*((val_16&0x3f)) - ((val_16&0x40)>>6)*(((~val_16)&0x3f)+1);
				if((!(inst&0x400)) != (!(cpssp->IO[SREG]&(0x1<<(inst&0x7))))){
					flash->pc += val_signed;
					printf("brbc, brbs: pc=pc%+d, bit=%x, SREG=%x, (cl=1, set=0)=%x\n",val_signed, inst&0x7, cpssp->IO[SREG], (inst&0x400)>>10); 
				}else{
					printf("brbc, brbs: condition fulfilled: SREG(%x), SREG=%x, (cl=1, set=0)=%x\n", inst&0x7, cpssp->IO[SREG], (inst&0x400)>>10);		
				}
			}
			break;

		case 0xd: //rcall
			STACK = ((flash->pc)&0xff00)>>8;
			STACK_dec;
			STACK = flash->pc&0xff;
			STACK_dec;
			set_pc(flash, flash->pc+(inst&0xfff));
			printf("rcall: pc=%x, sp=%x\n", flash->pc, (cpssp->IO[SP_H]<<8)|cpssp->IO[SP_L]);
			break;
		case 0x4: //sbci
			sreg_val = 0;
			reg_d = 0x10|((inst&0xf0)>>4);
			im_val = ((inst&0xf00)>>4)|(inst&0xf);
			res = cpssp->REGS[reg_d]-im_val-(cpssp->IO[SREG]&0x1);
			sreg_val |= ((!res)&&(cpssp->IO[SREG]&0x2))<<1; //zero-flag
			sreg_val |= (((~cpssp->REGS[reg_d])&im_val) ^ (res&im_val) ^ (res&(~cpssp->REGS[reg_d])))>>7; //carry-flag
			//TODO: other flags, 0x3 is the mask for set or cleared flags		
			cpssp->IO[SREG] &= ~0x3;
			cpssp->IO[SREG] |= (sreg_val&0x3);
			cpssp->REGS[reg_d] = res;
			printf("sbci: reg_d=%x, val=%x, res=%x, SREG=%x\n", reg_d, im_val, res, cpssp->IO[SREG]);
			break;
		case 0x5: //subi
			sreg_val = 0;
			reg_d = 0x10|((inst&0xf0)>>4);
			im_val = ((inst&0xf00)>>4)|(inst&0xf);
			res = cpssp->REGS[reg_d]-im_val;
			sreg_val |= (!res)<<1; //zero-flag
			sreg_val |= (((~cpssp->REGS[reg_d])&im_val) ^ (res&im_val) ^ (res&(~cpssp->REGS[reg_d])))>>7; //carry-flag
			//TODO: other flags, 0x3 is the mask for set or cleared flags		
			cpssp->IO[SREG] &= ~0x3;
			cpssp->IO[SREG] |= (sreg_val&0x3);
			cpssp->REGS[reg_d] = res;
			printf("subi: reg_d=%x, val=%x, res=%x, SREG=%x\n", reg_d, im_val, res, cpssp->IO[SREG]);
			break;

		case 0x1: //adc, cp, cpse, sub
			sreg_val=0;			
			reg_d = (inst&0x1f0)>>4;
			reg_r = (inst&0xf)|((inst&0x200)>>5);
			switch((inst&0xc00)>>10){
				case 0x0: //cpse
					if(cpssp->REGS[reg_d]-cpssp->REGS[reg_r]){ //not equal: do nothing
					} else {
						set_pc(flash, flash->pc+1);
					}
					sreg_val = cpssp->IO[SREG];
					printf("cpse: src=%x, dest=%x, src_val=%x, dest_val=%x\n", reg_r, reg_d, cpssp->REGS[reg_r], cpssp->REGS[reg_d]);
					break;
				case 0x1: case 0x2: //cp, sub
					res = cpssp->REGS[reg_d] - cpssp->REGS[reg_r];
					sreg_val |= (!res)<<1; //zero-flag
					sreg_val |= (((~cpssp->REGS[reg_d])&cpssp->REGS[reg_r]) ^ (res&cpssp->REGS[reg_r]) ^ (res&(~cpssp->REGS[reg_d])))>>7; //carry-flag
					if(inst&0x800){ //sub
						cpssp->REGS[reg_d] = res;
						printf("(sub) ");
					}					
					printf("cp: src=%x, dest=%x, src_val=%x, dest_val=%x, SRAM=%x\n", reg_r, reg_d, cpssp->REGS[reg_r], cpssp->REGS[reg_d], sreg_val);					
					break;

				case 0x3: //adc
					res = cpssp->REGS[reg_d] + cpssp->REGS[reg_r] + (cpssp->IO[SREG]&0x1);
					sreg_val |= (!res)<<1; //zero-flag
					sreg_val |= ((cpssp->REGS[reg_d]&cpssp->REGS[reg_r]) ^ ((~res)&cpssp->REGS[reg_r]) ^ ((~res)&cpssp->REGS[reg_d]))>>7; //carry-flag
					printf("adc: src=%x, dest=%x, src_val=%x, dest_val=%x, res=%x\n", reg_r, reg_d, cpssp->REGS[reg_r], cpssp->REGS[reg_d], res);					
					cpssp->REGS[reg_d] = res;					
					break;
			}
			cpssp->IO[SREG] &= ~(0x3);
			cpssp->IO[SREG] |= sreg_val&0x3;
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
	struct cpssp *cpssp = (struct cpssp*)malloc(sizeof(struct cpssp));
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
	cpssp->IO[SP_L] = (SRAMSIZE-1)&0xff;
	cpssp->IO[SP_H] = ((SRAMSIZE-1)&0xff00)>>8;
	printf("sp_h=%x, sp_l=%x\n", ((SRAMSIZE-1)&0xff00)>>8, (SRAMSIZE-1)&0xff);
	return cpssp;
}

void
chip_atmel_atmega32_destroy(void *_cpssp)
{
	struct cpssp *cpssp = _cpssp;

	/* FIXME */

	free(cpssp);
}
