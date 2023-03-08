#ifndef SUDOKU_H
#define SUDOKU_H

// Read a Sudoku board specified by index into puzzle. Returns false if the
// file can't be opened.
bool read_sudoku(char puzzle[9][9], const char *filename, int index);

// Read a random Sudoku board into puzzle. Returns the board's index or -1 if
// the file can't be opened.
int read_random_sudoku(char puzzle[9][9], const char *filename);

bool is_valid_sudoku(const char puzzle[9][9]);
bool is_filled_sudoku(const char puzzle[9][9]);

#endif