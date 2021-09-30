//done by gautham on 5/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int merge(int arr[],int l,int mid,int r){
    int l1=mid-l+1,l2=r-mid;
    int larr[l1+1],rarr[l2+1];
    int c=0;
    for (int i=0;i<l1;i++){
        larr[i]=arr[l+i];
    }
    for (int i=0;i<l2;i++){
        rarr[i]=arr[mid+1+i];
    }
    int c1=0,c2=0;
    larr[l1]=10000;
    rarr[l2]=10008;
    for (int i=0;i<r-l+1;i++){
        c++;
        if (larr[c1]<=rarr[c2]){
            arr[l+i]=larr[c1];
            c1++;
        }
        else{
            arr[l+i]=rarr[c2];
            c2++;
        }
    }
    return c;
}

int MS(int arr[],int l,int r){
    int cnt=0;
    if (r>l){
        int mid=(l+r)/2;
        cnt=cnt+MS(arr,l,mid);
        cnt=cnt+MS(arr,mid+1,r);
        cnt=cnt+merge(arr,l,mid,r);
    }
    return cnt;
}

void print(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    //inputting the array
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d",&k);
        arr[i]=k;
    }
    //sorting the array
    int ans=MS(arr,0,n-1); // gives the no of comparisons
    print(arr,n);// printing all the elements of the array
    printf("\n");
    printf("%d",ans);
    return 0;
}