#ifndef OBSTACLEMOVEMENT_H
#define OBSTACLEMOVEMENT_H

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

void moveObstacles(char **board, char **originalBoard, int ***obstacleDirections, int boardSizeX, int boardSizeY);

#endif