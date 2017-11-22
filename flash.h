#ifndef FLASH_H
#define FLASH_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FLASHSIZE 2048

struct flash {
	uint16_t FLASH[FLASHSIZE];
	uint16_t pc;
};
struct flash *new_flash(void);
int flash_binary(char *filename, struct flash *flash);
void flash_destroy(struct flash *flash);
uint16_t load_inst(struct flash *flash);
void set_pc(struct flash *flash, uint32_t pc);
#endif
