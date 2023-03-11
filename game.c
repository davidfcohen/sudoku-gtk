#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game.h"

#define RECORD_SIZE 100
#define SHA1_SIZE   12
#define PUZZLE_SIZE 81

int main(void) {
    return 0;
}

bool read_sudoku(char puzzle[9][9], const char *filename, int index) {
    FILE *database = fopen(filename, "r");
    
    if (database == NULL)
        return false;

    fseek(database, 0, SEEK_END);

    if (index < 0 || index >= ftell(database) / RECORD_SIZE)
        return false;

    fseek(database, index * RECORD_SIZE + SHA1_SIZE + 1, SEEK_SET);

    fread(puzzle, 1, PUZZLE_SIZE, database);

    fclose(database);

    return true;
}

int read_random_sudoku(char puzzle[9][9], const char *filename) {
    FILE *database = fopen(filename, "r");
    
    if (database == NULL)
        return -1;

    fseek(database, 0, SEEK_END);

    srand((unsigned) time(NULL));
    int random_index = rand() % (ftell(database) / RECORD_SIZE);

    fseek(database, random_index * RECORD_SIZE + SHA1_SIZE + 1, SEEK_SET);

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
