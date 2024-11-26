//bottom up MAX heap
//here elements are inserted first and then the heapify function is applied after insertions
#include <stdio.h>
#define MAX 100

typedef struct heap{
    int ele;
    int occupied;
}HEAP;

HEAP Heap[MAX];
int size = 0;

void heapInit(){
    Heap[0].ele = -1;
    for(int i = 0; i < MAX; i++){
        Heap[i].occupied = 0;
    }
}

int insert(int);
void Heapify(HEAP*,int);
void display();
void buildMaxHeap();

int main(){
    int choice,ele;
    heapInit();
    while(1){
        printf("1.Enter element\n2.Print elements\n3.exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element:");
                scanf("%d",&ele);
                size = insert(ele);
                break;
            case 2:
                buildMaxHeap();
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Wrong input\n");
                break;
        }
    }
}

int insert(int val){
    if(Heap[1].occupied == 0){
        Heap[1].ele = val;
        Heap[1].occupied = 1;
        size++;
        return size;
    }
    int i = 1;
    while(i < MAX) {
        int left = (2*i), right = ((2*i)+1);
        if(Heap[left].occupied == 0 && left < MAX){
            Heap[left].ele = val;
            Heap[left].occupied = 1;
            size++;
            return size;
        }
        if(Heap[right].occupied == 0 && right < MAX){
            Heap[right].ele = val;
            Heap[right].occupied = 1;
            size++;
            return size;
        }
        if (Heap[right].occupied == 1 && Heap[left].occupied == 1) {
            i++;
        }
    }
}



void Heapify(HEAP* arr, int index) {
    // Bubble up the element to maintain the max-heap property
    while (index > 1) { // Ensure we don't move past the root at index 1
        int parentIndex = index / 2;

        // Swap if the current element is greater than its parent
        if (arr[index].ele > arr[parentIndex].ele) {
            HEAP temp = arr[index];
            arr[index] = arr[parentIndex];
            arr[parentIndex] = temp;

            // Move up to the parent for the next iteration
            index = parentIndex;
        } else {
            // Stop if the heap property is satisfied
            break;
        }
    }
}

void buildMaxHeap() {
    for (int i = size; i >= 1; i--) {
        Heapify(Heap, i);
    }
}

void display(){
    if(size == 0){
        printf("No elements\n");
        return;
    }
    for(int i = 1; i <= size;i++){
        if(Heap[i].occupied == 1)
            printf("%d ",Heap[i].ele);
    }
    printf("\n");
}

