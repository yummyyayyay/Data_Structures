#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    int thread;
    struct node* right;
    struct node* left;
}NODE;

NODE* root = NULL;
NODE* insertNode(NODE* root,NODE* ptr,NODE* rt){

    if(root == NULL) {
        root = ptr;
        if (rt != NULL) {
            root->right = rt;
            root->thread = 1;
        }
    }
    else if(ptr->val < root->val)
    root->left = insertNode(root->left, ptr, root);
    else
    if(root->thread == 1){
        root->right = insertNode(NULL, ptr, rt);
        root->thread = 0;
    }
    else
        root->right = insertNode(root->right, ptr, rt);
    return root;
}

NODE* createTree(){
    int val;
    printf("Enter the numbers , press -1 to terminate:");
    fscanf(stdin,"%d",val);
    do{
        NODE* ptr = (NODE*)malloc(sizeof(NODE));
        ptr->val = val;
        ptr->right = NULL;
        ptr->left = NULL;
        ptr->thread = 0;
        root = insertNode(root,ptr,NULL);
        printf("Enter the next element");
        scanf("%d",&val);
    }while(val != -1);
    return root;
}

void inorder(NODE* root){
    NODE* ptr = root,*prev;
    do{
        while(ptr != NULL){
            prev = ptr;
            ptr = ptr->left;
        }
        if(prev != NULL){
            printf("%d ",prev->val);
            ptr = prev->right;
            while(prev != NULL && prev->thread){
                printf("%d ",ptr->val);
                prev = ptr;
                ptr = prev->right;
            }
        }
    }while(ptr != NULL);
}

int main(){
    createTree();
    printf("The inorder representation of the tree will be\n");
    inorder(root);
    return 0;
}