#include <stdio.h>
#define MAX 30
int FRONT = -1,REAR = -1;
int queue[MAX];

void Insert(int ele){
    if(REAR == MAX-1){
        printf("OVERFLOW\n");
    }
    else{
        if(REAR == -1)
            FRONT = 0;
        REAR++;
        queue[REAR] = ele;
    }
}

void Delete(){
    if(FRONT == -1 && REAR == -1)
        printf("UNDERFLOW\n");
    else{
        FRONT++;
    }
}

void Peek(){
    if(FRONT == -1 && REAR == -1)
        printf("The list is empty\n");
    else
        printf("%d\n",queue[FRONT]);
}

void Display(){
    if(REAR == -1 && FRONT == -1)
        printf("List is empty\n");
    else{
        for(int i = FRONT ; i <= REAR;i++){
            printf("%d",queue[i]);
            if(i != REAR)
                printf("->");
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