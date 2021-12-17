//done by gautham on 27/8
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int t;
    scanf("%d",&t);
    int n0=0,np=0,nn=-10000,s=0;
    // n0 is the no of zeros
    // np is the no of positive nos
    // nn is the negative no having smallest absolute value
    // s represents max sum
    for(int i=0;i<t;i++){
        int k;
        scanf("%d",&k);
        if (k>0){
            np++;
            s=s+k;
        }
        else if (k==0){
            n0++;
        }
        else{
            if (abs(k)<abs(nn)){
                nn=k;
            }
        }
    }
    if (np+n0>0){
        printf("%d %d",s,np+n0);
    }
    else{
        printf("%d %d",nn,1);
    }
    return 0;
}