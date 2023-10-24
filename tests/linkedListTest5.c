#include <stdio.h>
#include <stdlib.h>
#define LEFT_OBSTACLE_CHAR '<'  /*Left-moving obstacle character*/ 
#define RIGHT_OBSTACLE_CHAR '>' /*Right-moving obstacle character*/
#define UP_OBSTACLE_CHAR '^' /*Right-moving obstacle character*/
#define DOWN_OBSTACLE_CHAR 'v' /*Right-moving obstacle character*/
#define OBSTACLE_PATH_CHAR '.' /*Right-moving obstacle character*/
#define PLAYER_CHAR 'P' /*Player character*/ 
#define GOAL_CHAR 'G'   /*Goal character*/ 

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

LinkedList* createList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    list->head = NULL;
    return list;
}

void insert(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertLast(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void removeLastElement(LinkedList *list, void (*freeFunction)(void *)) {
    Node *current = list->head;
    Node *prev = NULL;
    
    if (list->head == NULL) {
        return;
    }

    if (current->next == NULL) {
        freeFunction(current->data);
        free(current);
        list->head = NULL;
        return;
    }

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    freeFunction(current->data);
    free(current);

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        list->head = NULL;
    }
}

void* getLastElement(LinkedList *list) {
    Node *current = list->head;
    if (current == NULL) {
        return NULL;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    return current->data;
}

void printList(LinkedList *list, void (*printFunction)(void *)) {
    Node *current = list->head;
    while (current != NULL) {
        printFunction(current->data);
        current = current->next;
    }
}

void freeList(LinkedList *list, void (*freeFunction)(void *)) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;

        freeFunction(temp->data);
        free(temp);
    }
    list->head = NULL;
    free(list);
}

void printBoard(char **board, int boardSizeX, int boardSizeY) {
    int i, j;
    for (i = 0; i < boardSizeX; i++) {
        for (j = 0; j < boardSizeY; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printList2DArray(LinkedList *list, int boardSizeX, int boardSizeY) {
    Node *current = list->head;
    while (current != NULL) {
        char **board = (char **)current->data;
        printBoard(board, boardSizeX, boardSizeY);
        current = current->next;
    }
}

void free2DArray(void *data) {
    free(data);
}

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

void exportListToTextFile(LinkedList *list, int boardSizeX, int boardSizeY, const char *filename) {
    int i, j;
    Node *current = list->head;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening the file for writing");
        exit(1);
    }

    
    while (current != NULL) {
        char **board = (char **)current->data;
        for (i = 0; i < boardSizeX; i++) {
            for (j = 0; j < boardSizeY; j++) {
                fprintf(file, "%c ", board[i][j]);
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
        current = current->next;
    }

    fclose(file);
}

int main() {
    int i, j;
    int boardSizeX, boardSizeY;
    char **board;
    char **board1;
    char **board2;
    FILE *file = fopen("game_3.txt", "r");
    FILE *file2 = fopen("game_4.txt", "r");
    LinkedList *list = createList();
    if (file == NULL) {
        perror("Error opening the file");
        exit(1);
    }

    fscanf(file, "%d %d", &boardSizeX, &boardSizeY);
    board1 = (char **)malloc(boardSizeX * sizeof(char *));
    for (i = 0; i < boardSizeX; i++) {
        (board1)[i] = (char *)malloc(boardSizeY * sizeof(char));
    }
    for (i = 0; i < boardSizeX; i++) {
        for (j = 0; j < boardSizeY; j++) {
            char value;
            fscanf(file, " %c", &value);
            switch (value) {
                case '0':
                    (board1)[i][j] = ' ';
                    break;
                case '1':
                    (board1)[i][j] = OBSTACLE_PATH_CHAR;
                    break;
                case '2':
                    (board1)[i][j] = DOWN_OBSTACLE_CHAR;
                    break;
                case '3':
                    (board1)[i][j] = PLAYER_CHAR;
                    break;
                case '4':
                    (board1)[i][j] = GOAL_CHAR;
                    break;
                default:
                    /* Handle other values as needed */
                    break;
            }
        }
    }
    fclose(file);

    insertLast(list, board1);

    fscanf(file2, "%d %d", &boardSizeX, &boardSizeY);
    board2 = (char **)malloc(boardSizeX * sizeof(char *));
    for (i = 0; i < boardSizeX; i++) {
        (board2)[i] = (char *)malloc(boardSizeY * sizeof(char));
    }
    for (i = 0; i < boardSizeX; i++) {
        for (j = 0; j < boardSizeY; j++) {
            char value;
            fscanf(file2, " %c", &value);
            switch (value) {
                case '0':
                    (board2)[i][j] = ' ';
                    break;
                case '1':
                    (board2)[i][j] = OBSTACLE_PATH_CHAR;
                    break;
                case '2':
                    (board2)[i][j] = DOWN_OBSTACLE_CHAR;
                    break;
                case '3':
                    (board2)[i][j] = PLAYER_CHAR;
                    break;
                case '4':
                    (board2)[i][j] = GOAL_CHAR;
                    break;
                default:
                    /* Handle other values as needed */
                    break;
            }
        }
    }
    fclose(file2);

    insertLast(list, board2);
    
    insertLast(list, duplicateBoard(board1, boardSizeX, boardSizeY));

    printList2DArray(list, boardSizeX, boardSizeY);

    exportListToTextFile(list, boardSizeX, boardSizeY, "output.txt");

    removeLastElement(list, free2DArray);

    board = getLastElement(list);

    printBoard(board, boardSizeX, boardSizeY);

    return 0;
}
