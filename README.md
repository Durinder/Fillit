# Fillit
Fillit is a project for the search of an optimal solution among a very large number of possibilities in a reasonable amount of time. Tetrimino pieces are assigned into the smallest square that can fit all of them.

Input is 1-26 tetris pieces, where each one is a 4x4 box in which '#' is part of a tetris piece and '.' is empty space.
Pieces are separated by a single newline.

Example of a valid input below:
"####
....
....
....

....
.#..
.###
....

....
..#.
.###
...."

Output of the program is the smallest square, in which the pieces can be placed. The pieces are given letters according to their running number.
First piece is A, second is B, and so on. Rules do not allow for any rotation of pieces.

The output of the given input example is:

"AAAA
..C.
BCCC
BBB."
