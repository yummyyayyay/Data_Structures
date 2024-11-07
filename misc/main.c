#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* left;
    struct node* right;

}NODE;

//void inorder(NODE root){
//    stack s = emptyStack;
//    NODE* currentNode = &root;
//    do{
//        while(currentNode != NULL){
//            push(s,currentNode);
//            currentNode = currentNode->left;
//        }
//        NODE poppedNode = pop(s);
//        printf("%d ", poppedNode.info);
//        currentNode = currentNode->right;
//    }
//}while(isEmpty(s) && currentNode != NULL);

//preorder
//void preorder(NODE* root){
//    NODE* currentNode = root;
//    if(currentNode == NULL)
//        return;
//    stack s = emptyStack;
//    push(s,currentNode);
//    while(isEmpty(s)){
//        currentNode = pop(s);
//        printf("%d",currentNode->info);
//        if(currentNode->right != NULL)
//            push(s,currentNode->right);
//        if(currentNode->left != NULL)
//            push(s,currentNode->left);
//    }
//}

//posorder
//void postorder(NODE* root){
//    stack s1 = emptyStack;
//    stack s2 = emptyStack;
//    NODE* current = NULL;
//    push(s1,root);
//    while(isEmpty(s1)){
//        current = pop(s1);
//        push(s2,current);
//        if(current->right)
//            push(s2,current->right);
//        if(current->left)
//            push(s2,current->left);
//    }
//    while(isEmpty(s2)){
//        current = pop(s2);``
//        printf("%d ",current->info);
//    }
//}