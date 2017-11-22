#include "sig_std_logic.h"

extern void *
poti_create(
	const char *name,
	struct sig_std_logic *port_left,
	struct sig_std_logic *port_middle,
	struct sig_std_logic *port_right
);
extern void
poti_destroy(void *_cpssp);
