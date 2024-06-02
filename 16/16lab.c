#include <stdio.h>
#include <stdlib.h>

#define NIL NULL

typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error for the new node.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NIL;
    newNode->next = NIL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NIL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = NIL;
    Node* head2 = NIL;
    Node* temp = NIL;
    Node* current = NIL;
    int num, count = 0;
    
    printf("Enter a sequence of numbers (enter 0 to complete):\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        count++;
        if (count % 2 == 1) {
            if (head1 == NIL) {
                head1 = createNode(num);
                temp = head1;
            } else {
                temp->next = createNode(num);
                temp->next->prev = temp;
                temp = temp->next;
            }
        } else {
            if (head2 == NIL) {
                head2 = createNode(num);
                current = head2;
            } else {
                current->next = createNode(num);
                current->next->prev = current;
                current = current->next;
            }
        }
    }
    
    if (count % 2 == 1) {
        current->next = NIL;
    } else {
        temp->next = NIL;
    }
    
    Node S = { NIL, count, head1 };
    
    // Вывод списка
    printf("Elements of the first list: ");
    printList(S.next);
    printf("Elements of the second list: ");
    printList(S.next->next);
    
    return 0;
}
