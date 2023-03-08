#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sudoku.h"

#define RECORD_SIZE 100
#define SHA1_SIZE   12
#define PUZZLE_SIZE 81

bool read_sudoku(char puzzle[9][9], const char *filename, int index) {
    // Open a Sudoku "Puzzle Bank" database file.
    FILE *database = fopen(filename, "r");
    
    // Handle any file open errors.
    if (database == NULL)
        return false;

    // Seek to EOF.
    fseek(database, 0, SEEK_END);

    // Check for an invalid index.
    if (index < 0 || index >= ftell(database) / RECORD_SIZE)
        return false;

    // Seek to the given index + the offset of the puzzle.
    fseek(database, index * RECORD_SIZE + SHA1_SIZE + 1, SEEK_SET);

    // Read 81 bytes into the puzzle array.
    fread(puzzle, 1, PUZZLE_SIZE, database);

    fclose(database);

    return true;
}

int read_random_sudoku(char puzzle[9][9], const char *filename) {
    // Open a Sudoku "Puzzle Bank" database file.
    FILE *database = fopen(filename, "r");
    
    // Handle any file open errors.
    if (database == NULL)
        return -1;

    // Seek to EOF.
    fseek(database, 0, SEEK_END);

    // Choose a random index.
    srand((unsigned) time(NULL));
    int random_index = rand() % (ftell(database) / RECORD_SIZE);

    // Seek to the random index + the offset of the puzzle.
    fseek(database, random_index * RECORD_SIZE + SHA1_SIZE + 1, SEEK_SET);

    // Read 81 bytes into the puzzle array.
    fread(puzzle, 1, PUZZLE_SIZE, database);

    fclose(database);

    return random_index;
}

bool is_valid_sudoku(const char puzzle[9][9]) {
    bool rows[9][9] = {{0}};
    bool columns[9][9] = {{0}}; 
    bool squares[9][9] = {{0}};

    int value;
    int s;  
    bool is_duplicate;

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (puzzle[r][c] < '1' || puzzle[r][c] > '9')
                continue;

            value = puzzle[r][c] - '0';

            s = 3 * (int) (r * 9 / 27) + (int) (c / 3);

            is_duplicate = (rows[r][value - 1] || 
                            columns[c][value - 1] ||
                            squares[s][value - 1]);
            if (is_duplicate)
                return false;

            rows[r][value - 1] = true;
            columns[c][value - 1] = true;
            squares[s][value - 1] = true;
        }
    }

    return true;
}

bool is_filled_sudoku(const char puzzle[9][9]) {
    for (int r = 0; r < 9; ++r)
        for (int c = 0; c < 9; ++c)
            if (puzzle[r][c] < '1' || puzzle[r][c] > '9')
                return false;
    return true;
}
