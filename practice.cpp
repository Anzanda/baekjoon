#include <stdio.h>
#include <stdlib.h>

struct listNode{
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;

void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr currentPtr);
void printList(ListNodePtr currnetPtr);
void instructions(void);

void insert(ListNodePtr *sPtr, char value){
    ListNodePtr headNode = (*sPtr);
    ListNodePtr curNode = headNode->nextPtr;
    while(curNode != NULL){
        if(curNode->data > value){
             break;
        }
        curNode = curNode->nextPtr;
    }
    
    ListNodePtr targetNode = curNode;
    curNode = headNode;
    while(curNode->nextPtr != targetNode){
        curNode = curNode->nextPtr;
    }

    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
    newNode->nextPtr = curNode->nextPtr;
    curNode->nextPtr = newNode;
}

int main(){
    ListNodePtr startPtr = (ListNodePtr)malloc(sizeof(ListNode));
    startPtr->nextPtr = NULL;

    int choice;
    char item;

    instructions();
    printf("? ");
    scanf("%d", &choice);

    while(choice != 3){
        switch (choice){
        case 1:
            while(!getchar());
            printf("Enter a character: ");
            item = getchar();
            insert(&startPtr, item);
            printList(startPtr);
            break;
        
        case 2:
            while(!getchar());
            if(!isEmpty(startPtr)){
                printf("Enter character to be deleted: ");
                item = getchar();

                if(delete(&startPtr, item)){
                    printf("%c deleted. \n\n", item);
                    printList(startPtr);
                }
                else{
                    printf("%c not found. \n\n", item);
                }
            }
            else{
                printf("List is empty. \n\n");
            }
            break;

        default:
            printf("Invalid choice. \n\n");
            instructions;
            break;
        }
        printf("? ");
        scanf("%d", &choice);
    }
    printf("End of run. \n");
    return 0;
}

int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){
    if(currentPtr == NULL){
        printf("List is empty. \n\n");
    }
    else{
        printf("The list is : \n");
        while(currentPtr != NULL){
            printf(" %c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL \n\n");
    }
}

void instructions(){
    printf("Enter your choice : \n");
    printf("\t 1 to insert an element into the list. \n");
    printf("\t 2 to delete an element from the list. \n");
    printf("\t 3 to end. \n");
}

void insert(ListNodePtr *sPtr, char value){
    
}

char delete(ListNodePtr *sPtr, char value){

}