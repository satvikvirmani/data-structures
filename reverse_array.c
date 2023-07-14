#include <stdio.h>

//Swap function declaration
void swap(int*, int*);

int main() {
    int n_terms;
    printf("Enter the number of terms: ");
    scanf("%d", &n_terms);
    
    int arr[n_terms];
    
    printf("Enter the values: \n");
    int i;
    for(i = 0; i < n_terms; i++){
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < n_terms/2; i++){
        swap(&arr[i], &arr[n_terms - i - 1]);
    }
    
    for(i = 0; i < n_terms; i++){
        printf("%d", arr[i]);
    }
    
    return 0;
}

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
