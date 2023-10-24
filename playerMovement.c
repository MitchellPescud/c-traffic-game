#include "playerMovement.h"

int movePlayer(char **board, char **originalBoard, int *playerX, int *playerY, int dx, int dy) {
    int newPlayerX = *playerX + dx;
    int newPlayerY = *playerY + dy;
    int validMove;
    char newCell = board[newPlayerX][newPlayerY];
    char previousCell = board[*playerX][*playerY];
    char originalCell = originalBoard[*playerX][*playerY];
    /*Check for collision with obstacle*/
    if (newCell == LEFT_OBSTACLE_CHAR || newCell == RIGHT_OBSTACLE_CHAR || newCell == UP_OBSTACLE_CHAR || newCell == DOWN_OBSTACLE_CHAR) {
        board[*playerX][*playerY] = originalCell;
        board[newPlayerX][newPlayerY] = DEATH_CHAR;
        validMove = 2; /* Collision with an obstacle */
    }
    /*If passed move onto player movement*/
    else if (previousCell == LEFT_OBSTACLE_CHAR || previousCell == RIGHT_OBSTACLE_CHAR || previousCell == UP_OBSTACLE_CHAR || previousCell == DOWN_OBSTACLE_CHAR) {
        board[*playerX][*playerY] = previousCell;
        *playerX = newPlayerX;
        *playerY = newPlayerY;
        board[*playerX][*playerY] = PLAYER_CHAR;
        validMove = 1; /* Valid move */
    }
    else {

        board[*playerX][*playerY] = originalCell;
        *playerX = newPlayerX;
        *playerY = newPlayerY;
        board[*playerX][*playerY] = PLAYER_CHAR;
        validMove = 1; /* Valid move */
    }
    return validMove; /*Return player movement check status*/
}

int checkPlayerMovementBorder(int *playerX, int *playerY, int dx, int dy, int boardSizeX, int boardSizeY) {
    int newPlayerX = *playerX + dx;
    int newPlayerY = *playerY + dy;
    int validMove = 1;

    /* Check collision with border*/
    if (newPlayerX < 0 || newPlayerX >= boardSizeX || newPlayerY < 0 || newPlayerY >= boardSizeY) {
        validMove = 0; /* Invalid move */
    }
    return validMove;
}

int checkWin(char **board, int playerX, int playerY, int goalX, int goalY) {
    int winValue = 0;
    if (playerX == goalX && playerY == goalY) { /*Check if Player and Goal touch*/
        board[playerX][playerY] = WIN_CHAR;
        winValue = 1; /* Player reached the goal */
    }
    return winValue;
}