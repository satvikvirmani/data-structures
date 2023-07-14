#include <stdio.h>

#define MAX 100
#define ERROR -9999

int stack[MAX];
int top = -1;

int push(int);
int pop();
int peek();
int isFull();
int isEmpty();
void display();
void insert();
void sort();

int main(){
	push(5);
	push(-2);
	push(9);
	push(-7);
	push(3);
	
	display();
	sort();
	display();
}

void insert(int currentEl){
	if(isEmpty() || currentEl >= peek()){
		push(currentEl);
		return ;
	}
	int tempEl = pop();
	insert(currentEl);
	push(tempEl);
}

void sort(){
	if(isEmpty()){
		return ;
	}
	int x = pop();
	sort();
	insert(x);
}

int push(int val){
	if(top < MAX-1){
		stack[++top] = val;
		return 1;
	}
	return 0;
}

int pop(){
	if(top > -1){
		return stack[top--];
	}
	return ERROR;
}

int peek(){
	if(top > -1){
		return stack[top];
	}
	return ERROR;
}

int isFull(){
	if(top == MAX-1){
		return 1;
	}
	return 0;
}

int isEmpty(){
	if(top == -1){
		return 1;
	}
	return 0;
}

void display(){
	printf("\n");
	int i = 0;
	while(i <= top){
		printf("%d ", stack[i]);
		i++;
	}
	return ;
}
