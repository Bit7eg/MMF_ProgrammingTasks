#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int num,
    count;
    scanf("%i%i", &count, &num);
    Node* head = NULL,
    * current = NULL;
    if((count <= 0) || (num <= 0)) {
        printf("Incorrect data");
        return 0;
    }
    head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    current = head;
    for(int i = 2; i <= count; i++) {
        current->next = (Node*)malloc(sizeof(Node));
        current = current->next;
        current->data = i;
    }
    current->next = head;
    while(head->next != head) {
        for(int i = 1; i < num; i++) {
            current = current->next;
        }
        head = current->next->next;
        free(current->next);
        current->next = head;
    }
    printf("%i", head->data);
    return 0;
}