#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

void insertInBST(node **, int);
void insertInBSTIteration(node **, int);
node *searchInBST(node **, int);
node *searchInBSTIteration(node **, int);

int main(){
    node *root = NULL;
}

void insertInBST(node **root, int val)
{
    if(*root == NULL)
    {
        *root = (node *)malloc(1 * sizeof(node));
        (*root)->data = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(val < (*root)->data)
    {
        insertInBST(&(*root)->left, val);
    }
    if(val > (*root)->data)
    {
        insertInBST(&(*root)->right, val);
    }

    return ;
}

void insertInBSTIteration(node **root, int val)
{
    node *current = *root;
    node *prev = NULL;

    while(current != NULL)
    {
        if(val < (current)->data)
        {
            prev = current;
            current = current->left;
        }
        else
        {
            prev = current;
            current = (current)->right;
        }
    }

    node *temp = (node *)malloc(1 * sizeof(node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    if(prev == NULL)
    {
        *root = temp;
    }
    else if(val < prev->data)
    {
        prev->left = temp;
    }
    else
    {
        prev->right = temp;
    }

    return ;
}

node *searchInBST(node **root, int val)
{
    if(*root == NULL)
    {
        printf("\nValue not found");
        return NULL;
    }
    else if(val < (*root)->data)
    {
        searchInBST(&(*root)->left, val);
    }
    else if(val > (*root)->data)
    {
        searchInBST(&(*root)->right, val);
    }
    else
    {
        return *root;
    }
}

node *searchInBSTIteration(node **root, int val)
{
    node *current = *root;

    while(current != NULL)
    {
        if(val < (current)->data)
        {
            current = current->left;
        }
        else if(val > (current)->data)
        {
            current = (current)->right;
        }
        else{
            return current;
        }
    }
    printf("\nValue not found");

    return NULL;
}