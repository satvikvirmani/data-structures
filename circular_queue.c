#include <stdio.h>

#define MAX 6
#define QUEUE_FULL_ERROR -9999
#define QUEUE_EMPTY_ERROR -9998

int queue[MAX];
int front = -1, rear = -1;

//Queue functions
int insertQ(int);
int delQ();
int displayQ();
int isQfull();
int isQempty();

int main() {
    printf("Enter 1 to insert into queue.");
    printf("\nEnter 2 to delete from queue.");
    printf("\nEnter 3 to display the queue.");
    printf("\nEnter 4 to exit.");
    
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
        printf("\nFull\n");
        return QUEUE_FULL_ERROR;
    }
    rear = (rear+1)%MAX;
    queue[rear] = val;
}

int delQ(){
    if(isQempty()){
        return QUEUE_EMPTY_ERROR;
    }
    front = (front+1)%MAX;
    int temp = queue[front];
    queue[front] = -999; //Reset the queue
    return temp;
}

int displayQ(){
    printf("\nQueue:\n");
    int i = 0;
        while(i < MAX){
            printf("%d-%d\n",i, queue[i++]);
        }
    
    return 1;
}

int isQfull(){
    if(front - rear == 1 || front + rear == MAX-2){
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
