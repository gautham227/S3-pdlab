//done by gautham on 27/8
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//sorts the list in increasing order using insertion sort
int INSERTIONSORTAS(int list[]){
    int len=0;
    while(list[len]!=10000){
        len++;
    }
    int j,k;
    for (int i=1;i<len;i++){
        k=list[i];
        j=i-1;
        while(j>=0 && list[j]>k){
            list[j+1]=list[j];
            j--;
        }
        list[j+1]=k;
    }
    return 0;
}

//sorts the list in decreasing order using insertion sort
int INSERTIONSORTDS(int list[]){
    int len=0;
    while(list[len]!=10000){
        len++;
    }
    int j,k;
    for (int i=1;i<len;i++){
        k=list[i];
        j=i-1;
        while(j>=0 && list[j]<k){
            list[j+1]=list[j];
            j--;
        }
        list[j+1]=k;
    }
    return 0;
}

//prints the array
void PRINT(int list[]){
    int len=0;
    while(list[len]!=10000){
        len++;
    }
    for(int i=0;i<len;i++){
        printf("%d ",list[i]);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int r=t-(t/2); // no of even indexed nos
    int even_ind_nos[r+1],odd_ind_nos[t/2+1];
    int inde=0,indo=0;
    for (int i=0;i<t;i++)
    {
        if (i%2==0){
            scanf("%d",&even_ind_nos[inde]);
            inde++;
            
        }
        else{
            scanf("%d",&odd_ind_nos[indo]);
            indo++;
        }
    }
    even_ind_nos[inde]=10000;
    odd_ind_nos[indo]=10000;
    INSERTIONSORTAS(even_ind_nos);
    INSERTIONSORTDS(odd_ind_nos);
    PRINT(even_ind_nos);
    printf("\n");
    PRINT(odd_ind_nos);
    return 0;
}