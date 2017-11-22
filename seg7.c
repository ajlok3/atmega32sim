#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui.h"
#include "seg7.h"

#define OFFX    5
#define OFFY    5
#define LX      20
#define LY      20
#define LSPACE  16
#define DX      (LX + LSPACE)

struct cpssp {
	GtkWidget *gui_area;

	int sum_seg[8];
	int state_seg[8];
	int state_anode;
};

static void
seg7_hor(
        GtkWidget *widget,
        int state,
        gint x,
        gint y
)
{       
        GdkGC *gc = state 
                        ? widget->style->fg_gc[widget->state]
                        : widget->style->bg_gc[widget->state];
        
        gdk_draw_line(widget->window, gc, 
                        x + 4, y - 2, x + LX - 4, y - 2);
        gdk_draw_line(widget->window, gc, 
                        x + 3, y - 1, x + LX - 3, y - 1);
        gdk_draw_line(widget->window, gc,
                        x + 2, y, x + LX - 2, y);
        gdk_draw_line(widget->window, gc, 
                        x + 3, y + 1, x + LX - 3, y + 1);
        gdk_draw_line(widget->window, gc, 
                        x + 4, y + 2, x + LX - 4, y + 2);
}

static void
seg7_vert(
        GtkWidget *widget,
        int state,
        gint x,
        gint y
)
{       
        GdkGC *gc = state 
                        ? widget->style->fg_gc[widget->state]
                        : widget->style->bg_gc[widget->state];
        
        gdk_draw_line(widget->window, gc, 
                        x - 2, y + 4, x - 2, y + LY - 4);
        gdk_draw_line(widget->window, gc, 
                        x - 1, y + 3, x - 1, y + LY - 3);
        gdk_draw_line(widget->window, gc,
                        x, y + 2, x, y + LY - 2);
        gdk_draw_line(widget->window, gc, 
                        x + 1, y + 3, x + 1, y + LY - 3);
        gdk_draw_line(widget->window, gc, 
                        x + 2, y + 4, x + 2, y + LY - 4);
}

static void
seg7_dot(
        GtkWidget *widget,
        int state,
        gint x,
        gint y
)
{       
        GdkGC *gc = state 
                        ? widget->style->fg_gc[widget->state]
                        : widget->style->bg_gc[widget->state];
        
        gdk_draw_line(widget->window, gc, 
                        x - 2, y - 2, x + 2, y - 2);
        gdk_draw_line(widget->window, gc, 
                        x - 2, y - 1, x + 2, y - 1);
        gdk_draw_line(widget->window, gc, 
                        x - 2, y + 0, x + 2, y + 0);
        gdk_draw_line(widget->window, gc, 
                        x - 2, y + 1, x + 2, y + 1);
        gdk_draw_line(widget->window, gc, 
                        x - 2, y + 2, x + 2, y + 2);
}

static const struct {
	void (*func)(GtkWidget *widget, int state, gint x, gint y);
	gint x;
	gint y;
} seg7_table[8] = {
	/* A */  { seg7_hor, 0 * LX, 0 * LY },
	/* B */  { seg7_vert, 1 * LX, 0 * LY },
	/* C */  { seg7_vert, 1 * LX, 1 * LY },
	/* D */  { seg7_hor, 0 * LX, 2 * LY },
	/* E */  { seg7_vert, 0 * LX, 1 * LY },
	/* F */  { seg7_vert, 0 * LX, 0 * LY },
	/* G */  { seg7_hor, 0 * LX, 1 * LY },
	/* DP */ { seg7_dot, 1 * LX + LSPACE / 2, LY * 2 },
};

static int
seg7_expose(GtkWidget *w, GdkEventExpose *event, gpointer _cpssp)
{
	struct cpssp *cpssp = _cpssp;
	int i;

	if (0 < event->count) {
		return FALSE;
	}

	gdk_window_clear_area(cpssp->gui_area->window,
			0, 0,
			cpssp->gui_area->allocation.width,
			cpssp->gui_area->allocation.height);

	for (i = 0; i < 8; i++) {
		(*seg7_table[i].func)(cpssp->gui_area,
				cpssp->sum_seg[i],
				OFFX + seg7_table[i].x,
				OFFY + seg7_table[i].y);
	}

	return FALSE;
}

