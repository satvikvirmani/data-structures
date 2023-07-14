#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} node;

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
		temp->next = NULL;
		
		if(*root == NULL) {
			*root = temp;
		}
		else {
			prev->next = temp;
		}
		
		prev = temp;
	}
}

void traverse(node **root) {
	node *current = *root;
	
	while(current != NULL) {
		printf("%d", current->data);
		current = current->next;
	}
	
	return ;
}

node *reversal(node *curr, node **root) {
	if(curr->next == NULL) {
	    *root = curr;
		return curr;
	}
	node *temp = reversal(curr->next, &(*root));
	temp->next = curr;
	curr->next = NULL;
	return curr;
}

node *reversalBtwNodes(node *start, node *end) {
	if(start == end) {
		return start;
	}
	node *temp = reversalBtwNodes(start->next, end);
	temp->next = start;
	start->next = NULL;
	return start;
}

node *reverseKGroups(node *root, int k) {
    if(root == NULL || root->next == NULL || k == 1) {
        return root;
    }
    node *start, *end;
    
    start = root;
    end = root;
    
    int i = 1;
    while(i < k) {
        end = end->next;
        i++;
        if(end == NULL) {
            return root;
        }
    }
    
    node *temp;
    temp = reverseKGroups(end->next, k);
    
    reversalBtwNodes(start, end);
    
    start->next = temp;
    return end;
}

int main()
{
	node *root;
	root = NULL;
	
	createList(&root);

	node *x = reverseKGroups(root, 2);
	
	traverse(&x);
}
