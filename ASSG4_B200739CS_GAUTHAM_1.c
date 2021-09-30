//done by gautham on 30/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int size(int arr[]){
    int s=0;
    while(arr[s]!=10001){
        s++;
    }
    return s;
}

void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(int arr[],int i,int larr){
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

void mhp(int arr[],int n){
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr,i,n);
    }
}

void heapsort(int arr[],int n){
    mhp(arr,n);
    for(int i=n-1;i>-1;i--){
        swap(arr,0,i);
        heapify(arr,0,i);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        arr[i]=k;
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}