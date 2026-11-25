# Traffic Game (C)

A terminal puzzle game in ANSI C. Get the player **P** to the goal **G** without colliding with the cars driving around the traffic loop.

## Build and play
```bash
make
./traffic boards/game_1.txt
```

| Key | Action |
|---|---|
| `w` `a` `s` `d` | move up / left / down / right (every move also advances each car one step) |
| `u` | undo the last move (player and cars) |
| `q` | quit |

## Board files
The first line is `rows columns`, followed by a grid of digits:

| Digit | Meaning |
|---|---|
| `0` | empty space |
| `1` | traffic path (`.`) |
| `2` | car, initially facing east |
| `3` | player |
| `4` | goal |

Cars follow the path, turning left or right when the way ahead is blocked. Four example boards are in `boards/`; making your own is just editing a grid of digits.

## Design
- `gameboard` – board loading and duplication
- `playerMovement`, `obstacleMovement` – movement and collision logic
- `linkedList` – **generic** linked list (`void *` payload) used as the undo history
- `printBoard`, `terminal`, `freeMemory` – rendering, raw keypress input, cleanup
- `tests/` – five self-contained linked-list tests, built one at a time: `gcc -ansi -pedantic tests/linkedListTest1.c -o test1 && ./test1`

Compiled with `-Wall -pedantic -ansi -Werror`.

## Known issue
A car travelling downward can get stuck repeatedly moving down until it hits the edge of the board. The fault is in the down-movement branch of `moveObstacles` in `obstacleMovement.c`.
