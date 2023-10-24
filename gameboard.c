#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameboard.h"

/* Function to initialize the game board and player/goal positions */
void initializeBoard(char ***board, char ***originalBoard, int *playerX, int *playerY, int *goalX, int *goalY, int *boardSizeX, int *boardSizeY, int ***obstacleDirections, const char *filename) {
    int i, j;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file");
        exit(1);
    }

    fscanf(file, "%d %d", boardSizeX, boardSizeY);

    /* Create board, originalBoard, and obstacleDirections arrays */
    *board = (char **)malloc(*boardSizeX * sizeof(char *));
    *originalBoard = (char **)malloc(*boardSizeX * sizeof(char *));
    *obstacleDirections = (int **)malloc(*boardSizeX * sizeof(int *));
    for (i = 0; i < *boardSizeX; i++) {
        (*board)[i] = (char *)malloc(*boardSizeY * sizeof(char));
        (*originalBoard)[i] = (char *)malloc(*boardSizeY * sizeof(char));
        (*obstacleDirections)[i] = (int *)malloc(*boardSizeY * sizeof(int));
    }

    for (i = 0; i < *boardSizeX; i++) {
        for (j = 0; j < *boardSizeY; j++) {
            char value;
            fscanf(file, " %c", &value);
            switch (value) {
                case '0':
                    (*board)[i][j] = ' ';
                    (*originalBoard)[i][j] = ' ';
                    break;
                case '1':
                    (*board)[i][j] = OBSTACLE_PATH_CHAR;
                    (*originalBoard)[i][j] = OBSTACLE_PATH_CHAR;
                    break;
                case '2':
                    (*board)[i][j] = RIGHT_OBSTACLE_CHAR;
                    (*obstacleDirections)[i][j] = RIGHT;
                    (*originalBoard)[i][j] = OBSTACLE_PATH_CHAR;
                    break;
                case '3':
                    *playerX = i;
                    *playerY = j;
                    (*board)[i][j] = PLAYER_CHAR;
                    (*originalBoard)[i][j] = ' ';
                    break;
                case '4':
                    *goalX = i;
                    *goalY = j;
                    (*board)[i][j] = GOAL_CHAR;
                    (*originalBoard)[i][j] = ' ';
                    break;
                default:
                    /* Handle other values as needed */
                    break;
            }
        }
    }
    fclose(file);
}

/* Function to duplicate the game board */
char** duplicateBoard(char** board, int boardSizeX, int boardSizeY) {
    int i, j;
    char** duplicate = (char**)malloc(boardSizeX * sizeof(char*));
    if (duplicate == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    for (i = 0; i < boardSizeX; i++) {
        duplicate[i] = (char*)malloc(boardSizeY * sizeof(char));
        if (duplicate[i] == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        for (j = 0; j < boardSizeY; j++) {
            duplicate[i][j] = board[i][j];
        }
    }

    return duplicate;
}
