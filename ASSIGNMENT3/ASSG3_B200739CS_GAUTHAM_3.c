//done by gautham on 5/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//recursive binary search
int Binary_Search(int list[],int n,int l,int r){
    if (l>r){
        return 0;
    }
    int mid=(l+r)/2;
    if (n==list[mid]){
        return 1;
    }
    else if(list[mid]>n){
        return(Binary_Search(list,n,mid+1,r));
    }
    else if(list[mid]<n){
        return (Binary_Search(list,n,l,mid-1));
    }
}

int main(){
    int l1,l2;
    scanf("%d",&l1);
    scanf("%d",&l2);
    int list1[l1],list2[l2];
    for (int i=0;i<l1;i++){
        scanf("%d",&list1[i]);
    }
    for (int i=0;i<l2;i++){
        scanf("%d",&list2[i]);
    }
    for (int i=0;i<l1;i++){
        // checking if an element in l1 is there in l2 using binary search
        if (Binary_Search(list2,list1[i],0,l1-1)){
            printf("%d ",list1[i]);
        }
    }
    return 0;
}