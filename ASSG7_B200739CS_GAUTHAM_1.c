// made by gautham on 13th nov
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>

struct nod{
    int key;
    struct nod* par;
    struct nod* left;
    struct nod* right;
};
typedef struct nod* node;

struct tre{
    node root;
};
typedef struct tre* tree;

node CREATE_NODE(int k){
    node x;
    x=(node)malloc(sizeof(struct nod));
    x->key=k;
    x->left=NULL;
    x->par=NULL;
    x->right=NULL;
    return x;
}

void INSERT(tree t, int k){
    node a;
    a=CREATE_NODE(k);
    node x,y;
    y=NULL;
    x=t->root;
    while(x!=NULL){
        y=x;
        if(x->key<=a->key){
            x=x->right;
        }
        else{
            x=x->left;
        }
    }
    a->par=y;
    if(y==NULL){
        t->root=a;
    }
    else if(a->key<y->key){
        y->left=a;
    }
    else{
        y->right=a;
    }
}

node SEARCH(tree t,int k){
    node present;
    present=t->root;
    while(present!=NULL && present->key!=k){
        if(present->key>k){
            present=present->left;
        }
        else{
            present=present->right;
        }
    }
    return present;
}

void SUCCESSOR(tree t, int k){
    node present;
    present=SEARCH(t,k);
    if(present->right!=NULL){
        while(present->left!=NULL){
            present=present->left;
        }
        printf("%d\n",present->key);
    }
    else{
        node p;
        p=present->par;
        while(p!=NULL && present!=p->right){
            present=p;
            p=p->par;
        }
        printf("%d\n",p->key);
    }
}

void PREDECESSOR(tree t, int k){
    node present;
    present=SEARCH(t,k);
    if(present->left!=NULL){
        while(present->right!=NULL){
            present=present->right;
        }
        printf("%d\n",present->key);
    }
    else{
        node p;
        p=present->par;
        while(p!=NULL && present!=p->left){
            present=p;
            p=p->par;
        }
        printf("%d\n",p->key);
    }
}

void INORDER(node r){
    if(r!=NULL){
        INORDER(r->left);
        printf("%d ",r->key);
        INORDER(r->right);
    }
}

void PREORDER(node r){
    if(r!=NULL){
        printf("%d ",r->key);
        PREORDER(r->left);
        PREORDER(r->right);
    }
}

void POSTORDER(node r){
    if(r!=NULL){
        POSTORDER(r->left);
        POSTORDER(r->right);
        printf("%d ",r->key);
    }
}

int main(){
    tree t;
    t=(tree)malloc(sizeof(struct tre));
    char c='b';
    int k;
    while(c!='e'){
        scanf("%c",&c);
        switch (c)
        {
        case 'a':
            scanf(" %d",&k);
            INSERT(t,k);
            break;
        case 'd':
            scanf(" %d",&k);
            DELETE(t,k);
            break;
        case 's':
            scanf(" %d",&k);
            SEARCH(t,k);
            break;
        case 'c':
            scanf(" %d",&k);
            SUCCESSOR(t,k);
            break;
        case 'r':
            scanf(" %d",&k);
            PREDECESSOR(t,k);
            break;
        case 'i':
            INORDER(t);
            print("\n");
            break;
        case 'p':
            PREORDER(t);
            print("\n");
            break;
        case 't':
            POSTORDER(t);
            print("\n");
            break;
        case 'e':
            break;
        }
    }
    return 0;
}