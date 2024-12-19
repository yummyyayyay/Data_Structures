#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int id;
    struct node* next;
}NODE;

void displayGraph(NODE* adj[],int nVert);
void createGraph(NODE* adj[],int nVert);
void deleteGraph(NODE* adj[],int nVert);

int main(){
    NODE* adj[10];
    int nVert;
    printf("Enter the number of vertices:");
    scanf("%d",&nVert);
    for(int i = 0;i<nVert;i++){
        adj[i] = NULL;
    }
    createGraph(adj,nVert);
    displayGraph(adj,nVert);
    deleteGraph(adj,nVert);
    return 0;
}

void createGraph(NODE* adj[],int nVert){
    NODE* temp,*last=NULL;
    int neighbours;
    for(int i = 0;i<nVert;i++){
        adj[i] = (NODE*)malloc(sizeof(NODE));
        printf("Enter the vertex id:");
        scanf("%d",&adj[i]->id);
        adj[i]->next = NULL;
        printf("Enter the number of adjacent nodes:");
        scanf("%d",&neighbours);
        for(int j = 0;j<neighbours;j++){
            printf("Enter the adjacent node id:");
            temp = (NODE*)malloc(sizeof(NODE));
            scanf("%d",&temp->id);
            temp->next = NULL;
            if(adj[i]->next == NULL)
                adj[i]->next = temp;
            else{
                last->next = temp;
            }
            last = temp;
        }
    }
}

void displayGraph(NODE* adj[],int nVert){
        for(int i = 0;i<nVert;i++){
            NODE* temp = adj[i]->next;
            printf("The adjacent nodes of %d vertex are:",adj[i]->id);
            while(temp != NULL){
                printf("%d ",temp->id);
                temp = temp->next;
            }
            printf("\n");
        }
}

void deleteGraph(NODE* adj[],int nVert){
    for(int i = 0; i < nVert;i++){
        NODE* current = adj[i];
        NODE* temp;
        while(current != NULL){
            temp =current;
            current = current->next;
            free(temp);
        }
    }
}