#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui.h"

#include "button.h"

struct cpssp {
	GtkWidget *gui_button;

	struct sig_std_logic *port;
};

static gboolean
button_pressed(GtkWidget *w, GdkEventButton *event, gpointer _cpssp)
{
	struct cpssp *cpssp = _cpssp;

	sig_std_logic_set(cpssp->port, cpssp, SIG_STD_LOGIC_0);

	return FALSE;
}

static gboolean
button_released(GtkWidget *w, GdkEventButton *event, gpointer _cpssp)
{
	struct cpssp *cpssp = _cpssp;

	sig_std_logic_set(cpssp->port, cpssp, SIG_STD_LOGIC_Z);

	return FALSE;
}

void *
button_create(const char *name, struct sig_std_logic *port)
{
	struct cpssp *cpssp;

	cpssp = malloc(sizeof(*cpssp));
	assert(cpssp);

	cpssp->gui_button = gtk_button_new();
	g_signal_connect(cpssp->gui_button, "button-press-event",
		      G_CALLBACK(button_pressed), (gpointer) cpssp);
	g_signal_connect(cpssp->gui_button, "button-release-event",
		      G_CALLBACK(button_released), (gpointer) cpssp);

	gtk_widget_show(cpssp->gui_button);

	gui_add(name, cpssp->gui_button);

	cpssp->port = port;
	sig_std_logic_connect_out(cpssp->port, cpssp, SIG_STD_LOGIC_Z);

	return cpssp;
}

void
button_destroy(void *_cpssp)
{
	struct cpssp *cpssp = _cpssp;

	free(cpssp);
}
