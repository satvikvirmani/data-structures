#include <stdio.h>

#define MAX 100
#define ERROR -9999

int push(int);
int pop();
int peek();

int stack[MAX];
int top = -1;

//Function declaration
int convert(int, int[]);

int main(){

    int num = 27;
    int binary[64];

    int n_bits = convert(num, binary);

    int i;
    for(i = 0; i <= n_bits; i++){
        printf("%d ", binary[i]);
    }

    return 0;
}

int push(int val){
    if(top < MAX-1){
        stack[++top] = val;
        return 1; //Operation Successfull
    }
    
    return 0; //Operation Unsuccessfull
}

int pop(){
    if(top > -1){
        return stack[top--]; //Operation Successfull
    }
    
    return ERROR; //Operation Unsuccessfull
}

int peek(){
    if(top > -1){
        return stack[top]; //Operation Successfull
    }
    
    return ERROR; //Operation Unsuccessfull
}

int convert(int num, int binary[]){
    while(num != 0){
        push(num%2);
        num /= 2;
    }
    
    int i = -1;
    while(peek() != ERROR){
        binary[++i] = pop();
    }

    return i;
}