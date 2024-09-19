#include "game.h"

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

void show_grid()
{
    printf("current grid: \n");
    for (int row = 0; row < ROW; ++row)
    {
        for (int col = 0; col < COL; ++col)
        {
            printf("%4d", game.grid[row][col]);
        }
        printf("\n");
    }
}

void add_random_tile()
{
    for (int i = 0; i < 2; i++)
    {
        if (game.available_tiles == 0)
        {
            break;
        }
        do
        {
            int row = rand() % 4;
            int col = rand() % 4;
            // 找到空白位置
            if (game.grid[row][col] == 0)
            {
                game.grid[row][col] = (rand() % 2 + 1) * 2;
                game.available_tiles--;
                break;
            }
            
        } while (i);
        
        
    }
}
