#pragma once

#include <ge211.h>

//
// Model constants:
//


enum move_dir {up, down, left, right};
//
// Model classes:
//


//The whole state of the game
class Model
{

public:

    Model();

    //
    // PUBLIC FUNCTIONS
    //

    //Performs a move
    void do_move(move_dir);

    //Generates an unoccupied position on the board for a location to add a piece
    ge211::Position generate_unoccupied_position();

    //Generates a number value (2 or 4) for an added piece
    int generate_value();

    //Adds a piece on to an unoccupied position on the board
    void add_piece();

    //Clears the board of all tiles
    void clear();

    //returns whether the game is over
    bool is_game_over();

    //returns whether the player has won (AKA 2048 tile was created)
    bool player_wins();

    struct Tile
    {
        int num_value = 0;

        bool blocked = false;
    };

    Tile board[4][4];

    int score = 0;

    int move_number = 0;





private:

    //
    // PRIVATE DATA MEMBERS
    //

    //The tiles

    //
    // POSSIBLE HELPER FUNCTIONS
    //

    //slide tiles to right
    void slide_right();

    //slide tiles left
    void slide_left();

    //slide tiles up
    void slide_up();

    //slide tiles down
    void slide_down();

    //returns whether a move is possible
    bool move_possible(int row, int col, int next_row, int next_col);

    //returns whether a piece can be added to the board
    bool can_add_piece();

    //returns whether two pieces can be combined
    bool can_combine(int row, int col, int next_row, int next_col);



    // Test Access

    friend class Test_access;

};

