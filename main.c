#include <gtk/gtk.h>
#include "sudoku_app.h"

int main(int argc, char *argv[]) {
    return g_application_run(G_APPLICATION(sudoku_app_new()), argc, argv);
}