//
// Created by megha on 3/7/2019.
//

#pragma once

#include "model.h"

#include <string>

#include <iostream>

extern ge211::Color const unoccupied_tile_color, two_color, four_color, eight_color, sixteen_color, score_tile,
        thirtytwo_color, sixtyfour_color, onetwentyeight_color, twofiftysix_color, fivetwelve_color,
        tentwentyfour_color, twentyfourtyeight_color;

class View
{
public:
    explicit View(Model&);

    // You will probably want to add arguments here so that the
    // controller can communicate UI state (such as a mouse or
    // cursor position):
    void draw(ge211::Sprite_set& set);

    ge211::Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

    ge211 :: Position board_to_screen (ge211 :: Position pos) const;

    ge211 :: Position screen_to_board (ge211 :: Position pos) const;

private:
    //Model const& model_;
    Model& model_;


    ge211::Font sans{"sans.ttf", 40};
    ge211::Text_sprite two =
            ge211::Text_sprite::Builder(sans)
                    .message("2")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite four =
            ge211::Text_sprite::Builder(sans)
                    .message("4")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite eight =
            ge211::Text_sprite::Builder(sans)
                    .message("8")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite sixteen =
            ge211::Text_sprite::Builder(sans)
                    .message("16")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite thirty_two =
            ge211::Text_sprite::Builder(sans)
                    .message("32")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite sixty_four =
            ge211::Text_sprite::Builder(sans)
                    .message("64")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite one_twenty_eight =
            ge211::Text_sprite::Builder(sans)
                    .message("128")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite two_fifty_six =
            ge211::Text_sprite::Builder(sans)
                    .message("256")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite five_hundred_twelve =
            ge211::Text_sprite::Builder(sans)
                    .message("512")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite thousand_twenty_four =
            ge211::Text_sprite::Builder(sans)
                    .message("1024")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite twenty_fourty_eight =
            ge211::Text_sprite::Builder(sans)
                    .message("2048")
                    .color(ge211::Color::black())
                    .build();


    ge211::Font sans2{"sans.ttf", 24};

    ge211::Text_sprite::Builder builder_ = ge211::Text_sprite::Builder(sans2);
    ge211::Text_sprite score = builder_.build();


    ge211::Text_sprite youlose =
            ge211::Text_sprite::Builder(sans)
                    .message("You lose!")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite youwin =
            ge211::Text_sprite::Builder(sans)
                    .message("You win!")
                    .color(ge211::Color::black())
                    .build();


    ge211::Rectangle_sprite tile_sprite {{125, 125}, unoccupied_tile_color};
    ge211::Rectangle_sprite two_tile {{125, 125}, two_color};
    ge211::Rectangle_sprite four_tile {{125, 125}, four_color};
    ge211::Rectangle_sprite eight_tile {{125, 125}, eight_color};
    ge211::Rectangle_sprite sixteen_tile {{125, 125}, sixteen_color};
    ge211::Rectangle_sprite thirtytwo_tile {{125, 125}, thirtytwo_color};
    ge211::Rectangle_sprite sixtyfour_tile {{125, 125}, sixtyfour_color};
    ge211::Rectangle_sprite onetwentyeight_tile {{125, 125}, onetwentyeight_color};
    ge211::Rectangle_sprite twofiftysix {{125, 125}, twofiftysix_color};
    ge211::Rectangle_sprite fivetwelve {{125, 125}, fivetwelve_color};
    ge211::Rectangle_sprite tentwentyfour {{125, 125}, tentwentyfour_color};
    ge211::Rectangle_sprite twentyfourtyeight {{125, 125}, twentyfourtyeight_color};

    ge211::Rectangle_sprite score_sprite {{500, 70}, score_tile};


};