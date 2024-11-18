//MAX heap top down
#include <stdio.h>
#define MAX 100

typedef struct heap{
    int info;
    int used;
}HEAP;

HEAP Heap[MAX];
int size = 0;

int insert(int);
void Heapify();
void display();
void HeapInit(){
    Heap[0].info = -1;
    for(int i = 0 ; i < MAX ; i++){
        Heap[i].used = 0;
    }
}

int main(){
    HeapInit();
    int choice,ele;
    while(1){
        printf("1.Insert Element\n2.Display\n3.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element:");
                scanf("%d",&ele);
                insert(ele);
                break;
            case 2:
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Wrong input!!");
        }
    }
}

int insert(int ele){
    if(Heap[1].used == 0){
        Heap[1].info = ele;
        Heap[1].used = 1;
        return size++;
    }
    if(size == MAX-1){
        printf("Heap is full!!\n");
    }
    int i =1;
    while(i<MAX){
        int left = (2*i),right = (2*i)+1;
        if(Heap[left].used == 0 && left <MAX){
            Heap[left].info = ele;
            Heap[left].used = 1;
            size++;
            Heapify();
            return size;
        }
        if(Heap[right].used == 0 && right < MAX){
            Heap[right].info = ele;
            Heap[right].used = 1;
            size++;
            Heapify();
            return size;
        }
        if(Heap[left].used == 1 && Heap[right].used == 1)
            i++;
    }
}

void Heapify(){
    for(int i = size/2;i>=1;i--){
        int left = (2*i),right = ((2*i)+1);
        int greater = -1;
        if(Heap[left].used == 1 && Heap[right].used == 1)
            greater = Heap[left].info>Heap[right].info?left:right;
        else if(Heap[left].used == 1 && Heap[right].used == 0)
            greater = left;
        else if(Heap[left].used == 0 && Heap[right].used == 1)
            greater = right;
        if(Heap[i].info<Heap[greater].info){
            HEAP temp = Heap[greater];
            Heap[greater] = Heap[i];
            Heap[i] = temp;
        }
    }
}

void display(){
    if(size == 0){
        printf("The heap is empty!!\n");
        return;
    }
    for(int i = 1; i <= size; i++) {
        if (Heap[i].used == 1) {
            printf("%d ", Heap[i].info);
        }
    }
    printf("\n");
}