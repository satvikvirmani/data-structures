#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *forwardRef;
} node;

void createList(node **);
void tranverseList(node **);
void sort(node **);

int main()
{
    // Header Node
    node *start;
    start = (node *)malloc(1 * sizeof(node));
    start->data = 0;

    printf("Create List: \n");
    createList(&start);
    tranverseList(&start);

    sort(&start);

    printf("\n\nSorted List: ");
    tranverseList(&start);

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

void sort(node **start)
{
    node *initNode;
    initNode = (*start)->forwardRef;

    while (initNode != NULL)
    {
        int initData;
        initData = initNode->data;

        node *minNode;
        findMinimum(&initNode, &minNode);

        int temp;
        temp = minNode->data;

        minNode->data = initData;
        initNode->data = temp;

        initNode = initNode->forwardRef;
    }
}

void findMinimum(node **start, node **minNode)
{
    node *temp;
    temp = (*start);

    int min;
    min = (*start)->data;

    while (temp != NULL)
    {
        if (temp->data <= min)
        {
            min = temp->data;
            *minNode = temp;
        }
        temp = temp->forwardRef;
    }
}