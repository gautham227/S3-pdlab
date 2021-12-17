//done by gautham on 5/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cnt=1;//global variable for counting the no of recursive calls made

//recursive binary search function
int Binary_Search(int list[],int n,int l,int r){
    int mid=(l+r)/2;
    // here to find the first element we also add the condition that the element before that shd not be equal to that value
    if (list[mid]==n && list[mid-1]<n){
        return mid;
    }
    else if (l>=r){
        return -1;
    }
    else{
        cnt++;
        if (list[mid]>=n){
            Binary_Search(list,n,l,mid-1);
        }
        else{
            Binary_Search(list,n,mid+1,r);
        }
    }
}

int main(){
    int l;
    scanf("%d",&l);
    int list[l];
    for (int i=0;i<l;i++){
        scanf("%d",&list[i]);
    }
    int n;
    scanf("%d",&n);
    int ans=Binary_Search(list,n,0,l-1);
    printf("%d\n",ans);
    printf("%d\n",cnt);
    return 0;
}