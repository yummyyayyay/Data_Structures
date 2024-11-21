//separate chaining using the hashing function - modulo
//the hashing index is being calculated using rno
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

//struct defining a student's roll no. and name
typedef struct node{
    int rno;
    char name[50];
    struct node* next;
}Node;

void initTable(Node*[]);
void insert(Node*[],int,char*);
int delete(Node*[],int);
int search(Node*[],int,char*);
void display(Node*[]);
void destroyNodes(Node*[]);

int main(){
    Node* ht[SIZE];
    initTable(ht);

    int choice,rno;
    char name[50];
    do{
        printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter rno:");
                scanf("%d",&rno);
                printf("Enter name:");
                scanf("%s",name);
                insert(ht,rno,name);
                break;
            case 2:
                printf("Enter rno:");
                scanf("%d",&rno);
                if(delete(ht,rno))
                    printf("Record with rno %d has been deleted\n",rno);
                else
                    printf("Record not found\n");
                break;
            case 3:
                printf("Enter the rno:");
                scanf("%d",&rno);
                printf("Enter the name:");
                scanf("%s",name);
                if(search(ht,rno,name))
                    printf("Found the Record\n");
                else
                    printf("Record not found\n");
                break;
            case 4:
                display(ht);
                break;
        }
    }while(choice < 5);
    destroyNodes(ht);
}

void initTable(Node* ht[]){
    for(int i = 0;i<SIZE;i++){
        ht[i] = NULL;
    }
}

void insert(Node* ht[],int rno,char* name){
    int index = rno%SIZE;

    if(ht[index] == NULL) {
        Node *temp = (Node *) malloc(sizeof(Node));
        temp->next = NULL;
        strcpy(temp->name, name);
        temp->rno = rno;
        ht[index] = temp;
    }
    else{
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->next = ht[index];
        temp->rno = rno;
        strcpy(temp->name,name);
        ht[index] = temp;
    }
}

int delete(Node* ht[],int rno){
    int index = rno%SIZE;
    if (ht[index] == NULL)
        return 0;
    else {
        Node *p = ht[index];
        Node* q = NULL;
        while(p != NULL && p->rno != rno){
            q = p;
            p = p->next;
        }
        if(p != NULL){
            if(q == NULL){
                ht[index] = p->next;
            }
            else{
                q->next = p->next;
            }
            free(p);
            return 1;
        }
        else
            return 0;
    }
}

int search(Node* ht[],int rno,char* name){
    int index = rno%SIZE;
    if(ht[index] == NULL)
        return 0;
    else{
        Node* p = ht[index];
        while(p != NULL){
            if((p->rno == rno) && (strcmp(p->name,name) == 0))
                return 1;
            else
                p = p->next;
        }
        return 0;
    }
}

void display(Node* ht[]){
    for(int i = 0;i<SIZE;i++){
        if(ht[i] != NULL){
            Node* p = ht[i];
            printf("h[%d]->",i);
            while(p != NULL){
                printf("%d %s\n1",p->rno,p->name);
                p = p->next;
            }
        }
    }
}

void destroyNodes(Node* ht[]){
    for(int i = 0;i<SIZE;i++){
        if(ht[i] != NULL){
            Node* p = ht[i];
            while(p != NULL){
                Node* temp = p;
                p = p->next;
                free(temp);
            }
            ht[i] = NULL;
        }
    }
}
