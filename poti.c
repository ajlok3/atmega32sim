#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui.h"
#include "poti.h"

struct cpssp {
	struct sig_std_logic *port_middle;

	int state_adj;
	int state_left;
	int state_right;
};

static void
poti_update(struct cpssp *cpssp)
{
	unsigned int mV;

	mV = cpssp->state_left
		+ (cpssp->state_right - cpssp->state_left) * cpssp->state_adj / 100.0;

	sig_std_logic_set(cpssp->port_middle, cpssp, SIG_COMB(mV, -1));
}

static void
poti_adj(GtkAdjustment *adj, gpointer _cpssp)
{
	struct cpssp *cpssp = _cpssp;

	cpssp->state_adj = (int) adj->value;

	poti_update(cpssp);
}

static void
poti_left_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	cpssp->state_left = SIG_mV(val);

	poti_update(cpssp);
}

static void
poti_right_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	cpssp->state_right = SIG_mV(val);

	poti_update(cpssp);
}

void *
poti_create(
	const char *name,
	struct sig_std_logic *port_left,
	struct sig_std_logic *port_middle,
	struct sig_std_logic *port_right
)
{
	static const struct sig_std_logic_funcs left_funcs = {
		.std_logic_set = poti_left_set,
	};
	static const struct sig_std_logic_funcs right_funcs = {
		.std_logic_set = poti_right_set,
	};
	struct cpssp *cpssp;
	GtkAdjustment *adj;
	GtkWidget *scale;

	cpssp = malloc(sizeof(*cpssp));
	assert(cpssp);

	adj = (GtkAdjustment *) gtk_adjustment_new(0.0, /* value */
			0.0, /* lower */
			110.0, /* upper + page size */
			5.0, /* step increment */
			10.0, /* page increment */
			10.0 /* page size */);
	g_signal_connect(adj, "value_changed",
			G_CALLBACK(poti_adj), cpssp);
	scale = gtk_hscale_new(adj);
	gtk_widget_show(scale);

	gui_add(name, scale);

	cpssp->state_adj = 0;
	cpssp->state_left = 0;
	cpssp->state_right = 0;

	cpssp->port_middle = port_middle;
	sig_std_logic_connect_out(cpssp->port_middle, cpssp, SIG_STD_LOGIC_0);

	sig_std_logic_connect_in(port_left, cpssp, &left_funcs);
	sig_std_logic_connect_in(port_right, cpssp, &right_funcs);

	return cpssp;
}

void
poti_destroy(void *_cpssp)
{
	struct cpssp *cpssp = _cpssp;

	free(cpssp);
}
