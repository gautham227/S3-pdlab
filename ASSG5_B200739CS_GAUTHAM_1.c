//done by gautham on 16/10
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int key;
    struct node* next;
};
typedef struct node* node;

struct sll{
    node head;
};
typedef struct sll* sll;

node CREATE_NODE(int k){
    node new;
    new=(node)malloc(sizeof(node));
    new->key=k;
    new->next=NULL;
    return new;
}

node LIST_SEARCH(sll ll,long int k){
    node present;
    present=ll->head;
    int flag=0;
    while(present!=NULL){
        if(present->key==k){
            flag=1;
            return present;
        }
        else{
            present=present->next;
        }
    }
    if(flag==0){
        return NULL;
    }
}

void LIST_INSERT_FRONT(sll ll,node x){
    node new;
    long int no;
    scanf("%ld",&no);
    new=CREATE_NODE(no);
    new->next=ll->head;
    ll->head=new;
}

void LIST_INSERT_TAIL(sll ll,node x){
    node new;
    long int no;
    scanf("%d",&no);
    new=CREATE_NODE(no);
    node present;
    present=ll->head;
    if(present==NULL){
        ll->head=new;
    }
    else{
        while(present->next!=NULL){
            present=present->next;
        }
        present->next=new;
    }
}

void LIST_INSERT_AFTER(sll ll,node x,node y){
    long int newkey;
    long int keybef;
    scanf("%ld",&newkey);
    scanf("%ld",&keybef);
    y=LIST_SEARCH(ll,keybef);
    if(y!=NULL){
        x=CREATE_NODE(newkey);
        x->next=y->next;
        y->next=x;
    }
    // else if(y==NULL){
    //     exit(0);
    // }
}

void LIST_INSERT_BEFORE(sll ll, node x, node y){
    long int newkey;
    long int keyaft;
    scanf("%ld",&newkey);
    scanf("%ld",&keyaft);
    y=LIST_SEARCH(ll,keyaft);
    node select; // node before y
    select=ll->head;
    while(select->next!=y){
        select=select->next;
    }
    x=CREATE_NODE(newkey);
    x->next=select->next;
    select->next=x;
}

void LIST_DELETE(sll ll,node x){
    long int key;
    scanf("%ld",&key);
    x=LIST_SEARCH(ll,key);
    if(x==ll->head){
        node present;
        present=ll->head;
        ll->head=present->next;
        printf("%ld\n",key);
    }
    else if (x==NULL){
        printf("%d\n",-1);
    }
    else{
        node present;
        present=ll->head;
        while(present!=NULL){
            if(present->next!=x){
                present=present->next;
            }
            else{
                present->next=x->next;
            }
            printf("%ld\n",key);
        }
    }

}

void LIST_DELETE_FIRST(sll ll){
    node present;
    present=ll->head;
    if(present==NULL){
        printf("-1\n");
    }
    else{
        printf("%ld",present->key);
        ll->head=present->next;
    }
}

void LIST_DELETE_LAST(sll ll){
    if(ll->head==NULL){
        printf("%d\n",-1);
    }
    else{
        node present;
        node prevele;
        present=ll->head;
        while(present->next->next!=NULL){
            present=present->next;
        }
        prevele=present;
        present=present->next;
        if(prevele!=NULL){
            prevele->next=NULL;
        }
        if(present==ll->head){
            ll->head=NULL;
        }
        long int ans=present->key;
        printf("%ld",ans);
    }
}

void PRINT_LIST(sll ll){
    node present;
    present=ll->head;
    while(present!=NULL){
        long int ans;
        ans=present->key;
        printf("%ld ",ans);
    }
    printf("\n");
}

int main(){
    sll ll;
    node x;
    node y;
    ll=(sll)malloc(sizeof(sll));
    char c='a';
    while(c!='e'){
        scanf("%c",&c);
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
            LIST_DELETE_FIRST(ll);
            break;
        case 'l':
            LIST_DELETE_LAST(ll);
            break;
        case 'p':
            PRINT_LIST(ll);
            break;
        case 'e':
            break;
        }
    }
    return 0;
}