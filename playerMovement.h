#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

#define PLAYER_CHAR 'P' /*Player character*/ 
#define LEFT_OBSTACLE_CHAR '<'  /*Left-moving obstacle character*/ 
#define RIGHT_OBSTACLE_CHAR '>' /*Right-moving obstacle character*/
#define UP_OBSTACLE_CHAR '^' /*Right-moving obstacle character*/
#define DOWN_OBSTACLE_CHAR 'v' /*Right-moving obstacle character*/
#define OBSTACLE_PATH_CHAR '.' /*Right-moving obstacle character*/
#define GOAL_CHAR 'G'   /*Goal character*/ 
#define DEATH_CHAR 'X'  /*Collision character*/ 
#define WIN_CHAR '!'    /*Winnign character*/ 

int movePlayer(char **board, char **originalBoard, int *playerX, int *playerY, int dx, int dy);
int checkPlayerMovementBorder(int *playerX, int *playerY, int dx, int dy, int boardSizeX, int boardSizeY);
int checkWin(char **board, int playerX, int playerY, int goalX, int goalY);

#endif
