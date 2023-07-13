#include <stdio.h>

typedef struct polyterm
{
    int exponent;
    int coeficient;
} polyterm;

int poly_add_struct(polyterm[], polyterm[], polyterm[], int, int);

int main() {
    int i;

    int n1;
    int n2;

    printf("Enter the number of terms of polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the number of terms of polynomial 2: ");
    scanf("%d", &n2);

    polyterm poly1[n1];
    polyterm poly2[n2];
    
    int max_n3 = n1 + n2;
    polyterm poly3[max_n3];
    
    printf("\nEnter polynomial 1\n");
    for(i = 0; i < n1; i++){
        printf("Exponent: ");
        scanf("%d", &poly1[i].exponent);
        printf("Coeficient: ");
        scanf("%d", &poly1[i].coeficient);
    }
    
    printf("\nEnter polynomial 2\n");
    for(i = 0; i < n2; i++){
        printf("Exponent: ");
        scanf("%d", &poly2[i].exponent);
        printf("Coeficient: ");
        scanf("%d", &poly2[i].coeficient);
    }
    
    int n3 = poly_add_struct(poly1, poly2, poly3, n1, n2);
    
    printf("\nPolynomial 3\n");
    for(i = 0; i < n3; i++){
        printf("Exponent: %d\n", poly3[i].exponent);
        printf("Coeficient: %d\n", poly3[i].coeficient);
    }
}

int poly_add_struct(polyterm poly1[], polyterm poly2[], polyterm poly3[], int n1, int n2){
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(poly1[i].exponent > poly2[j].exponent){
            poly3[k] = poly1[i];
            i++;
        }
        else if(poly1[i].exponent < poly2[j].exponent){
            poly3[k] = poly2[j];
            j++;
        }
        else{
            poly3[k].exponent = poly1[i].exponent;
            poly3[k].coeficient = poly1[i].coeficient + poly2[j].coeficient;
            i++;
            j++;
        }
        k++;
    }
    while(i < n1){
        poly3[k] = poly1[i];
        i++;
        k++;
    }
    while(j < n2){
        poly3[k] = poly2[j];
        j++;
        k++;
    }
    
    return k;
}
