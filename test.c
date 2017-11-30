#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char**argv){
	
	for(int j=0;j<400;j++){
		uint8_t i = (uint8_t)j;
		uint8_t res = 0x0-i;
		printf("neg(%x)=%x, com(%x)=%x\n", i, res, i, (~i)&0xff);	
	}
	return 0;
}
