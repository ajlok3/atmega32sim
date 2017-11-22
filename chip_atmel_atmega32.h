	
/*
 * WARNING:
 *
 * Automatically generated from chip_atmel_atmega32.sym.
 */

#include "sig_std_logic.h"
#include "sram.h"
#include "flash.h"

extern void
chip_atmel_atmega32_step(void *_cpssp);

void *
chip_atmel_atmega32_create(
	const char *name,
	struct sig_std_logic *port_pb0,
	struct sig_std_logic *port_pb1,
	struct sig_std_logic *port_pb2,
	struct sig_std_logic *port_pb3,
	struct sig_std_logic *port_pb4,
	struct sig_std_logic *port_pb5,
	struct sig_std_logic *port_pb6,
	struct sig_std_logic *port_pb7,
	struct sig_std_logic *port_nreset,
	struct sig_std_logic *port_vcc,
	struct sig_std_logic *port_gnd0,
	struct sig_std_logic *port_xtal2,
	struct sig_std_logic *port_xtal1,
	struct sig_std_logic *port_pd0,
	struct sig_std_logic *port_pd1,
	struct sig_std_logic *port_pd2,
	struct sig_std_logic *port_pd3,
	struct sig_std_logic *port_pd4,
	struct sig_std_logic *port_pd5,
	struct sig_std_logic *port_pd6,
	struct sig_std_logic *port_pd7,
	struct sig_std_logic *port_pc0,
	struct sig_std_logic *port_pc1,
	struct sig_std_logic *port_pc2,
	struct sig_std_logic *port_pc3,
	struct sig_std_logic *port_pc4,
	struct sig_std_logic *port_pc5,
	struct sig_std_logic *port_pc6,
	struct sig_std_logic *port_pc7,
	struct sig_std_logic *port_avcc,
	struct sig_std_logic *port_gnd1,
	struct sig_std_logic *port_aref,
	struct sig_std_logic *port_pa7,
	struct sig_std_logic *port_pa6,
	struct sig_std_logic *port_pa5,
	struct sig_std_logic *port_pa4,
	struct sig_std_logic *port_pa3,
	struct sig_std_logic *port_pa2,
	struct sig_std_logic *port_pa1,
	struct sig_std_logic *port_pa0,
	struct sram *sram,
	struct flash *flash
);
extern void
chip_atmel_atmega32_destroy(void *_cpssp);
