
#include "sram.h"


struct sram *new_sram(void) {
	struct sram *sram;
	sram = malloc(sizeof(struct sram));
	for (int i=0; i<SRAMSIZE; i++){
		sram->SRAM[i] = 0;	
	}
	return sram;
}

void sram_destroy(struct sram *sram){
	free(sram);
}

