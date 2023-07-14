#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define bool int
#define MAX 100
#define STACK_FULL NULL
#define STACK_EMPTY NULL
#define QUEUE_EMPTY_ERROR -9999

typedef struct node
{
    struct node *parent;
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct queueNode
{
    node *nodeOfTree;
    struct queueNode *forwardRef;
} queueNode;

void createTree(node **, FILE *);
void createTreeImproved(node **, FILE *);
void createTreeCall(node **, FILE *, node *, char);
void inorderTraversal(node **);
void preorderTraversal(node **);
void postorderTraversal(node **);
void inorderTraversalIteration(node **);
void preorderTraversalIteration(node **);
void postorderTraversalIteration(node **);
void levelorderTraversal(node **);
bool viewAncestors(node **, int);
int findHeight(node **);
int countNodes(node **);
node *maximumNode(node **);
node *minimumNode(node **);
int countLeafNodes(node **);
int countNonLeafNodes(node **);
void copyTree(node **, node **);
bool areEqual(node **, node **);
void mirrorTree(node **);
bool isSkewed(node **);
bool isLeftSkewed(node **);
bool isRightSkewed(node **);
bool isBST(node **);
node *push(node *);
node *pop();
node *peek();
bool isStackFull();
bool isStackEmpty();
int maximum(int, int);
void insertQ(node *);
node *delQ();
int isQEmpty();

queueNode *rear = NULL;
queueNode *front = NULL;

node *stack[MAX];
int top = -1;

int main()
{
    FILE *finA = NULL;
    finA = fopen("inputA.txt", "r");

    node *root = NULL;
    int temp;

    printf("Does root node exist? (1 - Yes): ");
    fscanf(finA, "%d ", &temp);
    if (temp == 1)
    {
        createTree(&root, finA);
    }
    //createTreeImproved(&root, finA);

    FILE *finB = NULL;
    finB = fopen("inputB.txt", "r");

    node *rootOther = NULL;
    int tempOther;

    printf("Does root node exist? (1 - Yes): ");
    fscanf(finB, "%d ", &tempOther);
    if (tempOther == 1)
    {
        createTree(&rootOther, finB);
    }
    //createTreeImproved(&rootOther, finB);

    printf("\nHeight of tree created: %d", findHeight(&root));
    printf("\nNumber of nodes in tree created: %d", countNodes(&root));
    printf("\nMaximum value in tree created: %d", maximumNode(&root)->data);
    printf("\nMinimum value in tree created: %d", minimumNode(&root)->data);
    printf("\nNumber of leaf nodes in tree created: %d", countLeafNodes(&root));
    printf("\nNumber of non leaf nodes in tree created: %d", countNonLeafNodes(&root));
    printf("\nAre tree A and tree B equal? %d", areEqual(&root, &rootOther));
    printf("\nIs tree skewed? %d", isSkewed(&root));
    printf("\nIs tree left skewed? %d", isLeftSkewed(&root));
    printf("\nIs tree right skewed? %d", isRightSkewed(&root));
    printf("\nIs tree a binary search tree? %d", isBST(&root));

    node *copyRoot = NULL;
    copyTree(&root, &copyRoot);

    mirrorTree(&root);

    int traversalChoice;
    printf("\nTraversal of the Tree:\n1 for Inorder\n2 for Preorder\n3 for Postorder\n4 for Inorder(iteration)\n5 for Preorder(iteration)\n6 for Postorder(iteration)\n7 for Level Order Tranversal\n8 to view ancestors\nEnter your choice: ");
    scanf("%d", &traversalChoice);

    switch (traversalChoice)
    {
    case 1:
        inorderTraversal(&root);
        printf("\n");
        inorderTraversal(&copyRoot);
        break;
    case 2:
        preorderTraversal(&root);
        printf("\n");
        preorderTraversal(&copyRoot);
        break;
    case 3:
        postorderTraversal(&root);
        printf("\n");
        postorderTraversal(&copyRoot);
        break;
    case 4:
        inorderTraversalIteration(&root);
        printf("\n");
        inorderTraversalIteration(&copyRoot);
        break;
    case 5:
        preorderTraversalIteration(&root);
        printf("\n");
        preorderTraversalIteration(&copyRoot);
        break;
    case 6:
        postorderTraversalIteration(&root);
        printf("\n");
        postorderTraversalIteration(&copyRoot);
        break;
    case 7:
        levelorderTraversal(&root);
        printf("\n");
        levelorderTraversal(&copyRoot);
        break;
    case 8:
        int temp;
        printf("\nEnter the value of node whose ancestors are to be displayed: ");
        scanf("%d", &temp);
        viewAncestors(&root, temp);
        printf("\n");
        viewAncestors(&copyRoot, temp);
        break;
    default:
        printf("Invalid Choice");
        break;
    }

    fclose(finA);
    fclose(finB);

    return 1;
}

void createTree(node **root, FILE *file)
{
    *root = (node *)malloc(1 * sizeof(node));
    (*root)->left = NULL;
    (*root)->right = NULL;

    printf("Enter the data: ");
    fscanf(file, "%d", &((*root)->data));

    int choice;

    printf("Does this node (%d) has a left child? (1 - Yes): ", (*root)->data);
    fscanf(file, "%d", &choice);
    if (choice == 1)
    {
        createTree(&((*root)->left), file);
    }
    printf("Does this node (%d) has a right child? (1 - Yes): ", (*root)->data);
    fscanf(file, "%d", &choice);
    if (choice == 1)
    {
        createTree(&((*root)->right), file);
    }
}

void createTreeImproved(node **root, FILE *file){
    int temp;
    printf("Enter the data of root node: ");
    scanf("%d", &temp);
    if(temp == -1){
        return ;
    }

    *root = (node *)malloc(1 * sizeof(node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->parent = NULL;
    (*root)->data = temp;

    createTreeCall(&(*root)->left, file, *root, 'l');
    createTreeCall(&(*root)->right, file, *root, 'r');
}

void createTreeCall(node **root, FILE *file, node *parent, char child)
{
    int temp;
    if(child == 'l'){
        printf("Enter node (%d)'s left child (-1 for NULL): ", parent->data);
    }else if(child == 'r'){
        printf("Enter node (%d)'s rigth child (-1 for NULL): ", parent->data);
    }
    scanf("%d", &temp);
    if(temp == -1){
        return ;
    }

    *root = (node *)malloc(1 * sizeof(node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->parent = parent;
    (*root)->data = temp;

    createTreeCall(&(*root)->left, file, *root, 'l');
    createTreeCall(&(*root)->right, file, *root, 'r');
}

void inorderTraversal(node **root)
{
    if (*root == NULL)
    {
        return ;
    }
    inorderTraversal(&((*root)->left));
    printf("%d", (*root)->data);
    inorderTraversal(&((*root)->right));
}

void preorderTraversal(node **root)
{
    if (*root == NULL)
    {
        return;
    }
    printf("%d", (*root)->data);
    preorderTraversal(&((*root)->left));
    preorderTraversal(&((*root)->right));
}

void postorderTraversal(node **root)
{
    if (*root == NULL)
    {
        return;
    }
    postorderTraversal(&((*root)->left));
    postorderTraversal(&((*root)->right));
    printf("%d", (*root)->data);
}

void inorderTraversalIteration(node **root)
{
    node *current = *root;
    bool done = FALSE;

    while (!done)
    {
        if (current != NULL)
        {
            push(current);
            current = current->left;
        }
        else
        {
            if (!isStackEmpty())
            {
                current = pop();
                printf("%d", current->data);

                current = current->right;
            }
            else
            {
                done = TRUE;
            }
        }
    }
}

void preorderTraversalIteration(node **root)
{
    node *current = *root;
    bool done = FALSE;

    push(*root);

    while (!isStackEmpty())
    {
        current = pop();
        printf("%d", current->data);

        if (current->right != NULL)
        {
            push(current->right);
        }
        if (current->left != NULL)
        {
            push(current->left);
        }
    }
}

void postorderTraversalIteration(node **root)
{
    node *current = *root;
    bool done = FALSE;

    do
    {
        while (current != NULL)
        {
            if (current->right != NULL)
            {
                push(current->right);
            }
            push(current);

            current = current->left;
        }
        current = pop();

        if (current->right != NULL && current->right == peek())
        {
            pop();
            push(current);

            current = current->right;
        }
        else
        {
            printf("%d", current->data);
            current = NULL;
        }
    } while (!isStackEmpty());
}

void levelorderTraversal(node **root)
{
    node *temp;
    if(*root == NULL)
    {
        return ;
    }
    insertQ(*root);
    insertQ(NULL);
    while(!isQEmpty())
    {
        temp = delQ();
        if(temp == NULL){
            printf("\n");
            if(!isQEmpty()){
                insertQ(NULL);
            }
            continue;
        }
        printf("%d", temp->data);
        if(temp->left != NULL){
            insertQ(temp->left);
        }
        if(temp->right != NULL){
            insertQ(temp->right);
        }
    }
}

bool viewAncestors(node **root, int val)
{
    if(*root == NULL)
    {
        return FALSE;
    }
    if((*root)->data == val)
    {
        return TRUE;
    }
    if(viewAncestors(&((*root)->left), val) || viewAncestors(&((*root)->right), val))
    {
        printf("%d ", (*root)->data);
        return TRUE;
    }
    return FALSE;
}

int findHeight(node **root)
{
    if(*root == NULL){
        return 0;
    }
    int leftHeight = findHeight(&((*root)->left));
    int rightHeight = findHeight(&((*root)->right));
    return maximum(leftHeight, rightHeight) + 1;
}

int countNodes(node **root)
{
 if(*root == NULL){
    return 0;
 }
 int nNodesLeft = countNodes(&(*root)->left);
 int nNodesRight = countNodes(&(*root)->right);

 return nNodesLeft + nNodesRight + 1;
}

node *maximumNode(node **root)
{
    if((*root)->left != NULL && (*root)->right != NULL){
        node *maxInLeft = maximumNode(&(*root)->left);
        node *maxInRight = maximumNode(&(*root)->right);

        if(maxInLeft->data > maxInRight->data){
            if((*root)->data > maxInLeft->data){
                return *root;
            }
            else{
                return maxInLeft;
            }
        }
        else{
            if((*root)->data > maxInRight->data){
                return *root;
            }
            else{
                return maxInRight;
            }
        }
    }
    if((*root)->left != NULL){
        node *maxInLeft = maximumNode(&(*root)->left);
        if(maxInLeft->data > (*root)->data){
            return maxInLeft;
        }
        return *root;
    }
    if((*root)->right != NULL){
        node *maxInRight = maximumNode(&(*root)->right);
        if(maxInRight->data > (*root)->data){
            return maxInRight;
        }
        return *root;
    }
    return *root;
}

node *minimumNode(node **root)
{
    if((*root)->left != NULL && (*root)->right != NULL){
        node *minInLeft = minimumNode(&(*root)->left);
        node *minInRight = minimumNode(&(*root)->right);

        if(minInLeft->data < minInRight->data){
            if((*root)->data < minInLeft->data){
                return *root;
            }
            else{
                return minInLeft;
            }
        }
        else{
            if((*root)->data < minInRight->data){
                return *root;
            }
            else{
                return minInRight;
            }
        }
    }
    if((*root)->left != NULL){
        node *minInLeft = minimumNode(&(*root)->left);
        if(minInLeft->data < (*root)->data){
            return minInLeft;
        }
        return *root;
    }
    if((*root)->right != NULL){
        node *minInRight = minimumNode(&(*root)->right);
        if(minInRight->data < (*root)->data){
            return minInRight;
        }
        return *root;
    }
    return *root;
}

int countLeafNodes(node **root)
{
    if(*root == NULL){
        return 0;
    }
    if((*root)->left == NULL && (*root)->right == NULL){
        return 1;
    }
    return countLeafNodes(&((*root)->left)) + countLeafNodes(&((*root)->right));
}

int countNonLeafNodes(node **root)
{
    if(*root == NULL){
        return 0;
    }
    if((*root)->left == NULL && (*root)->right == NULL){
        return 0;
    }
    return 1 + countNonLeafNodes(&((*root)->left)) + countNonLeafNodes(&((*root)->right));
}

void copyTree(node **root, node **copyRoot)
{
    if(*root == NULL){
        return ;
    }
    *copyRoot = (node *)malloc(1 * sizeof(node));
    (*copyRoot)->data = (*root)->data;
    (*copyRoot)->left = NULL;
    (*copyRoot)->right = NULL;

    copyTree(&((*root)->left), &((*copyRoot)->left));
    copyTree(&((*root)->right), &((*copyRoot)->right));
}

bool areEqual(node **rootA, node **rootB)
{
    if(*rootA == NULL && *rootB == NULL)
    {
        return TRUE;
    }
    if(*rootA == NULL && *rootB != NULL || *rootA != NULL && *rootB == NULL)
    {
        return FALSE;
    }
    if((*rootA)->data == (*rootB)->data)
    {
        return TRUE*areEqual(&((*rootA)->left), &((*rootB)->left))*areEqual(&((*rootA)->right), &((*rootB)->right));
    }
    return FALSE;
}

void mirrorTree(node **root)
{
    if(*root == NULL){
        return ;
    }
    mirrorTree(&((*root)->left));
    mirrorTree(&((*root)->right));

    node *temp;
    temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;
}

bool isSkewed(node **root)
{
    if(*root == NULL)
    {
        return TRUE;
    }
    if((*root)->left != NULL && (*root)->right != NULL)
    {
        return FALSE;
    }
    if((*root)->left != NULL)
    {
        return isSkewed(&((*root)->left));
    }
    if((*root)->right != NULL)
    {
        return isSkewed(&((*root)->right));
    }
    return TRUE;

}

bool isLeftSkewed(node **root)
{
    if(*root == NULL)
    {
        return TRUE;
    }
    if((*root)->right != NULL)
    {
        return FALSE;
    }
    if(isLeftSkewed(&((*root)->left)))
    {
        return TRUE;
    }
    return FALSE;
}

bool isRightSkewed(node **root)
{
    if(*root == NULL)
    {
        return TRUE;
    }
    if((*root)->left != NULL)
    {
        return FALSE;
    }
    if(isLeftSkewed(&((*root)->right)))
    {
        return TRUE;
    }
    return FALSE;
}

bool isBST(node **root)
{
    if(*root == NULL)
    {
        return TRUE;
    }
    if((*root)->left != NULL && (*root)->right != NULL)
    {
        return isBST(&((*root)->left))*isBST(&((*root)->right))*((*root)->left->data < (*root)->data)*((*root)->right->data > (*root)->data);
    }
    if((*root)->left != NULL)
    {
        return isBST(&((*root)->left))*((*root)->left->data < (*root)->data);
    }
    if((*root)->right != NULL)
    {
        return isBST(&((*root)->right))*((*root)->right->data > (*root)->data);
    }
    return TRUE;
}

node *push(node *temp)
{
    if (top < MAX - 1)
    {
        stack[++top] = temp;
        return temp;
    }
    return STACK_FULL;
}

node *pop()
{
    if (top > -1)
    {
        return stack[top--];
    }
    return STACK_EMPTY;
}

node *peek()
{
    if (top > -1)
    {
        return stack[top];
    }
    return STACK_EMPTY;
}

bool isStackFull()
{
    if (top == MAX - 1)
    {
        return TRUE;
    }
    return FALSE;
}

bool isStackEmpty()
{
    if (top == -1)
    {
        return TRUE;
    }
    return FALSE;
}

int maximum(int numA, int numB)
{
    if(numA > numB){
        return numA;
    }
    return numB;
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