static void
seg7_N_set(void *_cpssp, int n, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	cpssp->state_seg[n] = 2000 < SIG_mV(val);
}

static void
seg7_a_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 0, val);
}

static void
seg7_b_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 1, val);
}

static void
seg7_c_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 2, val);
}

static void
seg7_d_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 3, val);
}

static void
seg7_e_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 4, val);
}

static void
seg7_f_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 5, val);
}

static void
seg7_g_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 6, val);
}

static void
seg7_dp_set(void *_cpssp, unsigned int val)
{
	seg7_N_set(_cpssp, 7, val);
}

static void
seg7_anode_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	cpssp->state_anode = 2000 < SIG_mV(val);
}

void
seg7_step(void *_cpssp)
{
	static int count = 0;
	struct cpssp *cpssp = _cpssp;
	int i;

	for (i = 0; i < 8; i++) {
		cpssp->sum_seg[i] += cpssp->state_seg[i] < cpssp->state_anode;
	}

	if (count++ < 10000) {
		return;
	}
	count = 0;

	for (i = 0; i < 8; i++) {
		(*seg7_table[i].func)(cpssp->gui_area,
				10000 / 4 < cpssp->sum_seg[i],
				OFFX + seg7_table[i].x,
				OFFY + seg7_table[i].y);
		cpssp->sum_seg[i] = 0;
	}
}

void *
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
)
{
	static const struct sig_std_logic_funcs a_funcs = {
		.std_logic_set = seg7_a_set,
	};
	static const struct sig_std_logic_funcs b_funcs = {
		.std_logic_set = seg7_b_set,
	};
	static const struct sig_std_logic_funcs c_funcs = {
		.std_logic_set = seg7_c_set,
	};
	static const struct sig_std_logic_funcs d_funcs = {
		.std_logic_set = seg7_d_set,
	};
	static const struct sig_std_logic_funcs e_funcs = {
		.std_logic_set = seg7_e_set,
	};
	static const struct sig_std_logic_funcs f_funcs = {
		.std_logic_set = seg7_f_set,
	};
	static const struct sig_std_logic_funcs g_funcs = {
		.std_logic_set = seg7_g_set,
	};
	static const struct sig_std_logic_funcs dp_funcs = {
		.std_logic_set = seg7_dp_set,
	};
	static const struct sig_std_logic_funcs anode_funcs = {
		.std_logic_set = seg7_anode_set,
	};
	struct cpssp *cpssp;

	cpssp = malloc(sizeof(*cpssp));
	assert(cpssp);

	cpssp->gui_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(cpssp->gui_area,
			OFFX + LX + OFFX, OFFY + 2 * LY + OFFY);
	g_signal_connect(G_OBJECT(cpssp->gui_area), "expose_event",
			G_CALLBACK(seg7_expose), cpssp);
	gtk_widget_show(cpssp->gui_area);

	gui_add(name, cpssp->gui_area);

	sig_std_logic_connect_in(port_a, cpssp, &a_funcs);
	sig_std_logic_connect_in(port_b, cpssp, &b_funcs);
	sig_std_logic_connect_in(port_c, cpssp, &c_funcs);
	sig_std_logic_connect_in(port_d, cpssp, &d_funcs);
	sig_std_logic_connect_in(port_e, cpssp, &e_funcs);
	sig_std_logic_connect_in(port_f, cpssp, &f_funcs);
	sig_std_logic_connect_in(port_g, cpssp, &g_funcs);
	sig_std_logic_connect_in(port_dp, cpssp, &dp_funcs);
	sig_std_logic_connect_in(port_anode0, cpssp, &anode_funcs);

	return cpssp;
}

void
seg7_destroy(void *_cpssp)
{
	struct cpssp *cpssp = _cpssp;

	free(cpssp);
}
