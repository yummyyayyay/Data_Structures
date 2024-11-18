#include <stdio.h>
#define MAX 10

void BFS(int adj[][MAX],int visited[MAX],int start){
    int queue[MAX],rear = -1,front = -1,current;
    queue[rear++] = start;
    visited[start] = 1;
    while(front != rear){
        current = queue[front++];
        printf("%c \t",65+current);

        for(int i = 0;i<MAX;i++){
            if(adj[current][i] == 1 && visited[i] == 0){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int adj[MAX][MAX],visited[MAX] = {0};
    int start;
    printf("Enter the adjacency matrix:");
    for(int i = 0 ; i<MAX;i++){
        for(int j =0;j<MAX;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the starting node:");
    scanf("%d",&start);

    printf("Enter the starting node %c:\n",65+start);
    BFS(adj,visited,start);
    return 0;
}