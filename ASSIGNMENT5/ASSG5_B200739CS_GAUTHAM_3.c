//done by gautham on 17/10
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct stac{
    char* arr;
    int top;
    int size;
};
typedef struct stac* stack;

bool STACK_EMPTY(stack S){
    if(S->top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool STACK_FULL(stack S){
    int sz=S->size;
    if(S->top==sz-1){
        return true;
    }
    else{
        return false;
    }
}

void PUSH(stack S,char k){
    scanf(" %c",&k);
    if(STACK_FULL(S)==true){
        printf("%d\n",-1);
    }
    else{
        S->arr[S->top+1]=k;
        S->top=S->top+1;
    }
}

void POP(stack S){
    if(STACK_EMPTY(S)==true){
        printf("%d\n",-1);
    }
    else{
        char ans=S->arr[S->top];
        printf("%c\n",ans);
        S->top=S->top-1;
    }
}

void PEEK(stack S){
    if(STACK_EMPTY(S)==true){
        printf("%d\n",-1);
    }
    else{
        char ans=S->arr[S->top];
        printf("%c\n",ans);
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    stack s;
    s=(stack)malloc(sizeof(struct stac));
    s->arr=(char*)malloc(n*sizeof(char));
    s->size=n;
    s->top=-1;
    char c='a';
    char k;
    while(c!='t'){
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            PUSH(s,k);
            break;
        case 'd':
            POP(s);
            break;
        case 'p':
            PEEK(s);
            break;
        case 't':
            break;
        }
    }
    return 0;
}