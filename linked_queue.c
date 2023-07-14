#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define QUEUE_EMPTY_ERROR -9999

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct queueNode
{
    node *nodeOfTree;
    struct queueNode *forwardRef;
} queueNode;

queueNode *rear = NULL;
queueNode *front = NULL;

void insertQ(node *);
node *delQ();
int isQEmpty();

int main()
{
    node *temp1 = (node *)malloc(1 * sizeof(node));
    temp1->data = 1;
    node *temp2 = (node *)malloc(1 * sizeof(node));
    temp2->data = 2;
    node *temp3 = (node *)malloc(1 * sizeof(node));
    temp3->data = 3;
    insertQ(temp1);
    insertQ(temp2);
    insertQ(temp3);

    delQ();
    
    delQ();
delQ();
printf("\n%d\n", delQ()->data);
    node *temp4 = (node *)malloc(1 * sizeof(node));
    temp4->data = 4;
    node *temp5 = (node *)malloc(1 * sizeof(node));
    temp5->data = 5;
    insertQ(temp4);
    insertQ(temp5);
    printf("\n%d\n", delQ()->data);
}

void insertQ(node *thisNode)
{
    queueNode *temp = (queueNode *)malloc(1 * sizeof(queueNode));

    if (rear != NULL)
    {
        rear->forwardRef = temp;
    }
    if (front == NULL)
    {
        front = temp;
    }
    temp->nodeOfTree = thisNode;
    temp->forwardRef = NULL;

    rear = temp;
}

node *delQ()
{
    if (front == NULL)
    {
        return NULL;
    }
    queueNode *tempqueueNode;
    node *temp;
    temp = front->nodeOfTree;
    tempqueueNode = front->forwardRef;

    free(front);

    front = tempqueueNode;

    if (front == NULL)
    {
        rear = NULL;
    }

    return temp;
}

int isQEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}