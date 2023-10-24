#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "terminal.h"
#include "freeMemory.h"
#include "gameboard.h"
#include "playerMovement.h"
#include "obstacleMovement.h"
#include "printBoard.h"
#include "linkedList.h"

#define MAX_BOARD_SIZE 50   /* Define a maximum board size */
#define MIN_BOARDX_SIZE 3   /* Define a min board x size */
#define MIN_BOARDY_SIZE 5   /* Define a min board y size */

int main(int argc, char *argv[]) {
    /*Initialise required variables*/
    int moveResult;
    int getPlayerInput = 1;
    int dx = 0, dy = 0;
    int undo = 0;
    int i, j;
    int playerX, playerY, goalX, goalY, boardSizeX, boardSizeY;
    char **board;
    char **tempBoard;
    char **originalBoard;
    int **obstacleDirections;
    LinkedList *list = createList();

    /*Check if there are command-line arguments for board size*/
    if (argc != 2) {
        printf("Usage: %s <board_filename>\n", argv[0]);
    }
    else {
        /*Initialize game board and adjust terminal to suit game*/
        disableBuffer();
        initializeBoard(&board, &originalBoard, &playerX, &playerY, &goalX, &goalY, &boardSizeX, &boardSizeY, &obstacleDirections, argv[1]);
        insertLast(list, duplicateBoard(board, boardSizeX, boardSizeY));

        /*Get user input*/
        while (getPlayerInput == 1) {
            char ch;
            system("clear");
            printBoard(board, boardSizeX, boardSizeY);
            dx = 0;
            dy = 0;
            if (read(STDIN_FILENO, &ch, 1) == 1) {
                /* Process only 'W', 'A', 'S', 'D' and 'Q' keys */
                switch (ch) {
                    case 'w':
                        dx = -1;
                        break;
                    case 'a':
                        dy = -1;
                        break;
                    case 's':
                        dx = 1;
                        break;
                    case 'd':
                        dy = 1;
                        break;
                    case 'u':
                        undo = 1;
                        break;
                    case 'q':
                        /* Exit */
                        getPlayerInput = 0;
                    default:
                        /* Ignore all other input */
                        continue;
                }
            }
            /*Check the player can move and within game board*/
            if (checkPlayerMovementBorder(&playerX, &playerY, dx, dy, boardSizeX, boardSizeY) == 1) {
                if (undo == 1) {
                    removeLastElement(list);
                    tempBoard = getLastElement(list);
                    if (tempBoard != NULL) {
                        board = tempBoard;
                        printBoard(board, boardSizeX, boardSizeY);
                        for (i = 0; i < boardSizeX; i++) {
                            for (j = 0; j < boardSizeY; j++) {
                                if (board[i][j] == 'P'){
                                    playerX = i;
                                    playerY = j;
                                }
                            }
                        }
                    }
                    undo = 0;
                }
                else {
                    /*Move player and obstacles after input check and check game status*/
                    moveObstacles(board, originalBoard, &obstacleDirections, boardSizeX, boardSizeY);
                    printBoard(board, boardSizeX, boardSizeY);
                    moveResult = movePlayer(board, originalBoard, &playerX, &playerY, dx, dy);
                    insertLast(list, duplicateBoard(board, boardSizeX, boardSizeY));
                    if (moveResult == 2) {  /*If player collided with obstacle*/
                        printBoard(board, boardSizeX, boardSizeY);
                        printf("Game Over! You collided with an obstacle.\n");
                        getPlayerInput = 0;  /* Exit the game */
                    } else if (moveResult == 1 && checkWin(board, playerX, playerY, goalX, goalY)) {    /*If made it to the goal*/
                        printBoard(board, boardSizeX, boardSizeY);
                        printf("You won!\n");
                        getPlayerInput = 0; /* Exit the game */
                    }
                }
            }
            /* Sleep for a short time to control the game speed */
            sleep(0.5); /* Sleep for half a second  */
        }
        printf("Exiting Game...\n");

        /*Free Memory*/
        freeBoard(board, boardSizeX);
        freeObstacleDirections(obstacleDirections, boardSizeX);
        freeOriginalBoard(originalBoard, boardSizeX);
        freeList(list, freedata);

        /* Restore original terminal settings */
        enableBuffer();
    }
    return 0;
}