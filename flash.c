#include "flash.h"


struct flash *new_flash(void){
	struct flash *flash;
	flash = (struct flash*)malloc(sizeof(struct flash));
	for(int i=0; i<FLASHSIZE; i++){
		flash->FLASH[i]=0;
	}
	flash->pc=0;
	return flash;
}
void flash_destroy(struct flash *flash){
	free(flash);
}
int flash_binary(char *filename, struct flash *flash){
	FILE *elf = fopen(filename, "r+b");
	if(!elf){
		fprintf(stderr, "flash_binary: No file found with filename %s",filename);
		return 1;
	}
	uint32_t *prog_pos = malloc(sizeof(uint32_t));
	uint32_t *text_pos = malloc(sizeof(uint32_t));
	uint32_t *text_off = malloc(sizeof(uint32_t));
	uint32_t *data_pos = malloc(sizeof(uint32_t));
	uint32_t *data_off = malloc(sizeof(uint32_t));
	uint32_t *magic = malloc(sizeof(uint32_t));
	int i;
	fread(magic, sizeof(uint8_t), 4, elf); //read ELF-magic
	if(*magic != 0x464c457f){ //not ELF-magic
		fprintf(stderr, "\"%s\"is not a valid ELF-file\n", filename);
		fprintf(stderr, "%x\n", *magic);
		return 1;	
	}

	//Program header position
	fseek(elf, 0x1c, SEEK_SET);
	fread(prog_pos, sizeof(uint16_t), 2, elf);
	

	//Textposition: 4th byte of program header
	fseek(elf, *prog_pos+4, SEEK_SET);
	fread(text_pos, sizeof(uint16_t), 2, elf);
	
	//Textoffset
	fseek(elf, *prog_pos+16, SEEK_SET);
	fread(text_off, sizeof(uint16_t), 2, elf);

	fseek(elf, *text_pos, SEEK_SET);	 
	fread(flash->FLASH, sizeof(uint16_t), (*text_off)/2, elf);
	for(i=0; i<(*text_off)/2; i++){
		printf("Flash[%x]=0x%x\n",i,flash->FLASH[i]);
	}
	
	//shift 32byte : Data header
	*prog_pos += 32;

	//Data position
	fseek(elf, *prog_pos+4, SEEK_SET);
	fread(data_pos, sizeof(uint16_t), 2, elf);
	//printf("data_pos: %x\n", *data_pos);

	//Data offset
	fseek(elf, *prog_pos+16, SEEK_SET);
	fread(data_off, sizeof(uint16_t), 2, elf);
	//printf("data_off: %x\n", *data_off);

	fseek(elf, *data_pos, SEEK_SET);	 
	fread((flash->FLASH)+i, sizeof(uint16_t), (*data_off)/2, elf);
	
	for(; i<(*data_off)/2 + (*text_off)/2; i++){
		printf("Flash[%x]=0x%x\n",i,flash->FLASH[i]);
	}

	free(prog_pos);
	free(text_pos);
	free(text_off);
	free(data_pos);
	free(data_off);
	free(magic);
	fclose(elf);
	return 0;
}	

uint16_t load_inst(struct flash *flash){
	//printf("flash->pc: %x\n", flash->pc);
	uint16_t inst = flash->FLASH[flash->pc];
	flash->pc++;
	return inst;
}
void set_pc(struct flash *flash, uint32_t pc){
	flash->pc = pc;
}
