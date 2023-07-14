#include <stdio.h>

#define MAX 100
#define QUEUE_FULL_ERROR -9999
#define QUEUE_EMPTY_ERROR -9998

int queue[MAX];
int front = -1, rear = -1;

//Queue functions
int insertQ(int);
int delQ();
int displayQ();
int compactionQ();
int isQfull();
int isQempty();

//Utility functions
void swap(int*, int*);

int main() {
    printf("Enter 1 to insert into queue.");
    printf("\nEnter 2 to delete from queue.");
    printf("\nEnter 3 to display the queue.");
    printf("\nEnter 4 to perform compaction in queue.");
    printf("\nEnter 5 to exit.");
    
    int choice;
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int val;
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &val);
                insertQ(val);
                break;
            case 2:
                delQ();
                break;
            case 3:
                displayQ();
                break;
            case 4:
                compactionQ();
                break;
            case 5:
                break;
            default:
                printf("\nInvalid choice.");
                break;
        }
    } while(choice != 5);
    
    return 0;
}

int insertQ(int val){
    if(isQfull()){
        return QUEUE_FULL_ERROR;
    }
    queue[++rear] = val;
}

int delQ(){
    if(isQempty()){
        return QUEUE_EMPTY_ERROR;
    }
    return queue[++front];
}

int displayQ(){
    printf("\nQueue: ");
    int i = front;
    while(i < rear){
        printf("%d ", queue[++i]);
    }
    
    return 1;
}

int compactionQ(){
    int i = front+1, j = 0;
    while(i <= rear){
        swap(&queue[j++], &queue[i++]);
    }
    
    front = -1;
    rear = j-1;
    
    return 1;
}

int isQfull(){
    if(rear == MAX-1){
        return 1;
    }
    
    return 0;
}

int isQempty(){
    if(front == rear){
        return 1;
    }
    
    return 0;
}

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    
    return ;
}
