#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#define PLAYER_CHAR 'P' /*Player character*/ 
#define LEFT_OBSTACLE_CHAR '<'  /*Left-moving obstacle character*/ 
#define RIGHT_OBSTACLE_CHAR '>' /*Right-moving obstacle character*/
#define UP_OBSTACLE_CHAR '^' /*Right-moving obstacle character*/
#define DOWN_OBSTACLE_CHAR 'v' /*Right-moving obstacle character*/
#define OBSTACLE_PATH_CHAR '.' /*Right-moving obstacle character*/
#define GOAL_CHAR 'G'   /*Goal character*/ 
#define DEATH_CHAR 'X'  /*Collision character*/ 
#define WIN_CHAR '!'    /*Winnign character*/ 
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

void initializeBoard(char ***board, char ***originalBoard, int *playerX, int *playerY, int *goalX, int *goalY, int *boardSizeX, int *boardSizeY, int ***obstacleDirections, const char *filename);
char** duplicateBoard(char** board, int boardSizeX, int boardSizeY);


#endif