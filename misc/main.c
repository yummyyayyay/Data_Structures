//#include <stdio.h>
//#define MAX 10
////
////void DFS(int adj[][MAX],int visited[],int start,int nv){
////    int stack[MAX], top = -1;
////    start--;
////
////    stack[++top] = start;
////    visited[start] = 1;
////
////    while(top != -1){
////        int current = stack[top--];;
////        printf("%c",current+65);
////
////        for(int i = 0 ; i < nv; i++){
////            if(adj[current][i] == 1 && visited[i] != 1){
////                visited[i] = 1;
////                stack[++top] = i;
////            }
////        }
////    }
////}
//
////int chkPath(int a[MAX][MAX],int n,int visited[MAX],int src,int dest)
////{
//////	printf("%d ",src);	//Print src
////    visited[src]=1;	//Mark src visited
////
////    for(int i=0;i<n;i++)	//To traverse the nodes adjacent to src
////    {
////        if(a[src][i]==1  && visited[i]==0)	//For the first vertex 'i' adjacent and unvisited, start exploring 'i'
////            if(i==dest || chkPath(a,n,visited,i,dest))	//start exploring 'i'
////                return 1;
////    }
////    return 0;
////}
//
//int chkpath(int adj[][MAX],int n,int visited[],int src,int dest){
//    printf("%d",src);
//    visited[src] = 1;
//
//    for(int i = 0; i < n ; i++){
//        if(adj[src][i] == 1 && visited[i] != 1){
//            if(i == dest || chkpath(adj,n,visited,i,dest))
//                return 1;
//        }
//        return 0;
//    }
//}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prec(char c){
    if(c == '^')
        return 3;
    if(c == '/' || c == '*' || c == '%')
        return 2;
    if(c == '+' || c =='-')
        return 1;
    else return -1;
}

void flip(char* exp){
    int len = strlen(exp);
    char rev[len+1];
    for(int i = len-1;i>=0;i--){
        rev[len-i-1] = exp[i];
    }
    rev[len] = '\0';
    strcpy(exp,rev);
}

void parenFlip(char* exp){
    int len = strlen(exp);
    for(int i = 0;i<len;i++){
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

void infixToPrefix(char* exp){
    int len = strlen(exp);
    int j = 0;
    int top = -1;
    char stk[len];
    char result[len+1];
    flip(exp);
    parenFlip(exp);
    for(int i = 0;i<len;i++){
        char c = exp[i];

        if(isalnum(c))
            result[j++] = c;
        else if(c == '(')
            stk[++top] = c;
        else if(c == ')') {
            while (top != -1 && stk[top] != '(')
                result[j++] = stk[top--];
            top--;
        }
        else{
            while(top != -1 && prec(c) <= prec(stk[top]))
                result[j++] = stk[top--];
            stk[++top] = c;
        }
    }
    while(top != -1)
        result[j++] = stk[top--];
    flip(result);
    result[j] = '\0';
    printf("%s\n",result);
}

int main(){
    char exp[] = "(A-B/C)*(A/K-L)";
    infixToPrefix(exp);
    return 0;
}