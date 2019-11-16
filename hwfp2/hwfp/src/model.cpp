#include <iostream>
#include "model.h"

Model::Model()

{
    score = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j].num_value = 0;
        }
    }

    add_piece();
    add_piece();
}


void Model::do_move(move_dir dir)
{

    move_number++;
    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j].blocked = false;
        }
    }

    if (dir == left)
        slide_left();
    else if (dir == right)
        slide_right();
    else if (dir == up)
        slide_up();
    else if (dir == down)
        slide_down();


}

ge211::Position Model::generate_unoccupied_position()
{
    if (can_add_piece())
    {
        ge211::Position p = {-1, -1};
        while (p.x == -1 && p.y == -1)
        {
            int a = rand() % 4;
            int b = rand() % 4;
            if (board[a][b].num_value == 0)
                return {a, b};

        }
    }


}

int Model::generate_value()
{
    int a = rand() % 2;
    if (a == 0)
        return 2;
    else
        return 4;
}

void Model::add_piece()
{
    int a = generate_value();
    ge211::Position p = generate_unoccupied_position();
    board[p.x][p.y].num_value = a;
}

void Model::clear()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j].num_value = 0;
        }
    }
}

bool Model::is_game_over()
{
    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j].num_value == 0)
                return false;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((i != 3 && (board[i+1][j].num_value == board[i][j].num_value)) ||
            (j != 3 && (board [i][j+1].num_value == board[i][j].num_value)))
                return false;
        }
    }

    return true;

}

bool Model::player_wins()
{
    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j].num_value == 2048)
                return true;
        }
    }

    return false;
}

//PRIVATE HELPER FUNCTIONS

void Model::slide_right()
{
    int starting_col = 3;
    int col_step = -1;
    int starting_row = 0;
    int row_step = 1;

    bool should_restart = true;
    bool moved = false;

    while (should_restart)
    {
        should_restart = false;
        for (int i = starting_row; i >= 0 && i < 4; i += row_step)
        {
            for (int j = starting_col; j >= 0 && j < 4; j += col_step)
            {
                if (board[i][j].num_value != 0 && (move_possible(i, j, i, j + 1) || can_combine(i, j, i, j + 1)))
                {
                    moved = true;
                    board[i][j + 1].num_value += board[i][j].num_value;
                    board[i][j].num_value = 0;
                    should_restart = true;
                    break;
                }

            }
        }
    }

    if (can_add_piece() && moved)
        add_piece();
}

void Model::slide_left()
{
    int starting_col = 0;
    int col_step = 1;
    int starting_row = 0;
    int row_step = 1;

    bool should_restart = true;
    bool moved = false;

    while (should_restart)
    {
        should_restart = false;
        for (int i = starting_row; i >= 0 && i < 4; i += row_step)
        {
            for (int j = starting_col; j >= 0 && j < 4; j += col_step)
            {
                if (board[i][j].num_value != 0 && (move_possible(i, j, i, j - 1) || can_combine(i, j, i, j - 1)))
                {
                    moved = true;
                    board[i][j - 1].num_value += board[i][j].num_value;
                    board[i][j].num_value = 0;
                    should_restart = true;
                    break;
                }

            }
        }
    }

    if (can_add_piece() && moved)
        add_piece();

}

void Model::slide_up()
{
    int starting_col = 0;
    int col_step = 1;
    int starting_row = 0;
    int row_step = 1;

    bool should_restart = true;
    bool moved = false;


    while (should_restart)
    {
        should_restart = false;
        for (int i = starting_row; i >= 0 && i < 4; i += row_step)
        {
            for (int j = starting_col; j >= 0 && j < 4; j += col_step)
            {
                if (board[i][j].num_value != 0 && (move_possible(i, j, i - 1, j) || can_combine(i, j, i - 1, j)))
                {
                    moved = true;
                    board[i - 1][j ].num_value += board[i][j].num_value;
                    board[i][j].num_value = 0;
                    should_restart = true;
                    break;
                }

            }
        }
    }

    if (can_add_piece() && moved)
        add_piece();
}

void Model::slide_down()
{
    int starting_col = 0;
    int col_step = 1;
    int starting_row = 3;
    int row_step = -1;

    bool should_restart = true;
    bool moved = false;

    while (should_restart)
    {
        should_restart = false;
        for (int i = starting_row; i >= 0 && i < 4; i += row_step)
        {
            for (int j = starting_col; j >= 0 && j < 4; j += col_step)
            {
                if (board[i][j].num_value != 0 && (move_possible(i, j, i + 1, j) || can_combine(i, j, i + 1, j)))
                {
                    moved = true;
                    board[i + 1][j].num_value += board[i][j].num_value;
                    board[i][j].num_value = 0;
                    should_restart = true;
                    break;
                }

            }
        }
    }
    if (can_add_piece() && moved)
        add_piece();
}

bool Model::move_possible(int row, int col, int next_row, int next_col)
{
    if (next_row < 0 || next_col < 0 || next_row >= 4 || next_col >= 4 || board[next_row][next_col].num_value != 0)
        return false;
    else
        return true;
}

bool Model::can_add_piece()
{
    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 4; j ++)
        {
            if (board[i][j].num_value == 0)
                return true;
        }
    }
    return false;
}

bool Model::can_combine(int row, int col, int next_row, int next_col)
{

    if (next_row < 0 || next_col < 0 || next_row >= 4 || next_col >= 4)
        return false;

        if (board[next_row][next_col].num_value != 0 && !board[row][col].blocked && !board[next_row][next_col].blocked) {
            if (board[row][col].num_value == board[next_row][next_col].num_value) {
                board[next_row][next_col].blocked = true;
                score += board[row][col].num_value * 2;
                return true;
            }
            else
                return false;
        }


}


