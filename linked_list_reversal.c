#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *forwardRef;
} node;

void createList(node **);
void tranverseList(node **);
void reverse(node **);

int main()
{
    //Header Node
    node *start;
    start = (node *)malloc(1 * sizeof(node));
    start->data = 0;

    int pos;

    printf("Enter 1 to create a list.");
    printf("\nEnter 2 to reverse the list.");
    printf("\nEnter 3 to tranverse the list.");
    printf("\nEnter 4 to exit.");

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    do
    {
        switch (choice)
        {
        case 1:
            createList(&start);
            break;
        case 2:
            reverse(&start);
            break;
        case 3:
            tranverseList(&start);
            break;
        case 4:
            break;
        default:
            printf("\nInvalid choice.");
            break;
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    } while (choice != 4);
}

void createList(node **start)
{
    node *temp, *current;

    current = *start;

    int data;
    printf("\nEnter the data at node: ");
    scanf("%d", &data);

    while (data != -1)
    {
        temp = (node *)malloc(1 * sizeof(node));
        current->forwardRef = temp;
        temp->data = data;
        temp->forwardRef = NULL;
        current = temp;
        printf("\nEnter the data at node: ");
        scanf("%d", &data);
    }
}

void tranverseList(node **start)
{
    node *temp;
    temp = (*start)->forwardRef;

    printf("\nList: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->forwardRef;
    }
}

void reverse(node **start){
    node *last, *current, *initNode;
    last = NULL;
    initNode = (*start)->forwardRef;

    while(initNode != NULL){
        current = initNode;
        initNode = current->forwardRef;
        current->forwardRef = last;
        last = current;
    }

    initNode = last;
    (*start)->forwardRef = initNode;
}