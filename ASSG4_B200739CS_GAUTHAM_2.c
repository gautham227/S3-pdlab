//done by gautham on 30/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct S{
    int student_id;
    char student_name[21];
    int rank;
};

void swap(struct S* arr,int a,int b){
    struct S temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(struct S* arr,int i,int larr){
    int largest=i;
    int lele=2*i+1;
    int rele=2*i+2;
    if(lele<larr && arr[lele].rank>arr[largest].rank){
        largest=lele;
    }
    if (rele<larr && arr[rele].rank>arr[largest].rank){
        largest=rele;
    }
    if (largest!=i){
        swap(arr,i,largest);
        heapify(arr,largest,larr);
    }
}

void mhp(struct S* arr,int n){
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr,i,n);
    }
}

struct S* ENTER(struct S* arr,int len){
    arr=(struct S*)realloc(arr,(len+1)*sizeof(struct S));
    scanf("%d",&arr[len].student_id);
    scanf("%s",&arr[len].student_name);
    int k;
    scanf("%d",&k);
    arr[len].rank=k*(-1);
    mhp(arr,len+1);
    return arr;
}

int main(){
    struct S* arr;
    int len=0;
    arr=(struct S*)malloc(sizeof(struct S));
    char c='a';
    while(c!='t'){
        scanf("%c",&c);
        switch (c)
        {
        case 'e':
            arr=ENTER(arr,len);
            len++;
            break;
        // case 'i':
        //     INTERVIEW(arr);
        //     break;
        // case 'l':
        //     LIST(arr);
        //     break;
        case 't':
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i].student_id);
        printf("%s ",arr[i].student_name);
        printf("%d ",arr[i].rank);
    }
    
}