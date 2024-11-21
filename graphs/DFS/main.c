#include <stdio.h>
#define MAX 10

void DFS(int adj[][MAX],int visited[MAX],int start,int nv){
    int stack[MAX];
    int top = -1;

    start--;
    visited[start] = 1;
    stack[++top]  = start;

    printf("DFS Traversal:");

    while(top != -1){
        int current = stack[top--];
        printf("%c ",current+65);

        for(int i = 0; i<nv;i++){
            if(adj[current][i] == 1 && visited[i] != 1 ){
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
    printf("\n");
}

int main(){
    int adj[MAX][MAX],visited[MAX] = {0};
    int start,nv;

    printf("Enter the number of vertices:");
    scanf("%d",&nv);

    for(int i = 0; i<nv;i++){
        for(int j = 0; j<nv;j++){
            printf("Enter the element into the adjacency matrix:");
            scanf("%d",&adj[i][j]);
        }
    }

    printf("Enter which vertex you wanna start at:");
    scanf("%d",&start);

    DFS(adj,visited,start,nv);

    return 0;
}