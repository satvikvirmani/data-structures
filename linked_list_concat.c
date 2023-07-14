#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *forwardRef;
} node;

void createList(node **);
void tranverseList(node **);
void concatList(node **, node **);

int main()
{
    //Header Node List 1
    node *start1;
    start1 = (node *)malloc(1 * sizeof(node));
    start1->data = 0;

    //Header Node List 2
    node *start2;
    start2 = (node *)malloc(1 * sizeof(node));
    start2->data = 0;

    printf("Create List 1: \n");
    createList(&start1);
    tranverseList(&start1);

    printf("\nCreate List 2: \n");
    createList(&start2);
    tranverseList(&start1);

    concatList(&start1, &start2); // start2 is NULL after this

    printf("\nConcataneted List");
    tranverseList(&start1);

    return 0;
}

void createList(node **start)
{
    node *temp, *current;

    current = *start;

    int data;
    printf("Enter the data at node: ");
    scanf("%d", &data);

    while (data != -1)
    {
        temp = (node *)malloc(1 * sizeof(node));
        current->forwardRef = temp;
        temp->data = data;
        temp->forwardRef = NULL;
        current = temp;
        printf("Enter the data at node: ");
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

void concatList(node **start1, node **start2){
    node *temp;
    temp = (*start1)->forwardRef;

    while (temp->forwardRef != NULL)
    {
        temp = temp->forwardRef;
    }

    temp->forwardRef = (*start2)->forwardRef;

    free(*start2);

    *start2 = NULL;
}