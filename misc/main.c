void insert(Trie* root,char* pattern){
    Trie* cur = root;
    while(*pattern != '\0'){
        if(cur->child[*pattern-'a'] == NULL)
            cur->child[*pattern-'a'] = createNode();
        cur = cur->child[*pattern-'a'];
        pattern++;
    }
}

int search(Trie* root,char* pattern){
    Trie* cur = root;
    while(*pattern != '\0'){
        if(cur->child[*pattern-'a'] != NULL){
            cur = cur->child[*pattern-'a'];
        }
        else
            return 0;
    }
    if(cur->endOfWord == 1)
        return 1;
    return 0;
}

Trie* delete(Trie* root char* str,int level,int len){
    if(root == NULL)
        return root;

    if(level == len){
        if(root->endOfWord != 0)
            root->endOfWord == 0;
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

int isEmpty(Trie* root){
    for(int i =0;i<26;i++){
        if(root->child[i] != NULL)
            return 0;
    }
    return 1;
}