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

void max_heapify(int arr[], int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if (left<n && arr[left]>arr[i]){
        largest=left;
    }
    if (right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if (largest!=i){
        swap(arr,i,largest);
        max_heapify(arr,largest,n);
    }
}

void bmh(int arr[]){
    int hsize=size(arr);
    for (int i=(((int)hsize)/2)-1;i>-1;i--)
    {
        max_heapify(arr,i,hsize);
    }
}

void heapsrt(int arr[]){
    bmh(arr);
    int sz=size(arr);
    for (int i = sz/2-1; i >= 0; i--)
    {
        swap(arr,0,i);
        max_heapify(arr,0,sz);
    }
    
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d",&k);
        arr[i]=k;
    }
    arr[n]=10001;
    heapsrt(arr);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}