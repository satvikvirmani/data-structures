#include<stdio.h>

typedef struct{
    int row;
    int col;
    int val;
} matrix;

typedef struct{
    int coeficient;
    int exponent;
} polyterm;

void quick_sort(int arr[], int start, int end){
    if (start < end){
        int pivot = start;
        int i = start;
        int j = end + 1;
        int temp;
        do{
            do{
                i++;
            } while(arr[i] <= arr[pivot] && i <= end);
            do{
                j--;
            } while(arr[j] > arr[pivot]);
            if(i < j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } while(i < j);
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        
        quick_sort(arr, start, j-1);
        quick_sort(arr, j+1, end);   
    }
}

void merge(int arr[], int start, int mid, int end){
    int i = start;
    int j = mid;
    int k = 0;
    
    int temp[100];
    
    while(i < mid && j < end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i < mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j < end){
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    int m;
    for(m = 0; m < end-start; m++){
        arr[start + m] = temp[m];
    }
}

void merge_sort(int arr[], int start, int end){
    if(start < end-1){
        int mid = (start+end)/2;
        
        merge_sort(arr, start, mid);
        merge_sort(arr, mid, end);
        merge(arr, start, mid, end);
    }
}

void selection_sort(int arr[], int n){
    int i, j, min_index, temp;
    for(i = 0; i < n; i++){
        min_index = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;    
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int n){
    int i, key, com_index;
    for(i = 1; i < n; i++){
        key = arr[i];
        com_index = i;
        while(arr[com_index-1] > key && com_index > 0){
            arr[com_index] = arr[com_index-1];
            com_index--;
        }
        arr[com_index] = key;
    }
}

int binary_min(int arr[], int start, int end, int val){
    if(start < end){
        int mid = (start+end)/2;
        if(arr[mid] <= val){
            if(arr[mid+1] >= val){
                return mid+1;
            }
            else{
                return binary_min(arr, mid, end, val);
            }
        }
        else{
            return binary_min(arr, start, mid, val);
        }
    }
    return start;
}

void insertion_sort_with_binary(int arr[], int n){
    int i, j, key, to_put;
    for(i = 1; i < n; i++){
        to_put = binary_min(arr, 0, i, arr[i]);
        j = i;
        key = arr[j];
        while(j != to_put){
            arr[j] = arr[j-1];
            j--;
        }
        arr[to_put] = key;
    }
}

void transpose_slow(matrix mat[], matrix trans[]){
    trans[0].row = mat[0].col;
    trans[0].col = mat[0].row;
    trans[0].val = mat[0].val;
    int i, j, k=1;
    for(i = 0; i < mat[0].col; i++){
        for(j = 1; j <= trans[0].val; j++){
            if(i == mat[j].col){
                trans[k].row = mat[j].col;
                trans[k].col = mat[j].row;
                trans[k].val = mat[j].val;
                k++;
            }
        }
    }
}

void transpose_fast(matrix mat[], matrix trans[]){
    trans[0].row = mat[0].col;
    trans[0].col = mat[0].row;
    trans[0].val = mat[0].val;
    
    int rowTerms[mat[0].col];
    int startPos[mat[0].col];
    
    int i;
    for(i = 0; i < mat[0].col; i++){
        rowTerms[i] = 0;
    }
    for(i = 1; i <= mat[0].val; i++){
        rowTerms[mat[i].col]++;
    }
    startPos[0] = 1;
    for(i = 1; i < mat[0].col; i++){
        startPos[i] = startPos[i-1] + rowTerms[i-1];
    }
    for(i = 1; i <= mat[0].val; i++){
        trans[startPos[mat[i].col]].row = mat[i].col;
        trans[startPos[mat[i].col]].col = mat[i].row;
        trans[startPos[mat[i].col]].val = mat[i].val;
        startPos[mat[i].col]++;
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

int main() {
    int i;
    
    int arr[] = {7,15,2,1,13,20,25};
    
    printf("\nUnsorted Array\n");
    for(i = 0; i < 7; i++){
        printf("%d ", arr[i]);
    }
    
    insertion_sort_with_binary(arr, 7);
    
    printf("\nSorted Array\n");
    for(i = 0; i < 7; i++){
        printf("%d ", arr[i]);
    }
    
    matrix mat[] = {
        {4, 5, 6},
        {0, 1, 2},
        {1, 1, 3},
        {1, 4, 7},
        {2, 0, 8},
        {2, 2, 9},
        {3, 1, 5}
    };
    matrix transpose[7];
    
    printf("\nSparse Matrix\n");
    for(i = 0; i < 7; i++){
        printf("%d\t%d\t%d\n", mat[i].row, mat[i].col, mat[i].val);
    }
    
    transpose_fast(mat, transpose);
    
    printf("\nTranpose Matrix\n");
    for(i = 0; i < 7; i++){
        printf("%d\t%d\t%d\n", transpose[i].row, transpose[i].col, transpose[i].val);
    }
    
    int n1 = 5;
    int n2 = 7;
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
    
    int n1 = 6;
    int n2 = 9;
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
