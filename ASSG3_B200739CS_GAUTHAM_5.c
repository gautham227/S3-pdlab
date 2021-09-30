//done by gautham on 5/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// for counting the no of comparisons
long long no_cmp(int n){
    long long cmp=0;
    // if no of elements =1 then there is no possibility of comparison
    for (int i=2;i<=n;i++){
        double lg=log(i)/log(2);
        int lgi=ceil(lg);
        cmp=cmp+1+lgi;
    }
    return cmp;
}

long long merge(int arr[],int l,int mid,int r){
    long long c_inv=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int larr[n1];
    int rarr[n2];
    for (int i = 0; i < n1; i++)
    {
        larr[i]=arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        rarr[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if (larr[i]<=rarr[j]){
            arr[k]=larr[i];
            k++;i++;
        }
        else{
            arr[k]=rarr[j];
            c_inv=c_inv+n1-i;
            k++;j++;
        }
    }
    while (i<n1)
    {
        arr[k]=larr[i];
        k++;i++;
    }
    while (j<n2)
    {
        arr[k]=rarr[j];
        k++;j++;
    }
    return c_inv;
}

//function to sort the array using merge sort
long long MS(int arr[],int l,int r){
    long long cnt_inv=0;
    if (l<r){
        int mid=(l+r)/2;
        cnt_inv=cnt_inv+MS(arr,l,mid);
        cnt_inv=cnt_inv+MS(arr,mid+1,r);
        cnt_inv=cnt_inv+ merge(arr,l,mid,r);
    }
    return cnt_inv;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    // to input the array
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d",&k);
        arr[i]=k;
    }
    long long ans=MS(arr,0,n-1); // gives the no of inversions to be done
    long long cnt_cmp=no_cmp(n); // gives no of comarisons
    printf("%d",ans);
    printf("\n");
    printf("%d",cnt_cmp);
    return 0;
}