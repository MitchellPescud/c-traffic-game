#ifndef FREEMEMORY_H
#define FREEMEMORY_H

/* Function to free memory allocated for the game board */
void freeBoard(char **board, int boardSizeX);

/* Function to free memory allocated for the obstacle directions */
void freeObstacleDirections(int **obstacleDirections, int boardSizeX);

/* Function to free memory allocated for the original game board */
void freeOriginalBoard(char **originalBoard, int boardSizeX);

#endif  /* FREEMEMORY_H */