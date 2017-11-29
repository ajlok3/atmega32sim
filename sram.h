#ifndef SRAM_H
#define SRAM_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SRAMSIZE 4096

struct sram {
	uint8_t SRAM[SRAMSIZE];	
};

struct sram *new_sram();
void sram_destroy(struct sram *sram);
#endif
