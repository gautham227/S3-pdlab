//done by gautham on 17/10
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct queu{
    char** arr;
    long int head;
    long int tail;
    long int size;
};
typedef struct queu* queue;

int QUEUE_EMPTY(queue Q){
    if(Q->head==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int QUEUE_FULL(queue Q){
    if((Q->tail==Q->head-1) || (Q->tail==Q->size-1 && Q->head==0) || (Q->size==0) ){
        return 1;
    }
    else{
        return 0;
    }
}

void ENQUEUE(queue Q, char s[]){
    if(QUEUE_FULL(Q)==true){
        printf("%d\n",-1);
        return;
    }
    else if(Q->head!=0 && Q->tail==Q->size-1){
        Q->tail=0;
        // Q->arr[Q->tail]=s;
        strcpy(Q->arr[Q->tail],s);
    }
    else if(Q->head!=-1){
        Q->tail=Q->tail+1;
        // Q->arr[Q->tail]=s;
        strcpy(Q->arr[Q->tail],s);
    }
    else{
        Q->head=0;
        Q->tail=0;
        // Q->arr[Q->tail]=s;
        strcpy(Q->arr[Q->tail],s);
    }
}

void DEQUEUE(queue Q){
    if(QUEUE_EMPTY(Q)==true){
        printf("%d\n",-1);
        return;
    }
    else if(Q->head==Q->size-1){
        printf("%s\n",Q->arr[Q->head]);
        Q->head=0;
    }
    else if(Q->tail==Q->head){
        printf("%s\n",Q->arr[Q->head]);
        Q->head=-1;
        Q->tail=-1;
    }
    else{
        printf("%s\n",Q->arr[Q->head]);
        Q->head=Q->head+1;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    n=n-1;
    queue q;
    q=(queue)malloc(sizeof(struct queu));
    q->arr=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        q->arr[i]=(char*)malloc(21*sizeof(char));
    }
    q->size=n;
    q->head=-1;
    char c='a';
    char s[21];
    while(c!='t'){
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            scanf(" %s",&s);
            ENQUEUE(q,s);
            break;
        case 'd':
            DEQUEUE(q);
            break;
        case 'f':
            if(QUEUE_FULL(q)==0){
                printf("%d\n",1);
            }
            else{
                printf("%d\n",-1);
            }
            break;
        case 'e':
            if(QUEUE_EMPTY(q)==0){
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
    return 0;
}