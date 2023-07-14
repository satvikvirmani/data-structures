#include <stdio.h>

int main() {
    int n_rows, n_cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n_rows, &n_cols);
    
    int arr[n_rows + 1][n_cols + 1];
    
    printf("Enter the values: \n");
    int i, j;
    for(i = 0; i < n_rows; i++){
        for(j = 0; j < n_cols; j++){
            printf("Enter value of %d row and %d column: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    
    //Maximum in rows
    int max;
    for(i = 0; i < n_rows; i++){
        max = arr[i][0];
        for(j = 1; j < n_cols; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
        arr[i][j] = max;
    }
    
    //Minimum in cols
    int min;
    for(i = 0; i < n_cols; i++){
        min = arr[0][i];
        for(j = 1; j < n_rows; j++){
            if(arr[j][i] < min){
                min = arr[j][i];
            }
        }
        arr[j][i] = min;
    }
    
    //Printing the matrix
    printf("\nMatrix :\n");
    for(i = 0; i < n_rows+1; i++){
        for(j = 0; j < n_cols+1; j++){
            if(j == n_cols && i == n_rows){
                printf(" ");    
            }
            else{
                printf("%d\t", arr[i][j]);   
            }
        }
        printf("\n");
    }
    return 0;
}
