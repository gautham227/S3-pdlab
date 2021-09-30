//done by gautham on 9/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

void gift(int arr[],int spl[],int l,int r,int k,int x){
    if (l==r){
        printf("%d ",k);
        printf("%d",arr[l]);
        printf("\n");
        if (arr[l]==x){
            spl[k-1]=1;
        }
    }
    else{
        printf("%d ",k);
        for (int i=l;i<=r;i++){
            printf("%d ",arr[i]);
            if (arr[i]==x){
                spl[k-1]=1;
            }
        }
        printf("\n");
        int mid=(l+r)/2;
        int u=2*k;
        gift(arr,spl,l,mid,u,x);
        gift(arr,spl,mid+1,r,u+1,x);
    }

}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        int g;
        scanf("%d",&g);
        arr[i]=g;
    }
    int x;
    scanf("%d",&x);
    int spl[100000];
    for (int i=0;i<100000;i++){
        spl[i]=0;
    }
    gift(arr,spl,0,n-1,1,x);
    int c=0;
    for (int i=0;i<100000;i++){
        if (spl[i]==1){
            printf("%d ",i+1);
            c++;
        }
    }
    printf("\n");
    int ans=no_cmp(n);
    printf("%d",ans+n+c);
    return 0;
}