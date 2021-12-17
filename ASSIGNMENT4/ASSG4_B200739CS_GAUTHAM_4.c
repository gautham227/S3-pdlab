//done by gautham on 1/10
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(int* arr,int i,int larr){
    int largest=i;
    int lele=2*i+1;
    int rele=2*i+2;
    if(lele<larr && arr[lele]>arr[largest]){
        largest=lele;
    }
    if (rele<larr && arr[rele]>arr[largest]){
        largest=rele;
    }
    if (largest!=i){
        swap(arr,i,largest);
        heapify(arr,largest,larr);
    }
}

void mhp(int* arr,int* n){
    for (int i = (*n)/2-1; i >= 0; i--){
        heapify(arr,i,*n);
    }
}

int * INSERT_PATIENT(int* arr,int n,int k){
    arr=(int*)realloc(arr,(n+1)*sizeof(int));
    arr[n]=k*(-1);
    int i=n+1;
    mhp(arr, &i);
    return arr;
}

int * EXTRACT_NEXT_PATIENT(int *arr,int* n){
    if (*n==0){
        printf("%d\n",-1);
    }
    else{
        printf("%d\n",arr[0]*(-1));
        arr[0]=arr[*n-1];
        (*n)--;
        heapify(arr,0,*n);
    }
    return arr;
}

void GET_NEXT_PATIENT(int *arr){
    printf("%d\n",arr[0]*(-1));
}

int* CHANGE_TOKEN_NUMBER(int* arr,int k,int x,int n){
    int ind;
    for(int i=0;i<n;i++){
        if (arr[i]==k){
            arr[i]=x;
            ind=i;
            break;
        }
    }
    while(ind>0 && arr[ind/2]<arr[ind]){
        swap(arr,ind/2,ind);
        ind=ind/2;
    }
    return arr;
}

void DISPLAY_QUEUE(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]*(-1));
    }
    printf("\n");
}

int main(){
    int* arr;
    arr=(int*)malloc(sizeof(int));
    int n=0;
    char c='a';
    while (c!='s'){
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            int u;
            scanf("%d",&u);
            arr=INSERT_PATIENT(arr,n,u);
            n++;
            break;
        case 'e':
            arr=EXTRACT_NEXT_PATIENT(arr,&n);
            break;
        case 'm':
            GET_NEXT_PATIENT(arr);
            break;
        case 'c':
            int k,x;
            scanf("%d",&k);
            scanf("%d",&x);
            arr=CHANGE_TOKEN_NUMBER(arr,(-1)*k,(-1)*x,n);
            break;
        case 'd':
            DISPLAY_QUEUE(arr,n);
            break;
        case 's':
            break;
        }
    }
    return 0;
}