#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char**argv){
	
	uint16_t inst = 0xcea7;
	int val_signed = (!(inst&0x800))*(inst&0x7ff) - (!(!(inst&0x800)))*(((~inst)&0x7ff)+1);
	printf("val_signed = %+d\n", val_signed);
	return 0;
}
