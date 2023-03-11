#include <gtk/gtk.h>
#include "sudoku_app.h"
#include "sudoku_app_win.h"

struct _SudokuApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(SudokuApp, sudoku_app, GTK_TYPE_APPLICATION);

static void sudoku_app_init(SudokuApp *app) {
    return;
}

static void sudoku_app_activate(GApplication *app) {
    SudokuAppWindow *win;

    win = sudoku_app_window_new(SUDOKU_APP(app));
    gtk_window_present(GTK_WINDOW(win));
}

static void sudoku_app_open(GApplication *app, GFile **files, gint n_files,
                            const gchar *hint) {
    GList *windows;
    SudokuAppWindow *win;
    int i;

    windows = gtk_application_get_windows(GTK_APPLICATION(app));
    if (windows)
        win = SUDOKU_APP_WINDOW(windows->data);
    else
        win = sudoku_app_window_new(SUDOKU_APP(app));

    for (i = 0; i < n_files; i++) {
        sudoku_app_window_open(win, files[i]);
    }

    gtk_window_present(GTK_WINDOW(win));
}

static void sudoku_app_class_init(SudokuAppClass *class) {
    G_APPLICATION_CLASS(class)->activate = sudoku_app_activate;
    G_APPLICATION_CLASS(class)->open = sudoku_app_open;
}

SudokuApp *sudoku_app_new(void) {
    return g_object_new(SUDOKU_APP_TYPE,
                        "application-id", "org.gtk.sudokuapp",
                        "flags", G_APPLICATION_HANDLES_OPEN,
                        NULL);
}
