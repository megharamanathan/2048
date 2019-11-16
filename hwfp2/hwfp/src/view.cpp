//
// Created by megha on 3/7/2019.
//

#include "view.h"

ge211::Color const unoccupied_tile_color {240, 230, 140};
ge211::Color const score_tile{175, 238, 238};
ge211::Color const two_color {250, 235, 215};
ge211::Color const four_color {255, 192, 203};
ge211::Color const eight_color {255, 222, 173};
ge211::Color const sixteen_color {244, 164, 96};
ge211::Color const thirtytwo_color {255, 105, 180};
ge211::Color const sixtyfour_color {255, 69, 0};
ge211::Color const onetwentyeight_color {255, 215, 0};
ge211::Color const twofiftysix_color {30, 144, 255};
ge211::Color const fivetwelve_color {124, 252, 0};
ge211::Color const tentwentyfour_color {127, 255, 212};
ge211::Color const twentyfourtyeight_color {0, 255, 128};

using namespace ge211;

// You can change this or even determine it some other way:

View::View(Model& model)
        : model_(model)
{}

void View::draw(Sprite_set& set)
{

    set.add_sprite(score_sprite, {6, 5}, 0);

    builder_.message("Score: " + std::to_string(model_.score));
    builder_.color(ge211::Color::black());
    score.reconfigure(builder_);

    set.add_sprite(score, {20, 8}, 1);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            set.add_sprite(tile_sprite, {i * (tile_sprite.dimensions().width + 4) + 2, j *
            (tile_sprite.dimensions().height + 4) + 80}, 0);
        }
    }

    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 4; j++)
        {
            //ge211::Position p = board_to_screen({j, i});
            ge211::Position p2 = {(board_to_screen({j, i})).x + 45, (board_to_screen({j, i})).y + 25};
            ge211::Position p3 = {(board_to_screen({j, i})).x + 35, (board_to_screen({j, i})).y + 25};
            ge211::Position p4 = {(board_to_screen({j, i})).x + 25, (board_to_screen({j, i})).y + 25};
            ge211::Position p5 = {(board_to_screen({j, i})).x + 15, (board_to_screen({j, i})).y + 25};
            if (model_.board[i][j].num_value == 0)
            {
                set.add_sprite(tile_sprite, board_to_screen({j, i}), model_.move_number + 1);
            }
            if (model_.board[i][j].num_value == 2)
            {
                set.add_sprite(two_tile, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(two, p2, model_.move_number + 2);
            }

            if (model_.board[i][j].num_value == 4)
            {
                set.add_sprite(four_tile, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(four, p2, model_.move_number + 2);
            }

            if (model_.board[i][j].num_value == 8)
            {
                set.add_sprite(eight_tile, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(eight, p2, model_.move_number + 2);
            }

            if (model_.board[i][j].num_value == 16)
            {
                set.add_sprite(sixteen_tile, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(sixteen, p3, model_.move_number + 2);
            }
            if (model_.board[i][j].num_value == 32)
            {
                set.add_sprite(thirtytwo_tile, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(thirty_two, p3, model_.move_number + 2);
            }
            if (model_.board[i][j].num_value == 64)
            {
                set.add_sprite(sixtyfour_tile, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(sixty_four, p3, model_.move_number + 2);
            }
            if (model_.board[i][j].num_value == 128)
            {
                set.add_sprite(onetwentyeight_tile, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(one_twenty_eight, p4, model_.move_number + 2);
            }
            if (model_.board[i][j].num_value == 256)
            {
                set.add_sprite(twofiftysix, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(two_fifty_six, p4, model_.move_number + 2);
            }
            if (model_.board[i][j].num_value == 512)
            {
                set.add_sprite(fivetwelve, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(five_hundred_twelve, p4, model_.move_number + 2);
            }
            if (model_.board[i][j].num_value == 1024)
            {
                set.add_sprite(tentwentyfour, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(thousand_twenty_four, p5, model_.move_number + 2);
            }
            if (model_.board[i][j].num_value == 2048)
            {
                set.add_sprite(twentyfourtyeight, board_to_screen({j, i}), model_.move_number + 1);
                set.add_sprite(twenty_fourty_eight, p5, model_.move_number + 2);
            }
        }
    }

    if (model_.is_game_over())
        set.add_sprite(youlose, {200, 8}, 1);

    if (model_.player_wins())
        set.add_sprite(youwin, {200, 8}, 1);

}

Dimensions View::initial_window_dimensions() const
{
    // You can change this if you want:
    return {516, 596};
}

std::string View::initial_window_title() const
{
    return "2048";
}

ge211 :: Position View::board_to_screen (ge211 :: Position pos) const
{
    ge211::Position  screen_position = {pos.x * 129 + 2, pos.y * 129 + 80};
    return screen_position;
}

ge211 :: Position View::screen_to_board (ge211 :: Position pos) const
{
    ge211::Position p = {pos.x/tile_sprite.dimensions().width, pos.y/tile_sprite.dimensions().height};
    return p;
}
