
/*
	Design Develop and implement a program in c
	for the following operation on queue of integer,
	with maximum size MAX,
	a. inset an element to queue
	b. delete an element to queue
	c. display the element of queue
	d. demonstrate the underflow and overflow situation on queue
	e. exit
	
	support the program with apporiparate function
	with each of the above operation	
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int Queue[MAX];
int PriorityQueue[MAX];
int front=-1, rear=-1;

void enqueue(int data) {
    if(is_full()) {
        printf("Queue is Full.\n");
    } else {
        if(front == -1) {
            front = 0;
        }
        Queue[++rear] = data;
        printf("Data inserted Successfully.\n");
    }
}

void dequeue() {
    if(is_empty()) {
        printf("Queue is Empty.\n");
    } else {
        printf("%d : Data Deleted Successfully.\n", Queue[front]);
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            ++front;
        }
    }
}

void display() {
    int i;
    if(is_empty()) {
        printf("Queue is Empty.\n");
        return;
    }
    for(i = front; i <= rear; i++) {
        printf("%d | ", Queue[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void priority(int order) {
    int size = rear - front + 1;
    int i, j;
    
    for(i = 0; i < size; i++) {
        PriorityQueue[i] = Queue[front + i];
    }
    
    printf("\nCurrent Queue is :");
    for(i = 0; i < size; i++) {
        printf("%d | ", PriorityQueue[i]);
    }
    printf("\n");
    
    if(order == 1) {
        // Ascending order
        for(i = 0; i < size-1; i++) {
            for(j = 0; j < size-i-1; j++) {
                if(PriorityQueue[j] > PriorityQueue[j+1]) {
                    swap(&PriorityQueue[j], &PriorityQueue[j+1]);
                }
            }
        }
    } else if(order == 2) {
        // Descending order
        for(i = 0; i < size-1; i++) {
            for(j = 0; j < size-i-1; j++) {
                if(PriorityQueue[j] < PriorityQueue[j+1]) {
                    swap(&PriorityQueue[j], &PriorityQueue[j+1]);
                }
            }
        }
    }
    
    printf("\nPriority Queue is :");
    for(i = 0; i < size; i++) {
        printf("%d | ", PriorityQueue[i]);
    }
    printf("\n");
}

int is_full() {
    if(rear == MAX-1) {
        return 1;
    }
    return 0;
}

int is_empty() {
    if(front == -1) {
        return 1;
    }
    return 0;
}

void menu() {
    int option, data;
    int order;
    do {
        printf("\n------MENU-------\n");
        printf("\n\t 1.Insert");
        printf("\n\t 2.Delete");
        printf("\n\t 3.Display");
        printf("\n\t 4.Is_Empty");
        printf("\n\t 5.Is_Full");
        printf("\n\t 6.Show Priority");
        printf("\n\t 7.Exit");
        
        printf("\n Enter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\n Enter your data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if(is_empty()) {
                    printf("\n Yes, Queue is Empty (UNDERFLOW).\n");
                } else {
                    printf("\n NO, Queue is not Empty.\n");
                }
                break;
            case 5:
                if(is_full()) {
                    printf("\n Yes, Queue is Full (OVERFLOW).\n");
                } else {
                    printf("\n NO, Queue is not Full.\n");
                }
                break;
            case 6:
                printf("Choose your order: \n \t 1.ASC\n \t 2.DESC\n");
                printf("Enter your order: ");
                scanf("%d", &order);
                
                priority(order);
                break;
            case 7:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("Invalid Option, Please choose the correct one.");
                break;
        }
    } while(option != 7);
}

int main() {
    printf("Priority Queue Program...");
    menu();
    return 0;
}
