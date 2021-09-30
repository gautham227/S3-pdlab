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

int heapify(int arr[],int i,int larr,int cnt){
    int largest=i;
    int lele=2*i+1;
    int rele=2*i+2;
    if(lele<larr && arr[lele]>arr[largest]){
        largest=lele;
    }
    if (rele<larr && arr[rele]>arr[largest]){
        largest=rele;
    }
    cnt=cnt+2;
    if (largest!=i){
        swap(arr,i,largest);
        heapify(arr,largest,larr,cnt);
    }
    return cnt;
}

int mhp(int arr[],int n,int cnt){
    for (int i = n/2-1; i >= 0; i--)
    {
        cnt=cnt+heapify(arr,i,n,0);
    }
    return cnt;
}

int heapsort(int arr[],int n){
    int cnt=mhp(arr,n,cnt);
    for(int i=n-1;i>-1;i--){
        swap(arr,0,i);
        cnt=heapify(arr,0,i,cnt);
    }
    return cnt;
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
    int cnt=heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d",cnt);
    return 0;
}