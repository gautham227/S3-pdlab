// made by gautham on 6th nov
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct stac{
    char n;
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

stack CREATE_NODE(char k){
    stack x;
    x=(stack)malloc(sizeof(struct stac));
    x->n=k;
    x->next=NULL;
    return x;
}

void PUSH(sll s,char n){
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

char POP(sll s){
    bool x=STACK_EMPTY(s);
    if (x==true){
        return '0';
    }
    stack present;
    char b=s->head->n;
    present=s->head;
    if (present->next==NULL){
        s->head=NULL;
        return b;
    }
    s->head=present->next;
    return b;
}

int priority(char x){
    if (x=='+' || x=='-'){
        return 2;
    }
    else if(x=='*' || x=='/'){
        return 3;
    }
    else if(x=='('){
        return 1;
    }
    else if(x==')'){
        return 4;
    }
    return 0;
}

int TOP(sll s){
    bool x=STACK_EMPTY(s);
    if (x==true){
        return -1;
    }
    else{
        return priority(s->head->n);
    }
}

void INFIX_TO_POSTFIX(char* e){
    char post[strlen(e)];
    sll s;
    s=(sll)malloc(sizeof(struct ll));
    for(int i=0;i<strlen(e);i++){
        char w=e[i];
        if(w>='a' && w<='z'){
            printf("%c",w);
        }
        else if(w=='('){
            PUSH(s,w);
        }
        else if(w==')'){
            while(STACK_EMPTY(s)==false && s->head->n!='('){
                char u=POP(s);
                printf("%c",u);
            }
            POP(s);
        }
        else{
            int p=priority(w);
            while(STACK_EMPTY(s)==false && p<=TOP(s)){
                char u=POP(s);
                printf("%c",u);
            }
            PUSH(s,w);
        }
    }
    while(STACK_EMPTY(s)==false){
        char u=POP(s);
        printf("%c",u);
    }
}

int main(){
    char arr[510];
    scanf("%s",&arr);
    INFIX_TO_POSTFIX(arr);
    return 0;
}