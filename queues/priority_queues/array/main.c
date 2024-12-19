/*#include <stdio.h>

typedef struct pqueue{
    int data;
    int pty;
}pqueue;
pqueue pq[10];

void insert(pqueue pq[],int data, int pty, int* count){
    pqueue temp;
    temp.data = data;
    temp.pty = pty;

    int j = *count -1 ;

    while((j>=0)&&(pq[j].pty>temp.pty)){
        pq[j+1] = pq[j];
        j--;
    }
    pq[j+1] = temp;
    (*count)++;
}

pqueue delete(pqueue pq[],int* count){
    pqueue key;
    if(*count == 0){
        key.data = 0;
        key.pty = -1;
    }
    else{
        key = pq[0];
        for(int i = 1;i< *count; i++){
            pq[i-1] = pq[i];
        }
    }
    return key;
}

int main(){
    int count = 0;
    insert(pq,5,1,&count);
    insert(pq,2,2,&count);
    insert(pq,1,5,&count);
    insert(pq,8,3,&count);

    delete(pq,&count);

    for(int i = 0; i<count;i++){
        printf("%d",pq[i].data);
        if(i != count-1)
            printf("<-");
    }
    return 0;
}*/

//descending priority queue
#include <stdio.h>

typedef struct pqueue{
    int data;
    int pty;
}pqueue;

pqueue pq[5];

void insert(pqueue arr[],int data,int pty,int* count){
    pqueue temp;
    temp.data = data;
    temp.pty = pty;
    int j = *count - 1;

    while((j>=0) && (arr[j].pty<temp.pty)){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
    (*count)++;
}

pqueue delete(pqueue pq[],int* count){
    pqueue key;
    if(*count == 0){
        key.data = 0;
        key.pty = -1;
    }
    else{
        key = pq[0];
        for(int i = 1;i< *count; i++){
            pq[i-1] = pq[i];
        }
        (*count)--;
    }
    return key;
}

int main(){
    int count = 0;
    insert(pq,5,1,&count);
    insert(pq,2,2,&count);
    insert(pq,1,5,&count);
    insert(pq,8,3,&count);

    for(int i = 0; i<count;i++){
        printf("%d",pq[i].data);
        if(i != count-1)
            printf("<-");
    }
    printf("\n");

    pqueue rand = delete(pq,&count);

    for(int i = 0; i<count;i++){
        printf("%d",pq[i].data);
        if(i != count-1)
            printf("<-");
    }
    return 0;
}