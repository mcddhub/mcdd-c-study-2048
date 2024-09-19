#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 4
#define COL 4

typedef struct {
    int grid[ROW][COL];
    long current_score;
    int game_status;
    int available_tiles;
} game_state;

game_state game;

void initalize_game() {

    srand((unsigned)time(NULL));

    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            game.grid[row][col] = 0;
        }
    }
    game.current_score = 0;
    game.game_status = 0;
    game.available_tiles = 16;
}

void show_grid(){
    printf("当前网格: \n");
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            printf("%4d",game.grid[row][col]);
        }
    printf("\n");
    }
}

int main(){
    initalize_game();
    show_grid();
    return 0;
}
