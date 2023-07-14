#include <stdio.h>

#define MAX 100
#define ERROR '.'

char stack[MAX];
int top = -1;

int push(char);
char pop();
char peek();
int isFull();
int isEmpty();
void display();
int isDup(char[], int);

int main(){
	
	char expression[] = "(((x+y)))";
	
	int length = sizeof expression / sizeof expression[0];
	
	printf("%d", isDup(expression, length));
}

int isDup(char expression[], int length){
	int i = 0;
	while(i < length-1){
		if(expression[i] != ')'){
			push(expression[i]);
		}
		else{
			if (peek() == '('){
				return 1;
			}
			while(peek() != '('){
				pop();
			}
			pop();
		}
		i++;
	}
	return 0;
}

int push(char ch){
	if(top < MAX-1){
		stack[++top] = ch;
		return 1;
	}
	return 0;
}

char pop(){
	if(top > -1){
		return stack[top--];
	}
	return ERROR;
}

char peek(){
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
	while(!isEmpty()){
		printf("%d ", pop());
	}
	return ;
}
