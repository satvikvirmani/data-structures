#include <stdio.h>

int main(){
    char str[] = "Andriod is a flavour of Linux";

    int length = sizeof str / sizeof str[0];

    int breaks[length];

    breaks[0] = 0;

    int i = 0, j = 0;
    while(i < length){
        if(str[i] == ' '){
            breaks[++j] = i+1;
        }
        i++;
    }
    breaks[++j] = length;
    
    while(j > -1){
        for(i = breaks[j-1]; i < breaks[j]; i++){
            printf("%c", str[i]);
        }
        printf(" ");
        j--;
    }

    return 0;
}