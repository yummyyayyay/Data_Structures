#include <stdio.h>
#define MAX 30

int TOP=-1;

int push(int* ,int );
int pop(const int* );
void peek(int* );
void display(int* );
int empty(int* );

int main(){
    int stack[MAX];
    int choice,ele;
    do{
        printf("1.InsertElement\n2.DeleteElement\n3.Peek\n4.Display\n5.Empty\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element:");
                scanf("%d",&ele);
                TOP = push(stack,ele);
                break;
            case 2:
                TOP = pop(stack);
                break;
            case 3:
                peek(stack);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                TOP = empty(stack);
                break;
            case 6:
                return 0;
            default:
                printf("Error\n");
        }
    }while(choice<=6);
}

int push(int* arr,int ele){
    if(TOP == MAX-1)
        printf("Overflow\n");
    else{
        TOP++;
        arr[TOP] = ele;
    }
    return TOP;
}

int pop(const int* arr){
    int val;
    if(TOP == -1)
        printf("Underflow\n");
    else{
        val = arr[TOP];
        TOP--;
        printf("%d has been deleted\n",val);
    }
    return TOP;
}

void peek(int* arr){
    if(TOP == -1)
        printf("The list is empty\n");
    else
        printf("The topmost value is %d\n",arr[TOP]);
}

void display(int*arr){
    if(TOP == -1){
        printf("The list is empty\n");
    }
    else{
        for(int i = 0 ; i<=TOP;i++){
            printf("%d",arr[i]);
            if(i != TOP)
                printf("->");
        }
        printf("\n");
    }

}

int empty(int* arr){
    if(TOP == -1){
        printf("The list is already empty\n");
    }
    else{
        TOP = -1;
    }
    return TOP;
}