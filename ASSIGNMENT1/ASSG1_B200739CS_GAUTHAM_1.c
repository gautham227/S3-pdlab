//coded by gautham on 22/8
#include <stdio.h>
#include <math.h>

int octtodec(int n){
    int s=0; // value in decimal
    int p=0; //power of 8
    while (n>0){
        int rem=n%10; // to get the last element
        s=s+rem* pow(8,p);
        p++; //increasing the pow
        n=n/10; //removing the last digit
    }
    return s;

}
int main(){
    
    int oct=0;
    scanf("%d",&oct);
    int ans=octtodec(oct);
    printf("%d", ans);
    return 0;
}