


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

#define MAX 5

int Queue[MAX];
int front = -1, rear = -1;

int is_full() {
    if ((rear + 1) % MAX == front) {
        return 1;
    }
    return 0;
}

int is_empty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int data) {
    if (is_full()) {
        printf("Queue is Full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        Queue[rear] = data;
        printf("Data inserted Successfully.\n");
    }
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is Empty.\n");
    } else {
        printf("%d : Data Deleted Successfully.\n", Queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void printQueue(){
	int i;
	if (is_empty()) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("\n just printing the Queue : \n");
    
    for(i=0;i<MAX;i++){
    	printf(" %d |",Queue[i]);
	}
	printf("\n");
}

void display() {
    if (is_empty()) {
        printf("Queue is Empty.\n");
        return;
    }

    int i = front;
    while (i != rear) {
        printf("%d | ", Queue[i]);
        i = (i + 1) % MAX;
    }
    
    printf("%d | ", Queue[i]); 
    printf("\n");
}

void menu() {
    int option, data;
    do {
        printf("\n------MENU-------\n");
        printf("\n\t 1.Insert");
        printf("\n\t 2.Delete");
        printf("\n\t 3.Display");
        printf("\n\t 4.Is_Empty");
        printf("\n\t 5.Is_Full");
        printf("\n\t 6.Exit");

        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("\n Enter your data : ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            printQueue();
            break;
        case 4:
            if (is_empty()) {
                printf("\n Yes, Queue is Empty (UNDERFLOW).\n");
            } else {
                printf("\n NO, Queue is not Empty .\n");
            }
            break;
        case 5:
            if (is_full()) {
                printf("\n Yes, Queue is Full (OVERFLOW).\n");
            } else {
                printf("\n NO, Queue is not Full.\n");
            }
            break;
        case 6:
            printf("Exiting...");
            exit(0);
            break;
        default:
            printf("Invalid Option, Please choose correct one.");
            break;
        }
    } while (option != 6);
}

int main() {
    printf("Circular Queue Program...");
    menu();
    return 0;
}