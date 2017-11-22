#include <gtk/gtk.h>

extern void
gui_add(const char *name, GtkWidget *w);

extern void
gui_step(void);

extern void
gui_flush(void);

extern void
gui_init(int *argcp, char ***argvp);
extern void
gui_exit(void);
