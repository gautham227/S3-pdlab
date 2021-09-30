//coded by gautham on 22/8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char ul(char a){
    char u=a+32;
    return u;
}

char lu(char a){
    char l=a-32;
    return l;
}

int main(){
    int max=100000;
    char word[max];
    fgets(word,max,stdin);
    for(int i=0;i<sizeof(word)/sizeof(word[0]);i++){
        if (word[i]>='a' && word[i]<='z'){
            word[i]=lu(word[i]);
        }
        else if(word[i]>='A' && word[i]<='Z'){
            word[i]=ul(word[i]);
        }
    }
    printf("%s",word);
    return 0;

}