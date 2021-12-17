//coded by gautham on 22/8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Greatest_Common_Devisor(int ele1,int ele2){
    if (ele1%ele2==0){
        return ele2;
    }
    else{
        return Greatest_Common_Devisor(ele2,ele1%ele2);
    }
}

int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    if (abs(num1)>abs(num2)){
        int fin_ans;
        fin_ans=Greatest_Common_Devisor(abs(num1),abs(num2));
        printf("%d",fin_ans);
    }
    else{
        int fin_ans;
        fin_ans=Greatest_Common_Devisor(abs(num2),abs(num1));
        printf("%d",fin_ans);
    }
    return 0;
}