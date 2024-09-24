#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int ele;
    struct node* next;
}NODE;

NODE* FRONT = NULL;
NODE* REAR = NULL;

void Insert(int);
void Delete();
void Peek();
void Display();

int main(){
    int ele,choice;
    while(1){
        printf("1.Insert Element\n2.Delete Element\n3.Peek\n4.Display\n5.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element:");
                scanf("%d",&ele);
                Insert(ele);
                break;
            case 2:
                Delete();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
                break;
            case 5:
                return 0;
            default:
                printf("Incorrect Input!");
        }
    }
}

void Insert(int ele){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->ele = ele;
    temp->next = NULL;
    if(FRONT == NULL && REAR == NULL){
        FRONT = temp;
        REAR = temp;
    }
    else{
        REAR->next = temp;
        REAR = temp;
    }
}

void Delete(){
    if(FRONT == NULL && REAR == NULL )
        printf("The queue is empty\n");
    else{NODE* temp = FRONT;
        FRONT = FRONT->next;
        free(temp);
    }
}

void Peek(){
    if(FRONT == NULL && REAR == NULL)
        printf("The queue is empty\n");
    else
        printf("%d\n",FRONT->ele);
}

void Display(){
    if(FRONT == NULL && REAR == NULL)
        printf("The list is empty");
    else{
        NODE* q = FRONT;
        while(q != NULL){
            printf("%d",q->ele);
            q = q->next;
            if(q != NULL)
                printf("<-");
        }
        printf("\n");
    }
}