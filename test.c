#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "main.h"

static void should_init_success(void **state)
{
    (void)state;
    initalize_game();
    assert_int_equal(game.current_score, 0);
    assert_int_equal(game.game_status, 0);
    assert_int_equal(game.available_tiles, 16);
    for (int row = 0; row < ROW; ++row)
    {
        for (int col = 0; col < COL; ++col)
        {
            assert_int_equal(game.grid[row][col], 0);
        }
    }
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(should_init_success)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
