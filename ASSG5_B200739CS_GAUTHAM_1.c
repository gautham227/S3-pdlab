//done by gautham on 16/10
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct nod{
    char key;
    struct nod* next;
};
typedef struct nod* node;

struct sl{
    node head;
};
typedef struct sl* sll;

node CREATE_NODE(char k){
    node ne;
    ne=(node)malloc(sizeof(node));
    ne->key=k;
    ne->next=NULL;
    return ne;
}

node LIST_SEARCH(sll ll,char k){
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

void LIST_INSERT_FRONT(sll ll,node x){
    node ne;
    char no;
    scanf("%c",&no);
    ne=CREATE_NODE(no);
    ne->next=ll->head;
    ll->head=ne;
}

void LIST_INSERT_TAIL(sll ll,node x){
    node ne;
    char no;
    scanf("%c",&no);
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
    }
}

void LIST_INSERT_AFTER(sll ll,node x,node y){
    char nekey;
    char keybef;
    scanf("%c ",&nekey);
    scanf("%c",&keybef);
    y=LIST_SEARCH(ll,keybef);
    if(y!=NULL){
        x=CREATE_NODE(nekey);
        x->next=y->next;
        y->next=x;
    }
    else if(y==NULL){
        exit(0);
    }
}

void LIST_INSERT_BEFORE(sll ll, node x, node y){
    char nekey;
    char keyaft;
    scanf("%c ",&nekey);
    scanf("%c",&keyaft);
    y=LIST_SEARCH(ll,keyaft);
    node select; // node before y
    select=ll->head;
    while(select->next!=y){
        select=select->next;
    }
    if(y==NULL){
        exit(0);
    }
    x=CREATE_NODE(nekey);
    if(y!=ll->head){
        x->next=select->next;
        select->next=x;
    }
    else{
        x->next=y;
        ll->head=x;
    }
}

void LIST_DELETE(sll ll,node x){
    char key;
    scanf("%c",&key);
    x=LIST_SEARCH(ll,key);
    if (x==NULL){
        printf("%d\n",-1);
    }
    else if(x->next==NULL){
        printf("%d\n",-2);
        node present;
        node prevele;
        present=ll->head;
        if(present->key==key){
            ll->head=NULL;
            return;
        }
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

void LIST_DELETE_FIRST(sll ll){
    node present;
    present=ll->head;
    if(present==NULL){
        printf("-1\n");
    }
    else{
        printf("%c\n",present->key);
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
        char ans=present->key;
        printf("%c\n",ans);
    }
}

void PRINT_LIST(sll ll){
    node present;
    present=ll->head;
    while(present!=NULL){
        char ans;
        ans=present->key;
        printf("%c ",ans);
        present=present->next;
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