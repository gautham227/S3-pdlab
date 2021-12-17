//coded by gautham on 22/8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void CONVERT(int n, int bin[]){
    for(int i=15;i>-1;i--){
        int val=pow(2,i);
        if (n>=val){
            n=n-val;
            bin[15-i]=1;
        }
        else{
            bin[15-i]=0;
        }
    }
}

int main(){
    int dec,k;
    int bin[16];
    scanf("%d %d",&dec,&k);
    CONVERT(dec,bin);
    // after this the array bin contains each element of dec converted to binary
    
    for(int i=0;i<16;i++){
        printf("%d",bin[i]);
    }
    printf("\n");
    
    //to print result after left shift by k units
    
    for (int i=k;i<16;i++){
        printf("%d",bin[i]);
    }
    
    for (int i=0;i<k;i++){
        printf("%d",bin[i]);
    }
    printf("\n");
    
    //to print result after right shift by k units
    
    for (int i=0;i<k;i++){
        printf("%d",bin[i+16-k]);
    }
    
    for (int i=0;i<16-k;i++){
        printf("%d",bin[i]);
    }
    
    return 0;
}