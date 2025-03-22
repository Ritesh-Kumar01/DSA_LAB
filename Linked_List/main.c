#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_at_beginning(struct Node **head, int data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insert_at_end(struct Node **head, int data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void insert_at_position(struct Node **head, int data, int position) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    if (position == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Node *current = *head;
    int i;
    for (i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range.\n");
        free(temp);
    } else {
        temp->next = current->next;
        current->next = temp;
    }
}

void delete_from_beginning(struct Node **head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_from_end(struct Node **head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *current = *head, *prev = NULL;

    if (current->next == NULL) {
        *head = NULL;
        free(current);
        return;
    }

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

void delete_at_position(struct Node **head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    int i;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void delete_using_value(struct Node *head,int item){
	struct Node *temp = head;
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else{
    	while (temp != NULL) {
    		if(temp->next->next != NULL){
    			if(temp->data == item){
            	
				}
			}
            
            temp = temp->next;
        }
        printf("NULL\n");
	}
}

void display_from_beginning(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void search(struct Node *head, int item) {
    struct Node *temp = head;
    int found = 0; 
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    while (temp != NULL) {
        if (temp->data == item) {
            printf("%d item found in linked list\n", item);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("%d item not found in linked list\n", item);
    }
}

int searchValue(struct Node * head, int value) {
    struct Node * temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0;
}

void sortLinkedList(struct Node * head) {
    if (head == NULL || head->next == NULL) {
        printf("Linked is empty.");
    }
    struct Node * i = head;
    struct Node * j = NULL;

    for (; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    
    display_from_beginning(head);
}


void reverseLinkedList(struct Node * head) {
    struct Node * prev = NULL;
    struct Node * current = head;
    struct Node * next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    display_from_beginning(prev);
}

int main() {
    struct Node *head = NULL;
    int option, data, position;

    do {
        printf("\n\n ----Menu----");
        printf("\n \t 1. Insertion at beginning");
        printf("\n \t 2. Insertion at end");
        printf("\n \t 3. Insertion at position");
        printf("\n \t 4. Deletion from beginning");
        printf("\n \t 5. Deletion from end");
        printf("\n \t 6. Deletion from any position");
        printf("\n \t 7. Deletion using value");
        printf("\n \t 8. Display from beginning");
        printf("\n \t 9. Display from end");        
        printf("\n \t 10. Searching a value in linked list");        
        printf("\n \t 11. Reverse the Linked List");
        printf("\n \t 12. Sort the linked list in asc order");
        printf("\n \t 13. Exit the program");
        printf("\n\n");

        printf("Enter your Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insert_at_position(&head, data, position);
                break;
            case 4:
                delete_from_beginning(&head);
                break;
            case 5:
                delete_from_end(&head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                break;
            case 8:
                display_from_beginning(head);
                break;
            case 9:
                display_from_beginning(head);
                break;
            case 10:            	
                printf("Enter the data: ");
                scanf("%d", &data);
                if(searchValue(&head, data)){
                	printf("Data found successfully\n");
        				}else{
        					printf("Data not found.");
        				}
                break;
            case 11:     
			          reverseLinkedList(head);
                break;                
            case 12:            	
            	sortLinkedList(head);
                break;
            case 13:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Enter the correct Option.\n");
                break;
        }
    } while (option != 13);

    return 0;
}
