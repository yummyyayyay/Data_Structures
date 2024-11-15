#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int info;
    struct node* left;
    struct node* right;
}NODE;

//NODE* tree;
NODE* insertElement(NODE*, int);
void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);
NODE* findSmallest(NODE*);
NODE* findLargest(NODE*);
int deleteElement(NODE**, int);
NODE* mirrorImage(NODE*);
int totalNodes(NODE*);
int totalExternalNodes(NODE*);
int totalInternalNodes(NODE*);
int height(NODE*);
NODE* deleteTree(NODE*);

int main(){
    NODE *tree = NULL;
    NODE* ptr = NULL;
    int option,ele,ret;
    while(1){
        printf("1Insert Element\n2.Preorder representation\n3.Inorder representation\n4.Postorder representation\n"
               "5.Find the smallest element\n6.Find the largest element\n7.Delete an element\n8.Total number of nodes\n"
               "9.Total number of internal nodes\n10.Total number of external nodes\n11.Mirror of the tree\n12.Height of tree\n"
               "13.Delete tree\n14.Exit\nEnter your choice:");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the element:");
                scanf(" %d",&ele);
                tree = insertElement(tree,ele);
                break;
            case 2:
                if(tree == NULL)
                    printf("The tree is empty\n");
                else{
                    preorder(tree);
                    printf("\n");
                }
                break;
            case 3:
                if(tree == NULL){
                    printf("The tree is empty\n");
                }
                else{
                    inorder(tree);
                    printf("\n");
                }
                break;
            case 4:
                if(tree == NULL){
                    printf("The tree is empty\n");
                }
                else{
                    postorder(tree);
                    printf("\n");
                }
                break;
            case 5:
                ptr = findSmallest(tree);
                if(ptr == NULL)
                    printf("The tree is empty!\n");
                else
                    printf("%d\n",ptr->info);
                break;
            case 6:
                ptr = findLargest(tree);
                if(ptr == NULL)
                    printf("The tree is empty!\n");
                else
                    printf("%d\n",ptr->info);
                break;
            case 7:
                printf("Enter the element to be deleted:");
                scanf(" %d",&ele);
                ret = deleteElement(&tree,ele);
                if(ret == -1)
                    printf("Node not present\n");
                if(ret == 0)
                    printf("The tree is empty");
                if(ret == 1)
                    printf("The node has been successfully deleted\n");
                break;
            case 8:
                ret = totalNodes(tree);
                printf("The total number of nodes are %d\n",ret);
                break;
            case 9:
                ret = totalInternalNodes(tree);
                printf("The total number of internal nodes %d\n",ret);
                break;
            case 10:
                ret = totalExternalNodes(tree);
                printf("The total number of external nodes %d\n",ret);
                break;
            case 11:
                ptr = mirrorImage(tree);
                inorder(ptr);
                break;
            case 12:
                ret = height(tree);
                printf("The height of the tree is %d\n",ret);
                break;
            case 13:
                tree = deleteTree(tree);
                break;
            case 14:
                return 0;
            default:
                printf("Wrong option\n");
                break;
        }
    }
}


NODE* insertElement(NODE* root,int ele){
    //base case where the root is null
    if(root == NULL){
        NODE* newNode = malloc(sizeof(NODE));
        if(newNode == NULL){
            printf("Memory allocation failed!!\n");
            return NULL;
        }
        newNode->info = ele;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }
    if(ele < (root->info))
        root->left = insertElement(root->left,ele);
    if(ele > root->info)
        root->right = insertElement(root->right,ele);
    if(ele == root->info) {
        printf("Duplicate\n");
        return root;
    }
    return root;
}


void preorder(NODE* root){
    if(root == NULL)
        return;
    printf("%d ",root->info);
    if(root->left)
        preorder(root->left);
    if(root->right)
        preorder(root->right);
}

void inorder(NODE* root){
    if(root == NULL)
        return;
    if(root->left)
        inorder(root->left);
    printf("%d",root->info);
    if(root->right)
        inorder(root->right);
}

void postorder(NODE* root){
    if(root == NULL)
        return;
    if(root->left)
        postorder(root->left);
    if(root->right)
        postorder(root->right);
    printf("%d ",root->info);

}

NODE* findSmallest(NODE* root){
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL)
        return root;
    else
        return findSmallest(root->left);

}

NODE* findLargest(NODE* root){
    if(root == NULL)
        return NULL;
    if(root->right == NULL){
        return root;
    }
    else{
        return findLargest(root->right);
    }
}

int deleteElement(NODE** root, int ele){
    if(*root == NULL){
        return 0;
    }
    //traversal through tree to find the node to be deleted
    NODE* cur = *root;
    NODE* parent = NULL;
    while(cur != NULL && cur->info != ele){
        parent = cur;
        if(cur->info > ele)
            cur = cur->left;
        else if(cur->info < ele)
            cur = cur->right;
    }

    if(cur == NULL){
        return -1;
    }
    //different deletion situations
    //case 1 with no children to cur
    if(cur->left == NULL && cur->right == NULL){
        if(parent == NULL)
            free(*root);
        else if(parent->left == cur)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(cur);
        return 1;
    }
    //case 2 with one child
    else if(cur->left != NULL || cur->right != NULL){
        NODE* child = cur->left!= NULL ? cur->left:cur->right;
        if(parent == NULL)
            *root = child;
        else if(cur == parent->left)
            parent->left = child;
        else if(cur == parent->right)
            parent->right = child;
        free(cur);
        return 1;
    }
    //case 3 with both children
    else{
        NODE* predecessor = findLargest(cur->left);
        cur->info = predecessor->info;
        deleteElement(&predecessor, predecessor->info);
        return 1;
    }
}

NODE* mirrorImage(NODE* root){
    if(root == NULL) {
        return NULL;
    }
    else{
        mirrorImage(root->left);
        mirrorImage(root->right);
        NODE* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
}

int totalNodes(NODE* root){
    if(root == NULL)
        return 0;

    else if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return totalNodes(root->left)+ totalNodes(root->right)+1;
}

int totalInternalNodes(NODE* root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    else{
        return 1+ totalInternalNodes(root->left)+ totalInternalNodes(root->right);
    }
}

int totalExternalNodes(NODE* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return totalExternalNodes(root->left)+ totalExternalNodes(root->right);
}

int height(NODE* root){
    if(root == NULL)
        return -1;
//    else if(root->left == NULL && root->right == NULL)
//        return 0;
//    else if(height(root->left)>height(root->right))
//        return height(root->left)+1;
//    else
//        return height(root->right)+1;
    return (height(root->left)>height(root->right)?height(root->left):height(root->right))+1;
}

NODE* deleteTree(NODE* root){
    if(root == NULL)
        return NULL;
    else{
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
        return NULL;
    }
}

//typedef struct node{
//    int info;
//    struct node* left;
//    struct node* right;
//
//}NODE;

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