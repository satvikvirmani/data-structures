#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *forwardRef;
} node;

node *createList();
node *insertAtPos(node *, int);
node *deleteAtPos(node *, int);
node *tranverseList(node *);

int main()
{
    node *start;

    int pos;

    printf("Enter 1 to create a list.");
    printf("\nEnter 2 to insert a node.");
    printf("\nEnter 3 to delete a node.");
    printf("\nEnter 4 to tranverse the list.");
    printf("\nEnter 5 to exit.");

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    do
    {
        switch (choice)
        {
        case 1:
            start = createList();
            break;
        case 2:
            printf("\nEnter the position of node to be inserted: ");
            scanf("%d", &pos);
            start = insertAtPos(start, pos);
            break;
        case 3:
            printf("\nEnter the position of node to be deleted: ");
            scanf("%d", &pos);
            start = deleteAtPos(start, pos);
            break;
        case 4:
            tranverseList(start);
        case 5:
            break;
        default:
            printf("\nInvalid choice.");
            break;
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    } while (choice != 5);
}

node *createList()
{
    node *current, *start;
    current = NULL;

    node *temp;

    printf("\nEnter the data at node: ");
    int data;
    scanf("%d", &data);

    if (data == -1)
    {
        return current;
    }
    else
    {
        current = (node *)malloc(1 * sizeof(node));
        current->data = data;
        current->forwardRef = NULL;
        start = current;

        printf("\nEnter the data at node: ");
        scanf("%d", &data);
    }
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

    return start;
}

node *tranverseList(node *start)
{
    node *temp;
    temp = start;

    printf("\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->forwardRef;
    }

    return start;
}

node *insertAtPos(node *start, int pos)
{
    if (pos == 1)
    {
        node *newStart, *temp;

        printf("\nEnter the data at node: ");
        int data;
        scanf("%d", &data);

        temp = (node *)malloc(1 * sizeof(node));
        temp->data = data;
        temp->forwardRef = start;

        newStart = temp;

        return newStart;
    }
    node *nodeCount;

    nodeCount = start;

    printf("\nEnter the data at node: ");
    int data;
    scanf("%d", &data);
    int counter = 1;

    while (counter < pos - 1)
    {
        nodeCount = nodeCount->forwardRef;
        counter++;
    }

    node *temp;
    temp = (node *)malloc(1 * sizeof(node));
    temp->data = data;
    temp->forwardRef = nodeCount->forwardRef;

    nodeCount->forwardRef = temp;

    return start;
}

node *deleteAtPos(node *start, int pos)
{
    if (pos == 1)
    {

        node *newstart;

        newstart = start->forwardRef;
        free(start);

        return newstart;
    }

    node *nodeCount;
    node *delNode;

    nodeCount = start;
    int counter = 1;

    while (counter < pos - 1)
    {
        nodeCount = nodeCount->forwardRef;
        counter++;
    }

    delNode = nodeCount->forwardRef;
    nodeCount->forwardRef = (nodeCount->forwardRef)->forwardRef;

    free(delNode);

    return start;
}