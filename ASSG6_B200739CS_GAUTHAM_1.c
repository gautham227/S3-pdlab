// made by gautham on 31st oct
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct stac{
    int no;
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

stack CREATE_NODE(int k){
    stack x;
    x=(stack)malloc(sizeof(struct stac));
    x->no=k;
    x->next=NULL;
    return x;
}

void PUSH(sll s,stack x){
    int n;
    scanf(" %d",&n);
    stack t;
    t=CREATE_NODE(n);
    if(s->head!=NULL){
        t->next=s->head;
        s->head=t;
    }
    else{
        s->head=t;
    }
}

void POP(sll s){
    bool x=STACK_EMPTY(s);
    if (x==true){
        printf("%d\n",-1);
        return;
    }
    stack present;
    present=s->head;
    printf("%d\n",present->no);
    if (present->next==NULL){
        s->head=NULL;
        return;
    }
    s->head=present->next;
    return;
}



int main(){
    sll s;
    s=(sll)malloc(sizeof(struct ll));
    char c='a';
    stack x;
    bool u;
    while(c!='t'){
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            PUSH(s,x);
            break;
        case 'd':
            POP(s);
            break;
        case 'e':
            u=STACK_EMPTY(s);
            if(u==false){
                printf("%d\n",1);
            }
            else{
                printf("%d\n",-1);
            }
            break;
        case 't':
            break;
        }
    }
}