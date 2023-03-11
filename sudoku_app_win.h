#ifndef SUDOKU_APP_WIN_H
#define SUDOKU_APP_WIN_H

#include <gtk/gtk.h>
#include "sudoku_app.h"

#define SUDOKU_APP_WINDOW_TYPE (sudoku_app_window_get_type())
G_DECLARE_FINAL_TYPE (SudokuAppWindow, 
                      sudoku_app_window, 
                      SUDOKU, 
                      APP_WINDOW, 
                      GtkApplicationWindow);

SudokuAppWindow *sudoku_app_window_new(SudokuApp *app);
void sudoku_app_window_open(SudokuAppWindow *win, GFile *file);

#endif