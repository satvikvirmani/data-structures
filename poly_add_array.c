#include <stdio.h>

void poly_add_array(int[], int[], int[], int, int);

int main() {
    int i;
    
    int n1;
    int n2;

    printf("Enter the number of terms of polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the number of terms of polynomial 2: ");
    scanf("%d", &n2);

    int poly1[n1];
    int poly2[n2];
    
    printf("\nEnter polynomial 1\n");
    for(i = 0; i < n1; i++){
        scanf("%d", &poly1[i]);
    }
    
    printf("\nEnter polynomial 2\n");
    for(i = 0; i < n2; i++){
        scanf("%d", &poly2[i]);
    }
    
    int n3 = n1 > n2 ? n1 : n2;
    int poly3[n3];
    
    poly_add_array(poly1, poly2, poly3, n1, n2);
    
    printf("\nPolynomial 3\n");
    for(i = 0; i < n3; i++){
        printf("%d ", poly3[i]);
    }
}


void poly_add_array(int poly1[], int poly2[], int poly3[], int n1, int n2){
    int i = 0, j = 0, k= 0, count;
    if(n1 > n2){
        for(; i < n1-n2; i++,k++){
            poly3[k] = poly1[i];
        }
        for(;i < n1; i++,j++,k++){
            poly3[k] = poly1[i]+ poly2[j];
        }
    }
    else{
        for(; j < n2-n1; j++,k++){
            poly3[k] = poly2[j];
        }
        for(;j < n2; i++,j++,k++){
            poly3[k] = poly1[i]+ poly2[j];
        }
    }
}