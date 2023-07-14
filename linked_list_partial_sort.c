#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *forwardRef;
} node;

void createList(node **);
void tranverseList(node **);
int partialSort(node **, int);

int main()
{
    // Header Node
    node *start;
    start = (node *)malloc(1 * sizeof(node));
    start->data = 0;

    printf("Create List: \n");
    createList(&start);
    tranverseList(&start);

    partialSort(&start, 5);
    printf("Partial Sorted List: \n");
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

int partialSort(node **start, int check)
{

    node *current;
    current = *start;

    while ((current->forwardRef) != NULL)
    {
        current = current->forwardRef;
    }

    node *lastNode;
    lastNode = current;

    current = *start;
    int flag = 0;
    node *firstOccurence = NULL;

    while (current->forwardRef != firstOccurence)
    {
        if (current->forwardRef != NULL && (current->forwardRef)->data >= check)
        {

            if(flag == 0){
                firstOccurence = current->forwardRef;
                flag = 1;
            }
            node *replacementNode;
            replacementNode = current->forwardRef;

            current->forwardRef = replacementNode->forwardRef;
            lastNode->forwardRef = replacementNode;
            replacementNode->forwardRef = NULL;

            lastNode = replacementNode;

        }
    else{
        current = current->forwardRef;
    }
    }
}