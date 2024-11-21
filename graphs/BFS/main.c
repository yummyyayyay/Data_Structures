#include <stdio.h>
#define MAX 15

void BFS(int adj[][MAX],int visited[],int start,int nv){
    int queue[MAX],front = -1,rear = -1;
    start--;
    printf("BFS Traversal:");
    visited[start] = 1;
    queue[rear++] = start;

    while(front != rear){
        int current = queue[front++];
        printf("%c ",65+current);

        for(int i = 0;i<nv;i++){
            if(adj[current][i] == 1 && visited[i] != 1){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int adj[MAX][MAX];
    int visited[MAX];
    int nv,start;

    printf("Enter the number of vertices:");
    scanf("%d",&nv);

    for(int i = 0; i < nv;i++){
        for(int j = 0;j<nv;j++){
            printf("Enter the element into adjacency matrix:");
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the start vertex:");
    scanf("%d",&start);
    BFS(adj,visited,start,nv);
    return 0;
}