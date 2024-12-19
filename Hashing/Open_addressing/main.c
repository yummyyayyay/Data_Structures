//collision resolution using open addressing
//linear probing (h(k)+i)%size)
#include <stdio.h>
#include <string.h>
#define SIZE 7

typedef struct node{
    int rno;
    char name[50];
    int occupied;
}Node;

void initTable(Node[],int*);
int insert(Node[],int,char*,int*);
int delete(Node[],int,int*);
int search(Node[],int,int );
void display(Node[],int );

int main(){
    Node ht[SIZE];
    int choice,rno,size;
    initTable(ht,&size);
    char name[50];
    do{
        printf("1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter rno:");
                scanf("%d",&rno);
                printf("Enter name:");
                scanf("%s",name);
                insert(ht,rno,name,&size);
                break;
            case 2:
                printf("Enter rno:");
                scanf("%d",&rno);
                if(delete(ht,rno,&size))
                    printf("Record has been deleted!\n");
                else
                    printf("Record not found\n");
                break;
            case 3:
                display(ht,size);
                break;
            case 4:
                printf("Enter rno:");
                scanf("%d",&rno);
                printf("Enter name:");
                scanf("%s",name);
                if(search(ht,rno,size))
                    printf("Record found!\n");
                else
                    printf("Record not found!\n");
                break;
            default:
                printf("Incorrect input!\n");
                break;
        }
    }while(choice != 5);
}

void initTable(Node ht[],int*size){
    for(int i = 0;i<SIZE;i++){
        ht[i].occupied = -1;
    }
    *size = 0;
}

int insert(Node*ht,int rno,char* name,int* size){
    if(*size == SIZE)
        return 0;

    int index = rno%SIZE;
    while(ht[index].occupied != -1)
        index = (index+1)%SIZE;

    ht[index].rno = rno;
    strcpy(ht[index].name,name);
    ht[index].occupied = 1;
    (*size)++;
    return 1;
}

int delete(Node* ht,int rno,int* size){
    if(*size == 0)
        return 0;
    int index = rno%SIZE;

    int i = 0;
    while(ht[index].rno != rno && i<*size){
        index = (index+1)%SIZE;
        if(ht[index].occupied == 1)
            i++;
    }
    if(ht[index].rno == rno && ht[index].occupied == 1) {
        ht[index].occupied = -1;
        (*size)--;
        return 1;
    }
    return 0;
}

int search(Node ht[],int rno,int size){
    if(size == 0)
        return 0;
    int index = rno % SIZE;
    int i =0;
    while(ht[index].rno != rno && i<size){
        index = (index+1)%SIZE;
        if(ht[index].occupied == 1)
            i++;
    }
    if(ht[index].rno == rno && ht[index].occupied == 1)
        return 1;
    return 0;
}

void display(Node ht[],int size){
    if(size == 0)
        printf("Empty!!\n");
    for(int i = 0;i<SIZE;i++){
        if(ht[i].occupied == 1)
            printf("%d %s\n",ht[i].rno,ht[i].name);
    }
}
