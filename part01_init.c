#include "part01_init.h"

game_state game;

void initalize_game()
{

    srand((unsigned)time(NULL));

    for (int row = 0; row < ROW; ++row)
    {
        for (int col = 0; col < COL; ++col)
        {
            game.grid[row][col] = 0;
        }
    }
    game.current_score = 0;
    game.game_status = 0;
    game.available_tiles = 16;
}
