#include <stdio.h>
#include <stdlib.h>

#define INDEX_EXCEED_ERROR -9999

typedef struct node
{
    int exp;
    int coef;
    struct node *forwardRef;
} node;

void inputPoly(node**);
node*getAtPos(node**, int);
void addPoly(node**, node**, node**);
void printPoly(node**);

int main()
{
    node *poly1, *poly2, *poly3;
    poly1 = NULL;
    poly2 = NULL;
    poly3 = NULL;

    inputPoly(&poly1);
    inputPoly(&poly2);

    addPoly(&poly1, &poly2, &poly3);

    return 0;
}

void inputPoly(node **poly)
{
    printf("\nEnter the polynomial:\n");

    node *temp, *current;
    current = *poly;

    int exp, coef;

    printf("Enter the exponent coefficient pair: ");
    scanf("%d %d", &exp, &coef);

    while(exp != -1)
    {
        if(coef != 0)
        {
            temp = (node *)malloc(1 * sizeof(node));
            if(current !=NULL)
            {
                current->forwardRef = temp;
            }
            else
            {
                *poly = temp;
            }

            temp->exp = exp;
            temp->coef = coef;
            temp->forwardRef = NULL;

            current = temp;
        }

        printf("Enter the exponent coefficient pair: ");
        scanf("%d %d", &exp, &coef);
    }
}

node *getAtPos(node **start, int pos)
{
    node *temp;
    temp = *start;

    int counter = 1;

    while(counter < pos && temp!=NULL)
    {
        temp = temp->forwardRef;
        counter++;
    }

    return temp;
}

void addPoly(node **poly1, node **poly2, node **poly3)
{
    node *temp, *current;
    current = *poly3;

    int i, j, k;
    i = 1;
    j = 1;
    k = 1;


    while(getAtPos(&(*poly1), i) != NULL && getAtPos(&(*poly2), j) != NULL)
    {

        if(getAtPos(&(*poly1), i)->exp > getAtPos(&(*poly2), j)->exp)
        {
            temp = (node *)malloc(1 * sizeof(node));
            if(current !=NULL)
            {
                current->forwardRef = temp;
            }
            else
            {
                *poly3 = temp;
            }

            temp->exp = getAtPos(&(*poly1), i)->exp;
            temp->coef = getAtPos(&(*poly1), i)->coef;
            temp->forwardRef = NULL;

            current = temp;
            i++;
        }
        else if(getAtPos(&(*poly1), i)->exp < getAtPos(&(*poly2), j)->exp)
        {
            temp = (node *)malloc(1 * sizeof(node));
            if(current !=NULL)
            {
                current->forwardRef = temp;
            }
            else
            {
                *poly3 = temp;
            }

            temp->exp = getAtPos(&(*poly2), j)->exp;
            temp->coef = getAtPos(&(*poly2), j)->coef;
            temp->forwardRef = NULL;

            current = temp;
            j++;
        }
        else
        {
            if(getAtPos(&(*poly1), i)->coef + getAtPos(&(*poly2), j)->coef != 0)
            {
                temp = (node *)malloc(1 * sizeof(node));
                if(current !=NULL)
                {
                    current->forwardRef = temp;
                }
                else
                {
                    *poly3 = temp;
                }

                temp->exp = getAtPos(&(*poly2), j)->exp;
                temp->coef = getAtPos(&(*poly1), i)->coef + getAtPos(&(*poly2), j)->coef;
                temp->forwardRef = NULL;

                current = temp;
            }
            i++;
            j++;
        }
    }

    while(getAtPos(&(*poly1), i) != NULL)
    {
        temp = (node *)malloc(1 * sizeof(node));
        if(current !=NULL)
        {
            current->forwardRef = temp;
        }
        else
        {
            *poly3 = temp;
        }

        temp->exp = getAtPos(&(*poly1), i)->exp;
        temp->coef = getAtPos(&(*poly1), i)->coef;
        temp->forwardRef = NULL;

        current = temp;
        i++;
    }

    while(getAtPos(&(*poly2), j) != NULL)
    {
        temp = (node *)malloc(1 * sizeof(node));
        if(current !=NULL)
        {
            current->forwardRef = temp;
        }
        else
        {
            *poly3 = temp;
        }

        temp->exp = getAtPos(&(*poly2), j)->exp;
        temp->coef = getAtPos(&(*poly2), j)->coef;
        temp->forwardRef = NULL;

        current = temp;
        j++;
    }

    printPoly(&(*poly1));
    printf("+\n");
    printPoly(&(*poly2));
    printf("=\n");
    printPoly(&(*poly3));
}

void printPoly(node **start)
{
    node *temp;
    temp = *start;

    while(temp->forwardRef != NULL)
    {
        printf("%dX^%d + ", temp->coef, temp->exp);
        temp = temp->forwardRef;
    }

    printf("%dX^%d", temp->coef, temp->exp);

    printf("\n");
}