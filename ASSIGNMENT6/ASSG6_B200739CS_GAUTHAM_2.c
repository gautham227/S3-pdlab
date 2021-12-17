//made by gautham on 31st oct
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

struct nod{
    int no;
    struct nod* next;
};
typedef struct nod* node;

struct ll{
    node head;
    node tail;
};
typedef struct ll* queue;

node CREATE_NODE(int k){
    node x;
    x=(node)malloc(sizeof(struct nod));
    x->next=NULL;
    x->no=k;
    return x;
}

bool QUEUE_EMPTY(queue q){
    if(q->head==NULL){
        return true;
    }
    else{
        return false;
    }
}

void ENQUEUE(queue q,node k){
    int n;
    scanf(" %d",&n);
    node y=CREATE_NODE(n);
    if (q->head==NULL){
        q->head=y;
        q->tail=y;
    }
    else{
        q->tail->next=y;
        q->tail=y;
    }
    return;
}

void DEQUEUE(queue q){
    bool b=QUEUE_EMPTY(q);
    if (b==true){
        printf("%d\n",-1);
        return;
    }
    if(q->head->next==NULL){
        printf("%d\n",q->head->no);
        q->head=NULL;
        q->tail=NULL;
    }
    else{
        printf("%d\n",q->head->no);
        q->head=q->head->next;
    }
    return;
}

int main(){
    queue q;
    q=(queue)malloc(sizeof(struct ll));
    char c='a';
    bool u;
    node x;
    while(c!='t'){
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            ENQUEUE(q,x);
            break;
        case 'd':
            DEQUEUE(q);
            break;
        case 'e':
            u=QUEUE_EMPTY(q);
            if (u==true){
                printf("%d\n",-1);
            }
            else{
                printf("%d\n",1);
            }
            break;
        case 't':
            break;
        }
    }
    return 0;
}