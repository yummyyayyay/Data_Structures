#include <stdio.h>
#define MAX 100

typedef struct bs_tree{
    int info;
    int used;
}BST;

BST bst[MAX];
void inorder(int);
void input();
void init(){
    for(int i = 0; i < MAX; i++){
        bst[i].used = 0;
    }
}

int main(){
    int seln;
    init();
    while(1){
        printf("1.Add element\n2.Inorder traversal\n3.Exit\nEnter your choice:");
        scanf("%d",&seln);
        switch(seln){
            case 1:
                input();
                break;
            case 2:
                inorder(0);
                printf("\n");
                break;
            case 3:
                return 0;
            default:
                printf("Wrong input");
                break;
        }
    }
}

void input(){
    int ele;
    printf("Enter the element:");
    scanf("%d",&ele);

    if(bst[0].used == 0) {
        bst[0].info = ele;
        bst[0].used = 1;
        return;
    }

    int i = 0;
    while( i < MAX){
        if(bst[i].info > ele){
            int left = (2*i)+1;
            if(left >= MAX){
                printf("Overflow err:The array is full, no space for left child");
            }
            if(bst[left].used == 0){
                bst[left].info = ele;
                bst[left].used = 1;
                return;
            }
            else{
                i = left;
            }
        }
        else{
            int right = (i*2)+2;
            if(right >= MAX){
                printf("Overflow err:The array is full, no space for right child");
            }
            if(bst[right].used == 0){
                bst[right].info = ele;
                bst[right].used = 1;
                return;
            }
            else{
                i = right;
            }
        }
    }

    printf("The array is full");
}

void inorder(int index){
    if(index<MAX && (bst[index].used == 1)){
        inorder((2*index)+1);
        printf("%d",bst[index].info);
        inorder((2*index)+2);
    }
}