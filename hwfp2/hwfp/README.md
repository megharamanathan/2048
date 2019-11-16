# 2048

## Instructions

The game begins with 2 randomly generated tiles holding either the number two or the number four
on a 4x4 board. By pressing each of the four arrow keys, the player can move the tiles in the
corresponding direction. If a move is not valid, then the board remains the same and pressing the corresponding
arrow key will do nothing.
The player can combine tiles holding the same number to form a new tile with a new number that is
twice the value of the two tiles that were combined. Each time the player plays a valid move, a new tile will
appear on an unoccupied location on the grid, holding a value of either 2 or 4. When an arrow key is pressed,
the tiles slide in the corresponding direction until they are either stopped by a tile or the edge of the grid.
The goal is to combine tiles to form a tile with the number 2048, at which point the game will end with a message,
"You win!" There are no legal moves left when all of the tiles on the screen are occupied, and there are no
adjacent tiles that have the same value that can be combined. At this point, a message will appear on the
screen saying "You lose!"
The score of the player is determined by every time the player is able to combine two tiles. In other words, the
score is incremented each time two tiles are combined, by the resulting tile's value.

## Changes from proposal

The model.h file was modified, specifically some member variables and the layout of struct Tile. The three member
variables ge211::Dimensions const tile_dims, int const number_size, and ge211::Dimensions const board_dimensions
were removed from the model.h file, and instead were used in view.h and view.cpp. The Tile struct
previously had the variables of color and whether the tile was occupied or unoccupied. This was modified to only include
an int num_value, and bool blocked, which was used to inform me of whether the tile had already previously been
combined so that I would know not to combine it again in the same move. Some of the functions of
the model class were also modified. I did not have a use for the end_game function, and ended the game in the
controller class instead.

## Evaluation guide

All of the functional requirements can be checked through interactive playing of the game. There is a 4x4 array
of tiles that are stationary that appear on the screen when the game begins. Two tiles are occupied when first
running the game, both of which are either 2 or 4. Throughout gameplay, the each tile is either occupied or unoccupied
by a number. Pressing the arrow keys causes the numbers to slide. The tiles are stopped at the appropriate locations.
After each move, the user will see that a new tile is generated holding either the number two or the number four. The
tiles also change colors when combined, and each number has a unique color. Gameplay ends when there are no
valid moves, at which point at the top of a screen, a message will display, "You lose!" If the 2048 tile is reached,
a message will display saying "You win!" The score is displayed in the upper left hand corner and is incremented
every time two tiles are combined by the resulting tile's value.

## Answers to open questions

1. The sliding of the blocks is not animated.

2. I created multiple text sprites that contained numbers for each possible number in the game. I also created
rectangle sprites that were set to be different colors based on the number they were holding. I used a board_to_screen
function in the view class to convert the board positions of each tile and each sprite into screen positions. I placed
the tiles in the screen position that was generated, and slightly modified this screen position for each text sprite,
based on the length of the number, so that the text would be centered on the tile.

3. I decided to end the game after the user reaches the 2048 tile. In order to do this, I disabled all of the
arrow keys after the 2048 tile is created.

