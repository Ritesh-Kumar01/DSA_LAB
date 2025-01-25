#include<stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty(){
	if(top == -1){
		return 1;
	}
	return 0;
}

int isFull(){
	if(top == (MAX - 1)){
		return 1;
	}
	return 0;
}

void push(){
	if(isFull()){
		printf("STACK OVERFLOW : Stack is Full.\n");
	}else{
		int data;
		printf("Enter the data to insert : ");
		scanf("%d",&data);
		stack[++top] = data;
	}
}

void pop(){
	if(isEmpty()){
		printf("STACK UNDERFLOW : Stack is Empty.\n");
	}else{
		printf("Data Deleted Successfully.\n");
		stack[top] = 0;
		top--;
		
	}
}

void peek(){
	if(isEmpty()){
		printf("STACK UNDERFLOW : Stack is Empty.\n");
	}else{
		printf("Top Element : %d\n",stack[top]);
	}
}


void display(){
	int i;
	if(isEmpty()){
		printf("Nothing to show Stack is Empty.");
	}else{
		for(i=MAX-1;i>-1;i--){
			printf("%d\n",stack[i]);
		}
	}
}

int palindrome(int stack[]){
	int i,j;
	for(i=0,j=top;i<top,j>0;i++,j--){

			if(stack[i] != stack[j]){
				
				return 0;
			}
		
	}
	
	return 1;
}


void menu(){
	int option;
	do{
		printf("Menu: \n");
		printf("\t 1.Push \n");
		printf("\t 2.Pop \n");
		printf("\t 3.peek \n");
		printf("\t 4.Display \n");
		printf("\t 5.isEmpty \n");
		printf("\t 6.isFull \n");
		printf("\t 7.Check palindrome \n\n");
		printf("\t 8.Exit the program\n\n");
		
		printf("Enter your choice : ");
		scanf("%d",&option);
		
		switch(option){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				if(isEmpty()){
					printf("YES, Stack is Empty.\n");
					printf("STACK UNDERFLOW HIT.\n");
				}else{
					printf("NO, Stack is not Empty\n");
				}
				break;
			case 6:
				if(isFull()){
					printf("YES, Stack is Full.\n");
					printf("STACK OVERFLOW HIT.\n");
				}else{
					printf("NO, Stack is not Full.\n");
				}
				break;
			case 7:
				if(palindrome(stack)){
					printf("it is a palindrome.");
				}else{
					printf("Not a palindrome.");
				}				
				break;
			case 8:
				printf("------------- Exiting... ------------\n");
				return;
				break;
			default:
				printf("Invalid Option.\n");
				break;
		}
	}while(option != 7);
}


int main(){
	printf("--------------------Stack Operation -------------\n\n");
	menu();
	return 0;
}