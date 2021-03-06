// made by gautham on 6th nov
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct stac{
    long int n;
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

stack CREATE_NODE(long int k){
    stack x;
    x=(stack)malloc(sizeof(struct stac));
    x->n=k;
    x->next=NULL;
    return x;
}

void PUSH(sll s,long int n){
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

long int POP(sll s){
    bool x=STACK_EMPTY(s);
    if (x==true){
        return '0';
    }
    stack present;
    long int b=s->head->n;
    present=s->head;
    if (present->next==NULL){
        s->head=NULL;
        return b;
    }
    s->head=present->next;
    return b;
}

sll EVALUATE_POSTFIX(char* e){
    sll s;
    s=(sll)malloc(sizeof(struct ll));
    int i=0;
    while(i<strlen(e)){
        if(e[i]=='+'){
            long int a=POP(s);
            long int b=POP(s);
            PUSH(s,a+b);
        }
        else if(e[i]=='-'){
            long int a=POP(s);
            long int b=POP(s);
            PUSH(s,b-a);
        }
        else if(e[i]=='*'){
            long int a=POP(s);
            long int b=POP(s);
            PUSH(s,a*b);
        }
        else if(e[i]=='/'){
            long int a=POP(s);
            long int b=POP(s);
            PUSH(s,b/a);
        }
        else if(e[i]>='0' && e[i]<='9'){
            long int u=0;
            while(e[i]!=' '){
                u=u*10+(e[i]-48);
                i++;
            }
            PUSH(s,u);
        }
        i++;
    }
    return s;
}

int main(){
    char e[1000];
    fgets(e,1000,stdin);
    sll s=EVALUATE_POSTFIX(e);
    printf("%d\n",s->head->n);
    return 0;
}