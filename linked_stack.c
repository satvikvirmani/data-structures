#include <stdio.h>
#include <stdlib.h>

#define ERROR -9999

typedef struct  node
{
    int data;
    struct node *backwardRef;
} node;

int push(node **, int);
int pop(node **);
int display(node **);

int main(){
    node *start;
    start = NULL;

    printf("Enter 1 to push.");
    printf("\nEnter 2 to pop.");
    printf("\nEnter 3 to display.");
    printf("\nEnter 4 to exit.");
    
    int choice;
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int val;
                printf("Enter the data: ");
                scanf("%d", &val);
                push(&start, val);
                break;
            case 2:
                pop(&start);
                break;
            case 3:
                display(&start);
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice.");
                break;
        }
    } while(choice != 4);
    
    return 0;
}

int push(node **start, int val){
    node *temp;
    temp = (node * )malloc(1 * sizeof(node));
    temp->data = val;
    temp->backwardRef = *start;

    *start = temp;

    return 1;
}

int pop(node **start){
    if(*start != NULL){
        int tempVal = (*start)->data;

        node *temp;
        temp = *start;

        *start = temp->backwardRef;

        free(temp);

        return tempVal;
    }

    return ERROR;
}

int display(node **start){
    node *temp;
    temp = *start;

    while(temp != NULL){
        printf("\n%d", temp->data);
        temp = (temp)->backwardRef;
    }
}