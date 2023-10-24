#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
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

Node* insert_end(LinkedList* list, void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
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

Node* remove_end(LinkedList* list, void (*freeData)(void*)) {
    if (list->head == NULL) {
        return NULL;
    } else if (list->head->next == NULL) {
        freeData(list->head->data);
        free(list->head);
        list->head = NULL;
        return NULL;
    } else {
        Node* current = list->head;
        Node* prev = NULL;

        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        freeData(current->data);
        free(current);
        prev->next = NULL;
        return list->head;
    }
}

void print_list(LinkedList* list, void (*printData)(void*)) {
    Node* current = list->head;
    while (current != NULL) {
        printData(current->data);
        printf(" -> ");
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(LinkedList* list, void (*freeData)(void*)) {
    while (list->head != NULL) {
        Node* node = list->head;
        list->head = list->head->next;
        freeData(node->data);
        free(node);
    }
    free(list);
}

void printIntData(void* data) {
    printf("%d", *((int*)data));
}

void freeIntData(void* data) {
    free(data);
}

int main() {
    LinkedList* myList = create_empty_list();

    int* data1 = (int*)malloc(sizeof(int));
    int* data2 = (int*)malloc(sizeof(int));
    int* data3 = (int*)malloc(sizeof(int));

    *data1 = 1;
    insert_end(myList, data1);

    
    *data2 = 2;
    insert_end(myList, data2);

    
    *data3 = 3;
    insert_end(myList, data3);

    printf("Linked List: ");
    print_list(myList, printIntData);

    remove_end(myList, freeIntData);

    printf("Linked List after removing the last element: ");
    print_list(myList, printIntData);

    free_list(myList, freeIntData);

    return 0;
}