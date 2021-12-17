//coded by gautham on 13/8
#include <stdio.h>
#include <math.h>

int main(){
    int n,num,rnum=0;
    scanf("%d", &n);
    num =n;
    while(n>0){
        int rem=n%10; // to extract the last digit of the of the n
        n=n/10;
        rnum=(rnum*10)+rem;
    }
    // a number will ne paliandrome if the no itself and the no obtained by reversing the digits are same
    if (num==rnum){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}