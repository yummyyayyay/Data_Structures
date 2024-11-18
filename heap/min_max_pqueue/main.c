//PQueue using Min-Max Heap
//ascending priority queue - here we will arbitrarily add in elements into the heap, and then we will delete the smallest element always;
//descending priority queue - same as apq, but it is in descending order
#include <stdio.h>
#define MAX 100

typedef struct pq{
    int size;
    int pq[MAX];
}PQ;

void init(PQ*pq){
    pq->size = 0;
}

void display(PQ pq){
    int size = pq.size;
    for(int i = 0;i<size;i++){
        printf("%d ",pq.pq[i]);
    }
    printf("\n");
}

int insert(PQ *pq,int ele){
    if(pq->size == MAX){
        return -1;
    }
    int c = pq->size, parent = (c-1)/2;
    //moving to the position of insertion
    while(c>0 && pq->pq[parent]<ele){
        pq->pq[c] = pq->pq[parent];
        c = parent;
        parent = (c-1)/2;
    }
    pq->pq[c] = ele;
    pq->size++;
    return 1;
}

int dequeue(PQ*pq, int* ele){
    int p,c;
    if(pq->size == 0)
        return -1;
    *ele = pq->pq[0];
    int elt = pq->pq[pq->size-1];
    p = 0;
    if(pq->size == 1)
        c = -1;
    else
        c = 1;
    if(pq->size>2 && pq->pq[2]>pq->pq[1])
        c = 2;
    while(c >= 0 && elt < pq->pq[c]){
        pq->pq[p] = pq->pq[c];
        p = c;
        c = 2*p+1;
        if(c+1 < pq->size-1 && pq->pq[c]<pq->pq[c+1])
            c = c+1;
        if(c>pq->size-1)
            c = -1;
    }
    pq->pq[p] = elt;
    pq->size--;
    return 1;
}

int main(){
    int choice,ele,ret;
    int del;
    PQ pq;
    init(&pq);
    while(1){
        printf("1.Insert element\n2.Delete element\n3.Display element\n4.exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element:");
                scanf("%d",&ele);
                ret = insert(&pq,ele);
                if(ret == -1)
                    printf("The queue is already full!!\n");
                else
                    printf("The element has been successfully inserted!!\n");
                break;
            case 2:
                ret = dequeue(&pq,&del);
                if(ret == -1)
                    printf("The queue is empty!!\n");
                else
                    printf("%d has been deleted\n",del);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                return 0;
            default:
                printf("incorrect input!!\n");
        }
    }
}