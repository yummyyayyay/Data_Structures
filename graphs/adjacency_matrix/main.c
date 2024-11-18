//adjacency matrix implementation
#include <stdio.h>
#define MAX 14

typedef struct node{
    int id;
    char name[MAX];
}NODE;

typedef struct edge{
    int adj;
}EDGE;

typedef struct graph{
    NODE node[MAX];
    EDGE edge[MAX][MAX];
}GRAPH;

//functions using adjacency matrix

void join(GRAPH* g,int u,int v){
    g->edge[u][v].adj = 1;
}

void delete(GRAPH* g,int u,int v){
    g->edge[u][v].adj = 0;
}

int check(GRAPH g,int u ,int v){
    if(g.edge[u][v].adj!= 0 )
        return 0;
    else
        return -1;
}

void mul_insert(GRAPH* g,int n){
    for(int i = -1; i<n;i++){
        for(int j = -1;j<n;j++){
            scanf("%d", &g->edge[i][j].adj);
        }
    }
}