#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int pty;
    struct node* next;
}NODE;

NODE* head = NULL;

void insert(int data, int pty){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->pty = pty;
    temp->next = NULL;
    if(head == NULL || head->pty>temp->pty){
        temp->next = head;
        head = temp;
    }
    else{
        NODE * q = head;
        while(q->next != NULL && q->next->pty <= temp->pty)
            q = q->next;
        temp->next = q->next;
        q->next = temp;
    };
}

void delete(){
    if(head == NULL)
        printf("The queue is empty");
    else{
        NODE* temp = head;
        head = head->next;
        free(temp);
    }
}