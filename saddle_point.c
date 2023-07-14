#include <stdio.h>

int main(){
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    int i, j, k, min, max, saddle;
    int minLoc[2]= {-1, -1};
    for (i = 0; i < 3; i++)
    {
        min = matrix[i][0];

        minLoc[0]= i;
        minLoc[1]= 0;

        saddle = 1;

        for (j = 1; j < 3; j++)
        {
            if(matrix[i][j] < min){
                min = matrix[i][j];
                minLoc[0] = i;
                minLoc[1] = j;
            }
        }

        max = matrix[minLoc[0]][minLoc[1]];

        for(k = 0; k < 3; k++){
            if(matrix[k][minLoc[1]] > max){
                saddle = 0;
                minLoc[0] = -1;
                minLoc[1] = -1;
            }
        }
    }

    if(saddle){
        printf("Location of saddle point is row %d & column %d i.e %d", minLoc[0], minLoc[1], matrix[minLoc[0]][minLoc[1]]);
    }
    else{
        printf("Saddle point does not exist");
    }

    return 0;
}