//done by gautham on 16/10
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct nod{
    long int key;
    struct nod* next;
    struct nod* prev;
};
typedef struct nod* node;

struct dl{
    node head;
};
typedef struct dl* dll;

node CREATE_NODE(long int k){
    node ne;
    ne=(node)malloc(sizeof(node));
    ne->key=k;
    ne->next=NULL;
    ne->prev=NULL;
    return ne;
}

node LIST_SEARCH(dll ll,long int k){
    node present;
    present=ll->head;
    int flag=0;
    while(present!=NULL){
        if(present->key==k){
            flag=1;
            return present;
            break;
        }
        else{
            present=present->next;
        }
    }
    if(flag==0){
        return NULL;
    }
    else{
        return present;
    }
}

void LIST_INSERT_FRONT(dll ll,node x){
    node ne;
    long int no;
    scanf("%ld",&no);
    ne=CREATE_NODE(no);
    ne->next=ll->head;
    ne->prev=NULL;
    if(ll->head!=NULL){
        ll->head->prev=x;
    }
    ll->head=ne;
}

void LIST_INSERT_TAIL(dll ll,node x){
    node ne;
    long int no;
    scanf("%ld",&no);
    ne=CREATE_NODE(no);
    node present;
    present=ll->head;
    if(present==NULL){
        ll->head=ne;
    }
    else{
        while(present->next!=NULL){
            present=present->next;
        }
        present->next=ne;
        ne->next=NULL;
        ne->prev=present;
    }
}

void LIST_INSERT_AFTER(dll ll,node x,node y){
    long int nekey;
    long int keybef;
    scanf("%ld ",&nekey);
    scanf("%ld",&keybef);
    y=LIST_SEARCH(ll,keybef);
    if(y!=NULL){
        x=CREATE_NODE(nekey);
        x->next=y->next;
        x->prev=y;
        if(y->next!=NULL){
            y->next->prev=x;
        }
        y->next=x;
    }
    else{
        exit(0);
    }
}

void LIST_INSERT_BEFORE(dll ll, node x, node y){
    long int nekey;
    long int keyaft;
    scanf("%ld ",&nekey);
    scanf("%ld",&keyaft);
    y=LIST_SEARCH(ll,keyaft);
    // node select; // node before y
    // select=ll->head;
    // while(select->next!=y){
    //     select=select->next;
    // }
    // x=CREATE_NODE(nekey);
    // x->next=select->next;
    // select->next=x;
    // x->prev=select;
    // select->next->prev=x;
    if(y==NULL){
        exit(0);
    }
    node select; // node before y
    // select=ll->head;
    // while(select->next!=y){
    //     select=select->next;
    // }
    x=CREATE_NODE(nekey);
    if(y!=ll->head){
        x->next=y;
        x->prev=y->prev;
        y->prev->next=x;
        y->prev=x;
    }
    else{
        x->next=y;
        y->prev=x;
        x->prev=NULL;
        ll->head=x;
    }
}

void LIST_DELETE(dll ll,node x){
    long int key;
    scanf("%ld",&key);
    x=LIST_SEARCH(ll,key);
    if (x==NULL){
        printf("Not Found\n");
    }
    else if(x->next==NULL){
        printf("NULL\n");
    }
    else if(x!=ll->head){
        node present;
        present=ll->head;
        while(present!=NULL){
            if(present->next!=x){
                present=present->next;
            }
            else{
                present->next=x->next;
                printf("%c\n",present->next->key);
            }
        }
    }
    else{
        node present;
        present=ll->head;
        ll->head=present->next;
        printf("%c\n",ll->head->key);
    }
}


int main(){
    dll ll;
    node x;
    node y;
    ll=(dll)malloc(sizeof(dll));
    char c='a';
    while(c!='e'){
        scanf("%c ",&c);
        switch (c)
        {
        case 'f':
            LIST_INSERT_FRONT(ll,x);
            break;
        case 't':
            LIST_INSERT_TAIL(ll,x);
            break;
        case 'a':
            LIST_INSERT_AFTER(ll,x,y);
            break;
        case 'b':
            LIST_INSERT_BEFORE(ll,x,y);
            break;
        case 'd':
            LIST_DELETE(ll,x);
            break;
        case 'i':
            LIST_DELETE_INITIAL(ll);
            break;
        case 'l':
            LIST_DELETE_LAST(ll);
            break;
        case 'r':
            int k;
            scanf("%d",&k);
            PRINT_REVERSE(ll,k);
            break;
        case 'e':
            break;
        }
    }
    return 0;
}
