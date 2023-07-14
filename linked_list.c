#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
    int data;
    struct node *link;
} node;

node *addNode(node*, int);
int insertAfter(node*, int);
int deleteAfter(node*, int);
int displayList(node *);

int main(){
    node *current, *start;

    current = (node *) malloc(1 * sizeof(node));
    current->data = 0;
    current->link = NULL;
    start = current;

    printf("Enter 1 to add a node.");
    printf("\nEnter 2 to insert a node after a node.");
    printf("\nEnter 3 to delete a node before a node.");
    printf("\nEnter 4 to display the list.");
    printf("\nEnter 5 to exit.");
    
    int choice, after = 0;
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int val;
                printf("\nEnter the data at the node: ");
                scanf("%d", &val);

                node *this;
                this = addNode(current, val);
                current = this;
                break;
            case 2:
                printf("\nEnter the data of the node after which node is to be inserted: ");
                scanf("%d", &after);

                insertAfter(start, after);
                break;
            case 3:
                printf("\nEnter the data of the node after which node is to be deleted: ");
                scanf("%d", &after);

                deleteAfter(start, after);
                break;
            case 4:
                displayList(start);
                break;
            case 5:
                break;
            default:
                printf("\nInvalid choice.");
                break;
        }
    } while(choice != 5);
    
    return 0;
}

node *addNode(node *prev, int val){
    node *thisNode;
    thisNode  = (node *) malloc(1 * sizeof(node));

    prev->link = thisNode;

    thisNode->data = val;
    thisNode->link = NULL;

    return thisNode;
}

int deleteAfter(node *start, int after){
    node *temp = start;
    while(temp != NULL){
        if (after == temp->data){
            break;
        }
        temp = temp->link;
    }

    node *tempDeletion;

    tempDeletion = temp->link;

    temp->link = (temp->link)->link;

    free(tempDeletion);

    return 1;
}

int insertAfter(node *start, int after){
    node *temp = start;
    while(temp != NULL){
        if (after == temp->data){
            break;
        }
        temp = temp->link;
    }
    node *thisNode;
    thisNode  = (node *) malloc(1 * sizeof(node));

    thisNode->link = temp->link;
    temp->link = thisNode;

    int val;
    printf("\nEnter the data at the node: ");
    scanf("%d", &val);

    thisNode->data = val;

    return 1;
}

int displayList(node *start){
    node *temp = start;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }

    return 1;
}