#include <stdlib.h>
#include "freeMemory.h"

/* Function to free memory allocated for the game board */
void freeBoard(char **board, int boardSizeX) {
    int i;
    for (i = 0; i < boardSizeX; i++) {
        free(board[i]);
    }
    free(board);
}

/* Function to free memory allocated for the obstacle directions */
void freeObstacleDirections(int **obstacleDirections, int boardSizeX) {
    int i;
    for (i = 0; i < boardSizeX; i++) {
        free(obstacleDirections[i]);
    }
    free(obstacleDirections);
}

/* Function to free memory allocated for the original game board */
void freeOriginalBoard(char **originalBoard, int boardSizeX) {
    int i;
    for (i = 0; i < boardSizeX; i++) {
        free(originalBoard[i]);
    }
    free(originalBoard);
}