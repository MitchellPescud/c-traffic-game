#include <stdio.h>
#include <stdlib.h>
#include "printBoard.h"

void printBoard(char **board, int boardSizeX, int boardSizeY) {
    int i, j;
    system("clear");

    for (j = 0; j < boardSizeY + 2; j++) { /*Print top border*/
        printf("*");
    }
    printf("\n");
        
    for (i = 0; i < boardSizeX; i++) {
        printf("*");    /*Print left side border*/
        for (j = 0; j < boardSizeY; j++) {
            printf("%c", board[i][j]);  /*Game board*/
        }
        printf("*");    /*Print right side border*/
        printf("\n");
    }

    for (j = 0; j < boardSizeY + 2; j++) {
        printf("*");    /*Print bottom border*/
    }
    printf("\n");
    printf("Controls:\n");
    printf("w - Move up\n");
    printf("a - Move left\n");
    printf("s - Move down\n");
    printf("d - Move right\n");
    printf("q - Quit\n");
}