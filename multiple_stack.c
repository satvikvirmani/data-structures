#include <stdio.h>
#include <math.h>

#define MAX 100
#define ERROR -9999
#define N_STACKS 5

int push(int,int);
int pop(int);
int peek(int);

int stack[MAX];
int top[N_STACKS];

int size = MAX/N_STACKS;

int main() {
    init();
    
    push(0, 2);
    push(1, 3);
    push(2, 1);
    push(1, 2);
    push(3, 9);
    push(2, 7);
    push(4, 3);
    push(4, 1);
    push(1, 5);
    push(2, 4);
    push(0, 2);
    push(0, 3);
    push(1, 7);
    push(3, 9);
    
    display();
    return 0;
}

void display(){
    int i;
    printf("\n");
    for(i = 0; i< MAX; i++){
        if(i%size == 0){
            printf("\nStack %d\n", i/size);
        }
        printf("%d ", stack[i]);
    }
}

void init(){
    int i;
    for(i = 0; i < N_STACKS; i++){
        top[i] = i*(size)-1;
    }
}

int push(int n,int val){
    if(top[n] < (((n+1) * size) - 1)){
        stack[++top[n]] = val;
        return 1; //Operation Successfull
    }
    
    return 0; //Operation Unsuccessfull
}

int pop(int n){
    if(top[n] > ((n*size) - 1)){
        return stack[top[n]--]; //Operation Successfull
    }
    
    return ERROR; //Operation Unsuccessfull
}

int peek(int n){
    if(top[n] > ((n*size) - 1)){
        return stack[top[n]--]; //Operation Successfull
    }
    
    return ERROR; //Operation Unsuccessfull
}
