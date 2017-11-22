#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui.h"

extern int end;

static GtkWidget *window;
static GtkWidget *hbox;
static GMainContext *main_context;


static gboolean
gui_delete(GtkWidget *widget, GdkEvent *event, gpointer _unused)
{
	end = 1;

	return FALSE;
}

void
gui_add(const char *name, GtkWidget *w)
{
	GtkWidget *frame;

	frame = gtk_frame_new(name);

	gtk_container_add(GTK_CONTAINER(frame), w);
	gtk_widget_show(w);

	gtk_widget_show(frame);
	gtk_box_pack_start(GTK_BOX(hbox), frame, FALSE, FALSE, 0);
}

void
gui_step(void)
{
	GPollFD fds_gpoll[FD_SETSIZE];
	gint max_priority;
	int fds_length;
	gint timeout;

	g_main_context_acquire(main_context);

	g_main_context_prepare(main_context, &max_priority);

	fds_length = g_main_context_query(main_context,
			max_priority, &timeout, fds_gpoll, FD_SETSIZE);

	if (g_main_context_check(main_context, max_priority,
			fds_gpoll, fds_length)) {
		g_main_context_dispatch(main_context);
	}

	g_main_context_release(main_context);
}

void
gui_flush(void)
{
}

void
gui_init(int *argcp, char ***argvp)
{
	gtk_init(argcp, argvp);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "delete-event", G_CALLBACK(gui_delete), NULL);

	gtk_window_set_title(GTK_WINDOW(window), "VM");

	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	hbox = gtk_hbox_new(FALSE, 0);
	gtk_widget_show(hbox);
	gtk_container_add(GTK_CONTAINER(window), hbox);

	gtk_widget_show(window);

	main_context = g_main_context_default();
}

void
gui_exit(void)
{
}
