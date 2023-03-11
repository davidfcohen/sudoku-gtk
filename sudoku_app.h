#ifndef SUDOKU_APP_H
#define SUDOKU_APP_H

#include <gtk/gtk.h>

#define SUDOKU_APP_TYPE (sudoku_app_get_type())

G_DECLARE_FINAL_TYPE(SudokuApp, sudoku_app, SUDOKU, APP, GtkApplication);

SudokuApp *sudoku_app_new(void);

#endif
