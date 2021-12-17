//done by gautham on 27/8
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int non_dec_no(int n){
    int last_no,pre_no;
    last_no=n%10;
    n=n/10;
    while(n>0){
        pre_no=n%10; //the present no
        if (pre_no>last_no){
            return 1;
        }
        last_no=pre_no; // in next iteration present no becomes the last no
        n=n/10;
    }
    return 0;
}

int main(){
    int t;
    int k=0; // to find if there in no nos in the required form
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if (non_dec_no(abs(n))==0){
            k=1;
            printf("%d ",n);
        }
    }
    if (k==0){ 
        printf("%d",-1); //printing -1 as no number is in the required form
    }
    return 0;
}