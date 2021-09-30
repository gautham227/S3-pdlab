//coded by gautham on 13/8
#include <stdio.h>
#include <math.h>

int PALIANDROME(int n){
    int num=n,rnum=0;
    while(n>0){
        int rem=n%10; // to extract the last digit of the of the n
        n=n/10;
        rnum=(rnum*10)+rem;
    }
    // a number will be paliandrome if the no itself and the no obtained by reversing the digits are same
    if (num==rnum){
        return 1;
    }
    else{
        return 2;
    }
}

int main(){
    int k,cnt=0;
    scanf("%d", &k);
    int arr_no[k];
    while (k--){
        int n;
        scanf("%d",&n);
        int b=PALIANDROME(n);
        if (b==1){
            cnt++;
        }
        else{
            continue;
        }
    }
    printf("%d",cnt);
    return 0;
}