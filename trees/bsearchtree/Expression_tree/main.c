#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

typedef struct node{
    char info;
    struct node *right,*left;
}NODE;

typedef struct tree{
    NODE* root;
}TREE;

typedef struct stack{
    NODE* s[MAX];
    int top;
}STACK;

void init_tree(TREE* pt){
    pt->root = NULL;
}

void init_stack(STACK *ps){
    ps->top = -1;
}

int push(STACK *ps,NODE *e){
    if(ps->top == MAX-1){
        return 0;
    }
    ps->top++;
    ps->s[ps->top] = e;
    return 1;
}

NODE* pop(STACK* ps){
    NODE* t = ps->s[ps->top];
    ps->top--;
    return t;
}
float eval(NODE* r){ // NOLINT(*-no-recursion)
    float res;
    switch (r->info) {
        case '+':
            res = eval(r->left)+ eval(r->right);
            break;
        case '-':
            res = eval(r->left)-eval(r->right);
            break;
        case '*':
            res = eval(r->left)*eval(r->right);
            break;
        case '/':
            res = eval(r->left)/eval(r->right);
            break;
        default:
            return r->info-'0';
    }
    return res;
}

//float eval_tree(TREE* pt){
//    return eval(pt->root);
//}

int main(){
    char postfix[MAX];
    STACK so;
    TREE to;
    init_stack(&so);
    init_tree(&to);
    printf("enter the valid postfix expression:");
    scanf("%s",postfix);
    int i =0;
    while(postfix[i]!= '\0'){
        NODE * temp = malloc(sizeof(NODE));
        temp->info = postfix[i];
        temp->left = NULL;
        temp->right = NULL;
        if(isdigit(postfix[i]))
            push(&so,temp);
        else {
            temp->right = pop(&so);
            temp->left = pop(&so);
            push(&so,temp);
        }
        i++;
    }
    to.root=pop(&so);
    printf("%0.2f",eval(to.root));
    return 0;
}
