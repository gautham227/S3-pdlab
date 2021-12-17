//coded by gautham on 22/8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    int list[n];

    //initialising the array
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        list[i]=k;
    }

    int no_rep=0; // to check if there is any element that is repeating

    for(int i=0;i<n;i++){
        //to not consider the values that have already been considered
        if (list[i]<-1000){
            continue;
        }

        else{
            int dig=list[i];
            int cnt=1; // counter no of times that value occurs
            list[i]=-10000; // assigning so that it will never be cosidered again
            for(int j=i+1;j<n;j++){
                if (list[j]==dig){
                    if (cnt==1){
                        printf("%d ",dig);
                        printf("%d ",i);
                        no_rep=1;
                    }
                    cnt++;
                    list[j]=-10000;
                    printf("%d ",j);
                }
            }
            if (cnt>1){
                printf("%d",cnt);
                printf("\n");
            }
        }
    }
    if (no_rep==0){
        printf("%d",-1);
    }
    return 0;
}