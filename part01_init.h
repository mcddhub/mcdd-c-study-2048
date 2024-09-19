#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 4
#define COL 4

typedef struct
{
    int grid[ROW][COL];
    long current_score;
    int game_status;
    int available_tiles;
} game_state;

extern game_state game;

void initalize_game();