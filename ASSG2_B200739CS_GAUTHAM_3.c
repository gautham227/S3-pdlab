//done by gautham on 30/8
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//function to find length of string
int length(char a[]){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}

int check(char a[],char b[],int n,int len_s){ //checks whether a[n:n+len_s] is same as str b
    for (int i=0;i<len_s;i++){
        if (a[n+i]!=b[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    char main_str[100000],sub_str[100000];
    scanf("%s",main_str);
    scanf("%s",sub_str);
    int len_m,len_s;
    len_m=length(main_str);
    len_s=length(sub_str);
    int index[len_m];  // an array which has value 1 corresponding element in main_str has to be printed
    for(int i=0;i<len_m;i++){
        index[i]=1; //initialising all values to 0
    }
    for (int i=0;i<=len_m-len_s;i++){
        if (check(main_str,sub_str,i,len_s)==0){
            for (int j=i;j<i+len_s;j++){
                index[j]=0; //makes element 0 which indicates corresponding element in main_str will not be printed
            }
        }
    }
    for (int i=0;i<len_m;i++){
        if (index[i]){
            printf("%c",main_str[i]);
        }
    }
    return 0;
}