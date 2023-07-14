#include<stdio.h>

typedef struct{
    int row;
    int col;
    int val;
} matrix;

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

int main() {
    int i;

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
}