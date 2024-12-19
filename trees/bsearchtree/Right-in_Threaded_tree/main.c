#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* right;
    struct node* left;
    int rthread;
}Node;

Node* createNode(int ele){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->info = ele;
    temp->right = NULL;
    temp->left = NULL;
    temp->rthread = 1;
    return temp;
}

void setLeft(Node* q,int ele){
    Node* temp = createNode(ele);
    q->left = temp;
    temp->right = q;
}

void setRight(Node* q,int ele){
    Node* temp = createNode(ele);
    temp->right = q->right;
    q->right = temp;
    q->rthread = 0;
}

void inorder(Node* root){
    Node* p = root,*q;
    do{
        q = NULL;
        while(p != NULL){
            q = p;
            p = p->left;
        }
        if(q != NULL){
            printf("%d",q->info);
            p = q->right;
            while(q->rthread && p!= NULL){
                printf("%d",p->info);
                q = p;
                p = p->right;
            }
        }
    } while(q != NULL);
}

void create(Node* root){
    Node *p = root;
    int ele;
    printf("Enter the element you want to enter:");
    scanf("%d",&ele);
    if(root == NULL){
        root = createNode(ele);
        return;
    }

    while(p != NULL){
        if(ele < p->info){
            if(p->left == NULL){
                setLeft(p,ele);
                return;
            }
            p = p->left;
        }
        else if(ele > p->info){
            if(p->right == NULL){
                setRight(p,ele);
                return;
            }
            p = p->right;
        }
    }

}