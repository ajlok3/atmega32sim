#include "sig_std_logic.h"

extern void *
led_create(const char *name, int r, int g, int b,
		struct sig_std_logic *port_a, struct sig_std_logic *port_c);
extern void
led_destroy(void *_cpssp);
