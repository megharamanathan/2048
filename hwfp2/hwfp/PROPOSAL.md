# Proposal: [PROPOSAL 2048]

## Synopsis

### Elements
My game will have one element:

-a stationary 4x4 array of tiles that is the grid. Each tile in the array may either hold a block with a number, or
be unoccupied

### Goal
By using the arrow keys on the keyboard, the player can slide numbered tiles on a grid to combine them.
In order to combine two tiles, they must hold the same number. The player's goal is to combine tiles on the grid to
create a tile with the number 2048.

#Game play
The game is played on a 4x4 grid that starts off with two tiles in random locations on the grid. Each of these initial
tiles holds either the number 2 or the number 4. When the player presses the arrow keys (up, down, right, or left), all of
the tiles slide in the corresponding direction. The tiles are stopped by either another tile, or the edge of the grid. If two tiles
of the same number collide, then they are combined to form a tile with the total value of those two tiles.
After each turn, a new tile appears on a random, unoccupied position on the board. This tile holds either the value 2 or the
value 4. The game is over when the player has no more legal moves; this means that all of the spaces on the board are
occupied, and there are no adjacent tiles holding the same value.

## Functional requirements

1. There is a 4x4 array of tiles of the same size that are stationary on the screen.

2. When the game first begins, there are two occupied tiles on the screen, each holding either the number 2 or the number 4,
in random locations on the grid.

3. During gameplay, each tile on the board will either be empty/unoccupied, or populated with a tile that has a number.

4. Pressing the arrow keys (up, down, left, and right) causes all the tiles on the grid to move in the corresponding
direction, until they are stopped.

5. The tiles can slide until they are stopped by a tile holding a different value, or until the edge of the grid.

6. After each turn, a new tile is generated on a random, unoccupied location in the grid, holding either the number
2 or the number 4.

7. If two tiles of the same number collide, they must combine to form a tile with the total value of those two tiles.

8. The resulting tile of two tiles colliding cannot merge with another tile of the same resulting value in the same move.

9. Each number of a tile has a distinct color, so when two tiles of the same number collide, they must combine to form
a tile of a different color.

10. The game is lost when there are no legal moves, or when all of the spaces on the board are occupied, and there
are no adjacent tiles holding the same value. This renders swiping in any direction impossible.

11. The game is won when the user combines tiles to create a tile with the value 2048. This should display a message
on the screen, "You won!"

12. There should be a score displayed in the upper left hand corner. This score begins at 0, and is incremented
every time two tiles are combined. It is incremented by the resulting tile's value.


## Open questions

1. Should the sliding of the blocks be animated? If so, with what velocity should all the blocks slide, and should
some blocks slide faster than others depending on how far they have to slide?

2. How should the numbers be placed on the blocks?

3. Should the game end when the user reaches 2048, or should the user have the option to keep going?


