#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *forwardRef;
	struct node *backwardRef;
} node;

void createList(node **);
void splitList(node **, node **, node **);
void traverse(node **);

int main() {
	node *root, *headA, *headB;
	root = NULL;
	headA = NULL;
	headB = NULL;
	
	createList(&root);
	
	traverse(&root);
	
	splitList(&root, &headA, &headB);
	
	traverse(&headA);
	traverse(&headB);
	
	return 1;
}

void createList(node **root) {
	int val;
	
	node *prev = NULL;
	
	while(1) {
		printf("\nEnter the data: ");
		scanf("%d", &val);
		
		if(val == -1) {
			return ;
		}
		
		node *temp = (node *) malloc(1 * sizeof(node));
		temp->data = val;
		temp->backwardRef = NULL;
		temp->forwardRef = NULL;
		
		if(*root == NULL) {
			*root = temp;
		}
		else {
			prev->forwardRef = temp;
			temp->backwardRef = prev;
		}
		
		prev = temp;
	}
}

void splitList(node **root, node **headA, node **headB) {
	node *temp = *root;
	
	node *tempHeadA = *headA;
	node *tempHeadB = *headB;
	
	while(temp != NULL) {
		if(temp->data % 2 == 0) {
			if (!tempHeadA) {
				*headA = temp;
				tempHeadA = temp;
			}
			else{
				tempHeadA->forwardRef = temp;
				temp->backwardRef = tempHeadA;
				tempHeadA = temp;	
			}
		}
		else {
			if (!tempHeadB) {
				*headB = temp;
				tempHeadB = temp;
			}
			else {
				tempHeadB->forwardRef = temp;
				temp->backwardRef = tempHeadB;
				tempHeadB = temp;
			}
		}
		temp = temp->forwardRef;
	}
	(*headA)->backwardRef = NULL;
	(*headB)->backwardRef = NULL;
	tempHeadA->forwardRef = NULL;
	tempHeadB->forwardRef = NULL;
	
	return ;
}

void traverse(node **root) {
	node *current = *root;
	
	while(current != NULL) {
		printf("%d", current->data);
		current = current->forwardRef;
	}
	printf("\n");
	
	return ;
}
