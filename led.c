#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include "gui.h"
#include "led.h"

struct cpssp {
	GdkPixbuf *icon[2];
	GtkWidget *widget;

	int state_a;
	int state_c;
};

static void
led_draw(GdkPixbuf *pixbuf, unsigned int r, unsigned int g, unsigned int b)
{
	int width, height, rowstride;
	guchar *pixels, *p;
	unsigned int x, y;

	assert(gdk_pixbuf_get_n_channels(pixbuf) == 4);
	assert(gdk_pixbuf_get_colorspace(pixbuf) == GDK_COLORSPACE_RGB);
	assert(gdk_pixbuf_get_bits_per_sample(pixbuf) == 8);
	assert(gdk_pixbuf_get_has_alpha(pixbuf));

	width = gdk_pixbuf_get_width(pixbuf);
	height = gdk_pixbuf_get_height(pixbuf);
	rowstride = gdk_pixbuf_get_rowstride(pixbuf);
	pixels = gdk_pixbuf_get_pixels(pixbuf);

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			int d2;

			p = pixels + y * rowstride + x * 4;
			d2 = (x-width/2)*(x-width/2) + (y-height/2)*(y-height/2);
			if (d2 <= ((width-4)/2)*((width-4)/2)) {
				/* Circle */
				p[0] = r;
				p[1] = g;
				p[2] = b;
				p[3] = 0xff;
			} else if (d2 <= (width/2)*(width/2)) {
				/* Frame */
				p[0] = 0x00;
				p[1] = 0x00;
				p[2] = 0x00;
				p[3] = 0xff;
			} else {
				/* Outside */
				p[0] = 0;
				p[1] = 0;
				p[2] = 0;
				p[3] = 0x00;
			}
		}
	}
}

static void
led_update(struct cpssp *cpssp)
{
	GdkPixbuf *icon;

	if (cpssp->state_c < cpssp->state_a) {
		icon = cpssp->icon[1];
	} else {
		icon = cpssp->icon[0];
	}

	gtk_image_set_from_pixbuf(GTK_IMAGE(cpssp->widget), icon);
	
}

static void
led_a_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	cpssp->state_a = val;

	led_update(cpssp);
}

static void
led_c_set(void *_cpssp, unsigned int val)
{
	struct cpssp *cpssp = _cpssp;

	cpssp->state_c = val;

	led_update(cpssp);
}

void *
led_create(
	const char *name,
	int r,
	int g,
	int b,
	struct sig_std_logic *port_a,
	struct sig_std_logic *port_c
)
{
	static const struct sig_std_logic_funcs port_a_funcs = {
		.boolean_or_set = led_a_set,
	};
	static const struct sig_std_logic_funcs port_c_funcs = {
		.boolean_or_set = led_c_set,
	};
	struct cpssp *cpssp;

	assert(0xff <= r + g + b);

	cpssp = malloc(sizeof(*cpssp));
	assert(cpssp);

	cpssp->icon[0] = gdk_pixbuf_new(GDK_COLORSPACE_RGB, 1, 8, 16, 16);
	assert(cpssp->icon[0]);
	led_draw(cpssp->icon[0], 0, 0, 0);
	cpssp->icon[1] = gdk_pixbuf_new(GDK_COLORSPACE_RGB, 1, 8, 16, 16);
	assert(cpssp->icon[1]);
	led_draw(cpssp->icon[1], r, g, b);

	cpssp->widget = gtk_image_new();
	gtk_image_set_from_pixbuf(GTK_IMAGE(cpssp->widget), cpssp->icon[1]);
	gtk_widget_show(cpssp->widget);

	gui_add(name, cpssp->widget);

	cpssp->state_a = 0;
	sig_std_logic_connect_in(port_a, cpssp, &port_a_funcs);
	cpssp->state_c = 0;
	sig_std_logic_connect_in(port_c, cpssp, &port_c_funcs);

	return cpssp;
}

void
led_destroy(void *_cpssp)
{
	struct cpssp *cpssp = _cpssp;

	free(cpssp);
}
