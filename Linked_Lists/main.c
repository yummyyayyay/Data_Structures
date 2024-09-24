//postfix implementation
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void infixtopostfix(char[],char[]);

int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    strcpy(postfix,"");
    infixtopostfix(infix,postfix);
    printf("The postfix version of the given expression is:");
    printf("%s",postfix);
    return 0;
}

void infixtopostfix(char source[],char destination[]){
    int i = 0,j=0,head=0;
    char stack[MAX];
    while(source[i] != '\0'){
        if(isalnum(source[i])){
            destination[j] = source[i];
            i++;
            j++;
        }
        else{
            if(head == 0){
                stack[head] = source[i];
                head++;
            }
            else if((source[i]== '+' || source [i] == '-') && (stack[head] == '*'|| stack[head] == '/' || stack[head] == '^')){
                destination[j] = stack[head];
                head--;
            }
            
            else if(source[i]== ')'){
                while(stack[head] != '('){
                    destination[j] = stack[head];
                    head--;
                    j++;
                }
            }
        }
    }
}