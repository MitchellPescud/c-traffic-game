#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char** data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

LinkedList* create_empty_list(void) {
    LinkedList* new_head = (LinkedList*)malloc(sizeof(LinkedList));
    new_head->head = NULL;
    return new_head;
}

Node* insert_end(LinkedList* list, char** data, int rows, int cols) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    int i, j;
    
    /*Allocate memory for the 2D array and copy data*/ 
    new_node->data = (char**)malloc(rows * sizeof(char*));
    for (i = 0; i < rows; i++) {
        new_node->data[i] = (char*)malloc(cols * sizeof(char));
        for (j = 0; j < cols; j++) {
            new_node->data[i][j] = data[i][j];
        }
    }
    
    new_node->next = NULL;
    
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    
    return list->head;
}

void remove_end(LinkedList* list, int rows) {
    int i;
    if (list->head == NULL) {
        return;
    } else if (list->head->next == NULL) {
        for (i = 0; i < rows; i++) {
            free(list->head->data[i]);
        }
        free(list->head->data);
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        Node* prev = NULL;

        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        for (i = 0; i < rows; i++) {
            free(current->data[i]);
        }
        free(current->data);
        free(current);
        prev->next = NULL;
    }
}

void print_list(LinkedList* list, int rows, int cols) {
    Node* current = list->head;
    int i, j;
    while (current != NULL) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("%c ", current->data[i][j]);
            }
            printf("\n");
        }
        current = current->next;
        printf("-----\n");
    }
}

void free_list(LinkedList* list, int rows) {
    int i;
    while (list->head != NULL) {
        Node* node = list->head;
        list->head = list->head->next;
        for (i = 0; i < rows; i++) {
            free(node->data[i]);
        }
        free(node->data);
        free(node);
    }
    free(list);
}

int main() {
    int rows = 3;
    int cols = 3;
    int i, j;
    LinkedList* myList = create_empty_list();
    char** array1 = (char**)malloc(rows * sizeof(char*));
    char** array2 = (char**)malloc(rows * sizeof(char*));
    char** array3 = (char**)malloc(rows * sizeof(char*));
    for (i = 0; i < rows; i++) {
        array1[i] = (char*)malloc(cols * sizeof(char));
    }
    
    for (i = 0; i < rows; i++) {
        array2[i] = (char*)malloc(cols * sizeof(char));
    }

    for (i = 0; i < rows; i++) {
        array3[i] = (char*)malloc(cols * sizeof(char));
    }
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            array1[i][j] = 'A' + i * cols + j;
            array2[i][j] = 'D' + i * cols + j;
            array3[i][j] = 'G' + i * cols + j;
        }
    }

    
    insert_end(myList, array1, rows, cols);
    insert_end(myList, array2, rows, cols);
    insert_end(myList, array3, rows, cols);

    printf("Linked List:\n");
    print_list(myList, rows, cols);

    remove_end(myList, rows);

    printf("Linked List after removing the last array:\n");
    print_list(myList, rows, cols);

    free_list(myList, rows);

    for (i = 0; i < rows; i++) {
        free(array1[i]);
        free(array2[i]);
        free(array3[i]);
    }
    free(array1);
    free(array2);
    free(array3);

    return 0;
}
