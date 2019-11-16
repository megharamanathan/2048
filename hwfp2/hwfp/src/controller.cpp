//
// Created by megha on 3/7/2019.
//

#include "controller.h"

using namespace ge211;

Controller::Controller()
        : model_()
        , view_(model_)
{ }

void Controller::draw(Sprite_set& sprites)
{

    view_.draw(sprites);
}

Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void Controller::on_key(ge211::Key key)
{
    if (!model_.player_wins()) {
        if (key == ge211::Key::up()) {
            model_.do_move(up);
        }

        if (key == ge211::Key::down()) {
            model_.do_move(down);
        }

        if (key == ge211::Key::right()) {
            model_.do_move(right);
        }

        if (key == ge211::Key::left()) {
            model_.do_move(left);
        }
    }

    if (key == ge211::Key::code('q'))
    {
        quit();
    }

}


