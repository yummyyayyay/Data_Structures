#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    struct stack* next;
    int data;
}STACK;

STACK* top = NULL;
STACK* push(STACK*,int );
STACK* pop(STACK*);
int peek(STACK*);
void display(STACK*);

int main(){
    int choice,ele,val;
    do{
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed:");
                scanf("%d",&ele);
                top = push(top,ele);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if(val == -1)
                    printf("The list is empty");
                else{
                    printf("The top element is %d",val);
                }
                break;
            case 4:
                display(top);
                break;
            case 5:
                return 0;
            default:
                printf("Wrong option\n");
        }
    }while(choice != 5);
}


#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
STACK* push(STACK* head,int ele){
    STACK* temp = malloc(sizeof(STACK));
    temp->data = ele;
    temp->next = NULL;
    if(top == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}
#pragma clang diagnostic pop


STACK* pop(STACK* head){
    if(head == NULL){
        printf("STACK UNDERFLOW\n");
    }
    else{
        STACK* q = head;
        head = head->next;
        free(q);
    }
    return head;
}

int peek(STACK* head){
    if(head == NULL)
        return -1;
    else
        return(top->data);
}

void display(STACK* head){
    if(head == NULL){
        printf("The list is empty\n");
    }
    else{
        while(head != NULL){
            printf("%d",head->data);
            if(head->next != NULL)
                printf("->");
            head = head->next;
        }
    }
}