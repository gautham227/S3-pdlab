//done by gautham on 27/8
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int u = *a; // u is used to temporarily hold the list[i]
    *a = *b;
    *b = u;
}

void Sort(int list[],int n){
    for (int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if (list[j]<list[i]){
                swap(&list[i],&list[j]);
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int list[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&list[i]);
    }
    Sort(list,n); // sorting the array
    int smax=0,smin=0;
    // smax-smin of n-m elements is same as smax-smin of m elements
    // smin can be obtained by taking sum of first m values of sorted array
    for (int i = 0; i < m; i++) {
        smin=smin+list[i];
    }
    // smax can be obtained by taking sum of last m values of sorted array
    for (int i = n-1; i >= n-m;i--){
      smax=smax+list[i];
    }
    printf("%d",smax-smin);
    return 0;
}