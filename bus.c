#include <stdio.h>
#include <stdlib.h>
#include "bus.h"
#define NMEMBERS 10

struct bus_funcs {
	
	void (*in)(void* state, int port, uint8_t *valp);
	void (*out)(void* state, int port, uint8_t val);
	void (*load)(void* state, int addr, uint8_t valp*);
	void (*store)(void* state, int addr, uint8_t val);
};

struct bus {
	struct{
		void* state;
		struct bus_funcs *funcs;
	} member[NMEMBERS];
	unsigned int nmembers;
};

void *new_bus(){
	struct bus *bus = malloc(sizeof(*bus));	
	bus->nmembers = 0;
}

void bus_connect(struct bus *bus, void *state, struct bus_funcs *bus_funcs){
	bus->member[bus->nmembers].state = state;
	bus->member[bus->nmembers].bus_funcs = bus_funcs;
	nmembers++;
}




