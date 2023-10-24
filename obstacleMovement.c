#include "obstacleMovement.h"

void moveObstacles(char **board, char **originalBoard, int ***obstacleDirections, int boardSizeX, int boardSizeY) {
    int i, j;
    for (i = 0; i < boardSizeX; i++) {
        int continueLoop = 1; /* Initialize the flag to 1 */
        for (j = 0; j < boardSizeY && continueLoop; j++) {
            /*If obstacle is moving left*/
            if (board[i][j] == LEFT_OBSTACLE_CHAR) {
                if (originalBoard[i][j-1] == '.') {
                    /* Move the obstacle forwards */
                    board[i][j] = '.';
                    board[i][j-1] = LEFT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j-1] = LEFT;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i+1][j] == '.') {
                    /* Change the direction of the obstacle to down (left) if it cant go forwards*/
                    board[i][j] = '.';
                    board[i+1][j] = DOWN_OBSTACLE_CHAR;
                    (*obstacleDirections)[i+1][j] = DOWN;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i-1][j] == '.') {
                    /* Change the direction of the obstacle to up (right) if it cant go forwards or left*/
                    board[i][j] = '.';
                    board[i-1][j] = UP_OBSTACLE_CHAR;
                    (*obstacleDirections)[i-1][j] = UP;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else {
                    /* Reverse if cant go forwards or left or right */
                    board[i][j] = RIGHT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j] = RIGHT;
                    continueLoop = 0;
                }
            }
            /*If obstacle is moving right*/
            else if (board[i][j] == RIGHT_OBSTACLE_CHAR) {
                if (originalBoard[i][j+1] == '.') {
                    /* Move the obstacle forwards */
                    board[i][j] = '.';
                    board[i][j+1] = RIGHT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j+1] = RIGHT;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i-1][j] == '.') {
                    /* Change the direction of the obstacle to up (left) if it cant go forwards*/
                    board[i][j] = '.';
                    board[i-1][j] = UP_OBSTACLE_CHAR;
                    (*obstacleDirections)[i-1][j] = UP;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i+1][j] == '.') {
                    /* Change the direction of the obstacle to down (right) if it cant go forwards or left*/
                    board[i][j] = '.';
                    board[i+1][j] = DOWN_OBSTACLE_CHAR;
                    (*obstacleDirections)[i+1][j] = DOWN;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else {
                    /* Reverse if cant go forwards or left or right */
                    board[i][j] = LEFT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j] = LEFT;
                    continueLoop = 0;
                }
            }
            else if (board[i][j] == UP_OBSTACLE_CHAR) {
                /* Check if the obstacle can move right */
                if (originalBoard[i-1][j] == '.') {
                    /* Move the obstacle forwards */
                    board[i][j] = '.';
                    board[i-1][j] = UP_OBSTACLE_CHAR;
                    (*obstacleDirections)[i-1][j] = UP;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i][j-1] == '.') {
                    /* Change the direction of the obstacle to left if it cant go forwards*/
                    board[i][j] = '.';
                    board[i][j-1] = LEFT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j-1] = LEFT;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i][j+1] == '.') {
                    /* Change the direction of the obstacle to right if it cant go forwards or left*/
                    board[i][j] = '.';
                    board[i][j+1] = RIGHT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j+1] = RIGHT;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else {
                    /* Reverse if cant go forwards or left or right */
                    board[i][j] = DOWN_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j] = DOWN;
                    continueLoop = 0;
                }
            }
            else if (board[i][j] == DOWN_OBSTACLE_CHAR) {
                if (originalBoard[i+1][j] == '.') {
                    board[i][j] = '.';
                    board[i+1][j] = DOWN_OBSTACLE_CHAR;
                    (*obstacleDirections)[i+1][j] = DOWN;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i][j+1] == '.') {
                    /* Change the direction of the obstacle to right if it cant go forwards or left*/
                    board[i][j] = '.';
                    board[i][j+1] = RIGHT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j+1] = RIGHT;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else if (originalBoard[i][j-1] == '.') {
                    /* Change the direction of the obstacle to left if it cant go forwards*/
                    board[i][j] = '.';
                    board[i][j-1] = LEFT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j-1] = LEFT;
                    (*obstacleDirections)[i][j] = 0;
                    continueLoop = 0;
                }
                else {
                    /* Reverse if cant go forwards or left or right */
                    board[i][j] = UP_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j] = UP;
                    continueLoop = 0;
                }
            }
        }
    }
}