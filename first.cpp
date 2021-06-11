#include <stdio.h>

typedef struct __node{
    int data;
    struct __node* next;
}Node;

int main(void){
    Node* head;
    head = (Node*)malloc(sizeof(Node));
    
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = 1;
    newnode -> next = head;
}