//
// Created by megha on 3/7/2019.
//

#pragma once

#include "model.h"
#include "view.h"

class Controller : public ge211::Abstract_game
{
public:

    explicit Controller();

// `protected` means that GE211 (via base class `ge211::Abstract_game`)
// can access these members, but arbitrary other code cannot:
protected:
    //
    // Controller operations called by GE211
    //

    // TODO: Add any input handlers you need, e.g.:
    //  - on_mouse_up for mouse clicks,
    //  - on_mouse_move for mouse tracking, or
    //  - on_frame for animation (?).

    void on_key(ge211::Key) override;


    // These three delegate to the view:
    void draw(ge211::Sprite_set&) override;
    ge211::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;

private:
    Model            model_;
    View             view_;

    // TODO: Add any UI state you need, e.g.:
    //  - the position of the mouse, or
    //  - the position of a keyboard-controller cursor.
};
