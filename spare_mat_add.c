#include<stdio.h>

typedef struct{
    int row;
    int col;
    int val;
} sparse;

int main() {
    int i, r , c;
    printf("Enter the total numbers of rows and columns: ");
    scanf("%d %d", &r, &c);
    
    
    int n_terms_a;
    printf("Enter the numbers of non-zero vlaues for sparse matrix 1: ");
    scanf("%d", &n_terms_a);
    
    sparse mat_a[n_terms_a+1];
    mat_a[0].row = r;
    mat_a[0].col = c;
    mat_a[0].val = n_terms_a;
    
    printf("Enter the row, col, value: \n");
    
    for(i = 1; i <= n_terms_a; i++){
        scanf("%d %d %d", &mat_a[i].row, &mat_a[i].col, &mat_a[i].val);
    }
    
    int n_terms_b;
    printf("Enter the numbers of non-zero vlaues for sparse matrix 2: ");
    scanf("%d", &n_terms_b);
    
    sparse mat_b[n_terms_b+1];
    mat_b[0].row = r;
    mat_b[0].col = c;
    mat_b[0].val = n_terms_b;
    
    printf("Enter the row, col, value: \n");
    
    for(i = 1; i <= n_terms_b; i++){
        scanf("%d %d %d", &mat_b[i].row, &mat_b[i].col, &mat_b[i].val);
    }
    
    printf("\nSparse Matrix 1: ");
    
    for(i = 0; i <= n_terms_a; i++){
        printf("\n%d %d %d", mat_a[i].row, mat_a[i].col, mat_a[i].val);
    }
    
    printf("\nSparse Matrix 2: ");
    
    for(i = 0; i <= n_terms_b; i++){
        printf("\n%d %d %d", mat_b[i].row, mat_b[i].col, mat_b[i].val);
    }
    
    sparse res[n_terms_a+n_terms_b+1];
    
    res[0].row = r;
    res[0].col = c;
    
    int m = 1, n = 1, o = 1;
    while(m <= n_terms_a && n <= n_terms_b){
        if(mat_a[m].row < mat_b[n].row){
            res[o] = mat_a[m];
            o++;
            m++;
        }
        else if(mat_a[m].row > mat_b[n].row){
            res[o] = mat_b[n];
            o++;
            n++;
        }
        else{
            if(mat_a[m].col < mat_b[n].col){
                res[o] = mat_a[m];
                o++;
                m++;
            }
            else if(mat_a[m].col > mat_b[n].col){
                res[o] = mat_b[n];
                o++;
                n++;
            }
            else{
                res[o].row = mat_a[m].row;
                res[o].col = mat_a[m].col;
                res[o].val = mat_a[m].val + mat_b[n].val;
                o++;
                m++;
                n++;
            }
        }
    }
    while(m <= n_terms_a){
        res[o] = mat_a[m];
        o++;
        m++;
    }
    while(n <= n_terms_b){
        res[o] = mat_a[n];
        o++;
        n++;
    }
    
    res[0].val = o-1;
    
    printf("\nResultant Matrix: ");
    
    for(i = 0; i < o; i++){
        printf("\n%d %d %d", res[i].row, res[i].col, res[i].val);
    }
}
