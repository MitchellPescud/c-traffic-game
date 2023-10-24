#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;
    int rows;
    int cols;
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

Node* insert_end(LinkedList* list, void* data, int rows, int cols) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    new_node->data = malloc(rows * cols * sizeof(char));
    new_node->rows = rows;
    new_node->cols = cols;
    memcpy(new_node->data, data, rows * cols * sizeof(char));
    
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

void remove_end(LinkedList* list) {
    if (list->head == NULL) {
        return;
    } else if (list->head->next == NULL) {
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

        free(current->data);
        free(current);
        prev->next = NULL;
    }
}

void print_list(LinkedList* list) {
    Node* current = list->head;
    int i, j;
    int rows = current->rows;
    int cols = current->cols;
    char* data = (char*)current->data;
    while (current != NULL) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("%c ", data[i * cols + j]);
            }
            printf("\n");
        }
        current = current->next;
        printf("-----\n");
    }
}

void free_list(LinkedList* list) {
    while (list->head != NULL) {
        Node* node = list->head;
        list->head = list->head->next;
        free(node->data);
        free(node);
    }
    free(list);
}

int main() {
    int rows = 3;
    int cols = 3;
    LinkedList* myList = create_empty_list();
    char array1[3][3] = {
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'}
    };

    char array2[3][3] = {
        {'J', 'K', 'L'},
        {'M', 'N', 'O'},
        {'P', 'Q', 'R'}
    };

    insert_end(myList, array1, rows, cols);
    insert_end(myList, array2, rows, cols);

    printf("Linked List:\n");
    print_list(myList);

    remove_end(myList);

    printf("Linked List after removing the last array:\n");
    print_list(myList);

    free_list(myList);

    return 0;
}
