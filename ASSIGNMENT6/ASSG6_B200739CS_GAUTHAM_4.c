// made by gautham on 6th nov
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct tre{
    char key;
    struct tre* left;
    struct tre* right;
    struct tre* next;
};
typedef struct tre* tree;

struct thea{
    tree head;
};
typedef struct thea* thead;

bool TREE_EMPTY(thead s){
    if (s->head==NULL){
        return true;
    }
    else{
        return false;
    }
}

tree TREE_CREATE_NODE(char k, tree a, tree b){
    tree x;
    x=(tree)malloc(sizeof(struct tre));
    x->key=k;
    x->left=a;
    x->right=b;
    x->next=NULL;
    return x;
}

void TREE_PUSH(thead s,char n, tree a, tree b){
    tree t;
    t=TREE_CREATE_NODE(n,a,b);
    if(s->head!=NULL){
        t->next=s->head;
        s->head=t;
    }
    else{
        s->head=t;
    }
}

tree TREE_POP(thead s){
    bool x=TREE_EMPTY(s);
    if (x==true){
        return NULL;
    }
    tree present;
    tree b=s->head;
    present=s->head;
    if (present->next==NULL){
        s->head=NULL;
        return b;
    }
    s->head=present->next;
    return b;
}

thead CONSTRUCT_TREE(char e[]){
    thead s;
    s=(thead)malloc(sizeof(struct thea));
    for(int i=0;i<strlen(e);i++){
        if(e[i]>=97 && e[i]<=122){
            TREE_PUSH(s,e[i],NULL,NULL);
        }
        else{
            tree rc=TREE_POP(s);
            tree lc=TREE_POP(s);
            TREE_PUSH(s,e[i],lc,rc);
        }
    }
    return s;
}

void INORDER(tree z){
    if(z!=NULL){
        INORDER(z->left);
        printf("%c",z->key);
        INORDER(z->right);
    }
}

void PREORDER(tree z){
    if(z!=NULL){
        printf("%c",z->key);
        PREORDER(z->left);
        PREORDER(z->right);
    }
}

void POSTORDER(tree z){
    if(z!=NULL){
        POSTORDER(z->left);
        POSTORDER(z->right);
        printf("%c",z->key);
    }
}

int main(){
    char c='a';
    char e[10000];
    char u;
    thead tree;
    while(c!='t'){
        scanf("%c",&c);
        switch (c)
        {
        case 'e':
            scanf("%c",&u);
            scanf("%s",&e);
            tree=CONSTRUCT_TREE(e);
            break;
        case 'i':
            INORDER(tree->head);
            printf("\n");
            break;
        case 'p':
            PREORDER(tree->head);
            printf("\n");
            break;
        case 's':
            POSTORDER(tree->head);
            printf("\n");
            break;
        case 't':
            break;
        }
    }
    return 0;
}