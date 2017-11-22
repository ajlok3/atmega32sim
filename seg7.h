#include "sig_std_logic.h"

extern void
seg7_step(void *_cpssp);

extern void *
seg7_create(
	const char *name, 
	struct sig_std_logic *port_e,
	struct sig_std_logic *port_d,
	struct sig_std_logic *port_anode0,
	struct sig_std_logic *port_c,
	struct sig_std_logic *port_dp,
	struct sig_std_logic *port_b,
	struct sig_std_logic *port_a,
	struct sig_std_logic *port_anode1,
	struct sig_std_logic *port_f,
	struct sig_std_logic *port_g
);
extern void
seg7_destroy(void *_cpssp);
