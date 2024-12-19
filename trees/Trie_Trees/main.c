//prefix tree operations (Trie-tree)
//node will consist only of lower case english alphabets
//operations - insert , delete , search
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie{
    struct trie *child[26];
    int endOfWord;
}Trie;

Trie* createNode();
void insertPattern(Trie*,char*);
int search(Trie*,char*);
Trie* delete(Trie*,char*,int,int);
int isEmpty(Trie*);

int main(){
    Trie *root = createNode();

    insertPattern(root,"apple");
    insertPattern(root,"app");
    insertPattern(root,"apt");

    if(search(root,"apple")){
        printf("The word exists\n");
    }
    else
        printf("The word doesn't exit in the tree\n");

    if(search(root,"arkansas")){
        printf("The word exists\n");
    }
    else
        printf("The word doesn't exit in the tree\n");


    delete(root,"apple",0,strlen("apple"));
    if(search(root,"apple")){
        printf("The word exists\n");
    }
    else
        printf("The word doesn't exit in the tree\n");


    return 0;
}

Trie* createNode(){
    Trie* temp = (Trie*)malloc(sizeof(Trie));

    for(int i = 0;i<26;i++){
        temp->child[i] = NULL;
    }
    temp->endOfWord = 0;

    return temp;
}

void insertPattern(Trie* root,char* pattern){
    Trie* cur = root;
    while(*pattern != '\0'){
        if(cur->child[*pattern-'a'] == NULL)
            cur->child[*pattern-'a'] = createNode();
        cur = cur->child[*pattern-'a'];
        pattern++;
    }
    cur->endOfWord = 1;
}

int search(Trie* root,char* pattern){
    Trie* cur = root;
    while(*pattern != '\0'){
        if(cur->child[*pattern-'a'] != NULL){
            cur = cur->child[*pattern-'a'];
            pattern++;
        }
        else return 0;
    }
    if(cur->endOfWord == 1)
        return 1;
    return 0;
}

Trie* delete(Trie* root,char* str,int level,int len){ // NOLINT(*-no-recursion)
    if(root == NULL)
        return root;

    if(level == len){
        if(root->endOfWord)
            root->endOfWord = 0;
        if(isEmpty(root)){
            free(root);
            root = NULL;
            return root;
        }
    }

    int index = str[level]-'a';
    root->child[index] = delete(root->child[index],str,level+1,len);

    if(root->endOfWord == 0 && isEmpty(root)){
        free(root);
        root = NULL;
    }
    return root;
}

int isEmpty(Trie* node){
    for(int i =0;i<26;i++){
        if(node->child[i] != NULL)
            return 0;
    }
    return 1;
}