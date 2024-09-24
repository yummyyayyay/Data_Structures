#include <stdio.h>
#define MAX 5

int FRONT = -1;
int REAR = -1;
int q[MAX];

void Insert(int ele){
    if((REAR+1)%MAX == FRONT) {
        printf("OVERFLOW\n");
        return;
    }
    if(FRONT == -1)
        FRONT = 0;
    REAR = (REAR+1)%MAX;
    q[REAR] = ele;
}

void Delete(){
    if(FRONT == -1 && REAR == -1)
        printf("UNDERFLOW\n");
    else if(FRONT == REAR){
        FRONT = -1;
        REAR = -1;
    }
    else{
        FRONT = (FRONT + 1)%MAX;
    }
}

void Peek(){
    if(FRONT == -1 && REAR == -1){
        printf("The list is empty\n");
    }
    else
        printf("%d\n",q[FRONT]);
}

void Display(){
    if(FRONT == -1 && REAR == -1)
        printf("The list is empty");
    else{
        if(FRONT < REAR){
            for(int i = FRONT ; i<=REAR;i++){
                printf("%d",q[i]);
                if(i != REAR){
                    printf("<-");
                }
            }
            printf("\n");
        }
        else{
            for(int i = FRONT ; i <= MAX-1;i++){
                printf("%d",q[i]);
                printf("<-");
            }
            for(int j = 0 ; j <= REAR; j++){
                printf("%d",q[j]);
                if(j != REAR)
                    printf("<-");
            }
            printf("\n");
        }
    }
}

int main(){
    int choice,ele;
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
                printf("Incorrect input");
        }
    }
}