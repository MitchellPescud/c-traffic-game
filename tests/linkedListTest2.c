#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
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

Node* insert_end(LinkedList* list, char data) {
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

void remove_end(LinkedList* list) {
    if (list->head == NULL) {
        return;
    } else if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        Node* prev = NULL;

        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        free(current);
        prev->next = NULL;
    }
}

void print_list(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(LinkedList* list) {
    while (list->head != NULL) {
        Node* node = list->head;
        list->head = list->head->next;
        free(node);
    }
    free(list);
}

int main() {
    LinkedList* myList = create_empty_list();

    insert_end(myList, 'A');
    insert_end(myList, 'B');
    insert_end(myList, 'C');

    printf("Linked List: ");
    print_list(myList);

    remove_end(myList);

    printf("Linked List after removing the last character: ");
    print_list(myList);

    free_list(myList);

    return 0;
}