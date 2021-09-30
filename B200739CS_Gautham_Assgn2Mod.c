//done by gautham on 2/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int Compare(char str1[],char str2[]){
    int i=0,f=0;
    while (str1[i]!='\0' && str2[i]!='\0'){
        if (str1[i]!=str2[i]){
            if (str1[i]>str2[i]){
                f=1;
            }
            break;
        }
        i++;
    }
    if (i==strlen(str1) || i==strlen(str2)){
        if (i==strlen(str1)){
            return 0;
        }
        else{
            return 1;
        }
    }
    if (f==0){
        return 0;
    }
    else{
        return 1;
    }
}

void Insertion_Sort_Lex(char a[][10000],int n){
    char p[10000];
    for (int i=1;i<n;i++){
        strcpy(p,a[i]);
        int j=i-1;
        while (j>=0 && Compare(a[j],p)==1){
            strcpy(a[j+1],a[j]);
            j--;
        }
        strcpy(a[j+1],p);
    }
}

int Sum_ASSCI(char a[]){
    int s=0;
    for(int i=0;i<strlen(a);i++){
        s=s+(int)a[i];
    }
    return s;
}

int main(){
    int n;
    scanf("%d",&n);
    char allstr[n][10000];
    for (int i=0;i<n;i++){
        scanf("%s",allstr[i]);
    }
    Insertion_Sort_Lex(allstr,n);
    int f=0;
    for (int i=0;i<n;i++){
        printf("%s ",allstr[i]);
    }
    printf("\n");
    for (int i=0;i<n;i++){
        if (Sum_ASSCI(allstr[i])%n==0){
            f=1;
            printf("%d ",i);
        }
    }
    if (f==0){
        printf("%d",-1);
    }
}