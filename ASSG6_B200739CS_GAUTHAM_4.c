// made by gautham on 6th nov
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct stac{
    char key;
    struct stac* left;
    struct stac* right;
    struct stac* next;
};
typedef struct stac* stack;

struct ll{
    stack head;
};
typedef struct ll* sll;

bool STACK_EMPTY(sll s){
    if (s->head==NULL){
        return true;
    }
    else{
        return false;
    }
}

stack CREATE_NODE(char k, stack a, stack b){
    stack x;
    x=(stack)malloc(sizeof(struct stac));
    x->key=k;
    x->left=a;
    x->right=b;
    x->next=NULL;
    return x;
}

void PUSH(sll s,char n, stack a, stack b){
    stack t;
    t=CREATE_NODE(n,a,b);
    if(s->head!=NULL){
        t->next=s->head;
        s->head=t;
    }
    else{
        s->head=t;
    }
}

stack POP(sll s){
    bool x=STACK_EMPTY(s);
    // if (x==true){
    //     return '0';
    // }
    stack present;
    stack b=s->head;
    present=s->head;
    if (present->next==NULL){
        s->head=NULL;
        return b;
    }
    s->head=present->next;
    return b;
}

sll CONSTRUCT_TREE(char e[]){
    sll s;
    s=(sll)malloc(sizeof(struct ll));
    for(int i=0;i<strlen(e);i++){
        if(e[i]>=97 && e[i]<=122){
            PUSH(s,e[i],NULL,NULL);
        }
        else{
            stack rc=POP(s);
            stack lc=POP(s);
            PUSH(s,e[i],lc,rc);
        }
    }
    return s;
}

void INORDER(stack z){
    if(z!=NULL){
        INORDER(z->left);
        printf("%c",z->key);
        INORDER(z->right);
    }
}

void PREORDER(stack z){
    if(z!=NULL){
        printf("%c",z->key);
        PREORDER(z->left);
        PREORDER(z->right);
    }
}

void POSTORDER(stack z){
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
    sll tree;
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