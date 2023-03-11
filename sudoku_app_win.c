#include <gtk/gtk.h>
#include "sudoku_app.h"
#include "sudoku_app_win.h"

struct _SudokuAppWindow
{
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(SudokuAppWindow, sudoku_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void sudoku_app_window_init(SudokuAppWindow *app)
{
    return;
}

static void sudoku_app_window_class_init(SudokuAppWindowClass *class)
{
    return;
}

SudokuAppWindow *sudoku_app_window_new(SudokuApp *app)
{
    return g_object_new(SUDOKU_APP_WINDOW_TYPE, "application", app, NULL);
}

void sudoku_app_window_open(SudokuAppWindow *win, GFile *file)
{
    return;
}