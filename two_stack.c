#include <stdio.h>
#include <math.h>

#define MAX 100
#define ERROR -9999
#define INVALID_STACK_ERROR -9998

int push(int,int);
int pop(int);

int stack[MAX];
int top_front = -1;
int top_rear = MAX;

int main() {
    
    push(0, 2);
    push(1, 3);
    push(1, 4);
    push(1, 6);
    push(0, 1);
    
    display();
    return 0;
}

void display(){
    int i;
    printf("\nStack\n");
    for(i = 0; i< MAX; i++){
        printf("%d ", stack[i]);
    }
}

int push(int n,int val){
    //n = 0 means stack at begining
    //n = 1 means stack at end
    if(n == 0){
        if(top_front < top_rear-1){
            stack[++top_front] = val;
            return 1; //Operation Successfull
        }
    }
    else if(n == 1){
        if(top_front < top_rear-1){
            stack[--top_rear] = val;
            return 1; //Operation Successfull
        }
    }else{
        return INVALID_STACK_ERROR; //Invalid stack id
    }
    
    return 0; //Operation Unsuccessfull
}

int pop(int n){
    //n = 0 means stack at begining
    //n = 1 means stack at end
    if(n == 0){
        if(top_front > -1){
            return stack[top_front--]; //Operation Successfull
        }
    }
    else if(n == 1){
        if(top_front < MAX){
            return stack[top_rear++]; //Operation Successfull
        }
    }else{
        return INVALID_STACK_ERROR; //Invalid stack id
    }
    
    return ERROR; //Operation Unsuccessfull
}
