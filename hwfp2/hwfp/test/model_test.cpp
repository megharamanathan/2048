#include "model.h"
#include <catch.h>

TEST_CASE("example test")
{
    CHECK( 1 + 1 == 2 );
}

TEST_CASE("game beginning")
{
    //this test checks if there are 2 tiles generated at the beginning of the game
    //and whether the values of the tiles are either 2 or 4
    Model m;

    int count = 0;
    bool val_is_2_or_4 = false;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++)
        {
            if (m.board[row][col].num_value != 0)
                count++;
            if (m.board[row][col].num_value == 2 || m.board[row][col].num_value == 4)
                val_is_2_or_4 = true;

        }
    }

    CHECK(count == 2);
    CHECK(val_is_2_or_4);
}

TEST_CASE("combine")
{
    //This test case checks if tiles are properly combined when swiped in a certain direction
    Model m;
    m.board[0][1].num_value = 4;
    m.board[0][2].num_value = 4;

    m.do_move(right);
    CHECK(m.board[0][3].num_value == 8);

    m.clear();
    m.board[3][0].num_value = 8;
    m.board[2][0].num_value = 8;
    m.board[1][0].num_value = 8;

    m.do_move(up);
    CHECK(m.board[0][0].num_value == 16);
    CHECK(m.board[1][0].num_value == 8);
}

TEST_CASE("combining more tiles")
{

    Model m;
    m.board[0][0].num_value = 8;
    m.board[0][1].num_value = 8;
    m.board[0][2].num_value = 8;

    m.do_move(left);
    CHECK(m.board[0][0].num_value == 16);
    CHECK(m.board[0][1].num_value == 8);

    m.clear();

    m.board[0][1].num_value = 4;
    m.board[1][1].num_value = 4;
    m.board[2][1].num_value = 4;
    m.board[3][1].num_value = 4;
    m.do_move(down);

    CHECK(m.board[3][1].num_value == 8);
    CHECK(m.board[2][1].num_value == 8);

}

TEST_CASE("score")
{
    //This test case checks that the score is incremented correctly when two tiles are combined
    Model m;
    m.board[0][0].num_value = 2;
    m.board[0][1].num_value = 2;
    m.board[0][2].num_value = 2;
    m.board[0][3].num_value = 2;

    m.do_move(left);
    CHECK(m.score == 8);

    m.do_move(left);
    CHECK(m.score == 16);

}

TEST_CASE("tiles are stopped")
{
    //This test case checks if tiles are stopped either when they hit a tile holding a different value,
    //or when they reach the edge of the board

    Model m;
    m.board[0][0].num_value = 16;
    m.do_move(left);
    CHECK(m.board[0][0].num_value == 16);

    m.clear();

    m.board[2][0].num_value = 4;
    m.board[3][0].num_value = 8;
    m.do_move(down);
    CHECK(m.board[2][0].num_value == 4);
    CHECK(m.board[3][0].num_value == 8);

    m.clear();

    m.board[2][1].num_value = 4;
    m.board[2][3].num_value = 8;
    m.do_move(left);
    CHECK(m.board[2][0].num_value == 4);
    CHECK(m.board[2][1].num_value == 8);

}

TEST_CASE("Combining tiles in multiple rows")
{
    Model m;
    m.clear();
    m.board[0][0].num_value = 32;
    m.board[0][1].num_value = 32;
    m.board[1][2].num_value = 64;
    m.board[1][3].num_value = 64;
    m.board[2][3].num_value = 64;

    m.do_move(right);
    CHECK(m.board[0][3].num_value == 64);
    CHECK(m.board[1][3].num_value == 128);
    CHECK(m.board[2][3].num_value == 64);
}

TEST_CASE("playing with score and moves")
{
    Model m;
    m.clear();
    CHECK(m.score == 0);

    m.board[2][3].num_value = 32;
    m.board[2][2].num_value = 16;
    m.board[2][1].num_value = 16;
    m.board[2][0].num_value = 8;
    m.board[1][0].num_value = 8;

    m.do_move(down);
    CHECK(m.board[3][0].num_value == 16);
    CHECK(m.board[3][1].num_value == 16);
    CHECK(m.board[3][2].num_value == 16);
    CHECK(m.board[3][3].num_value == 32);
    CHECK(m.score == 16);

    m.do_move(right);
    CHECK(m.board[3][0].num_value == 0);
    CHECK(m.board[3][1].num_value == 16);
    CHECK(m.board[3][2].num_value == 32);
    CHECK(m.board[3][3].num_value == 32);
    CHECK(m.score == 48);

    m.do_move(right);
    CHECK(m.board[3][0].num_value == 0);
    CHECK(m.board[3][1].num_value == 0);
    CHECK(m.board[3][2].num_value == 16);
    CHECK(m.board[3][3].num_value == 64);
    CHECK(m.score == 112);
}

TEST_CASE("game over?")
{
    Model m;
    m.clear();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m.board[i][j].num_value = 2;
        }
    }

    CHECK(!m.is_game_over());

    m.clear();
    int value = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            value = value*2;
            m.board[i][j].num_value = value;
        }
    }

    CHECK(m.is_game_over());

}

TEST_CASE("player wins")
{
    Model m;
    m.clear();
    CHECK(!m.player_wins());

    m.board[2][2].num_value = 2048;

    CHECK(m.player_wins());
}

TEST_CASE("combine separated tiles")
{
    Model m;
    m.clear();

    m.board[3][0].num_value = 8;
    m.board[1][0].num_value = 8;
    m.do_move(up);
    CHECK(m.board[0][0].num_value == 16);
}

TEST_CASE("random tile is generated") {
    Model m;
    m.clear();

    m.board[2][0].num_value = 8;
    m.board[3][0].num_value = 16;
    m.do_move(down);
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m.board[i][j].num_value != 0)
                count++;
        }
    }

    CHECK(m.board[2][0].num_value == 8);
    CHECK(m.board[3][0].num_value == 16);
    //The count should still be two here; there wasn't a new tile generated because
    //none of the pieces moved
    CHECK(count == 2);

    m.clear();
    m.board[0][0].num_value = 4;
    m.board[0][1].num_value = 4;
    count = 0;
    m.do_move(left);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m.board[i][j].num_value != 0)
                count++;
        }
    }
    //Now, two tiles are combined and one new tile is generated
    CHECK(count == 2);
}