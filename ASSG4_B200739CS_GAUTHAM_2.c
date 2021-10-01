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

void mhp(struct S* arr,int* n){
    for (int i = (*n)/2-1; i >= 0; i--)
    {
        heapify(arr,i,*n);
    }
}

struct S* ENTER(struct S* arr,int* len){
    arr=(struct S*)realloc(arr,((*len)+1)*sizeof(struct S));
    scanf("%d",&arr[*len].student_id);
    scanf("%s",&arr[*len].student_name);
    int k;
    scanf("%d",&k);
    arr[*len].rank=k*(-1);
    *len=*len+1;
    mhp(arr,len);
    return arr;
}

struct S* INTERVIEW(struct S* arr, int* len){
    if (*len==0){
        printf("%d\n",-1);
        return arr;
    }
    else{
        printf("%d ",arr[0].student_id);
        printf("%s\n",arr[0].student_name);
        swap(arr,0,*len-1);
        arr=(struct S*)realloc(arr,((*len)-1)*sizeof(struct S));
        *len=*len-1;
        heapify(arr,0,*len);
        return arr;
    }
}

void LIST(struct S* arr, int len){
    if (len==0){
        printf("%d\n",-1);
    }
    else{
        struct S* arr1;
        arr1=(struct S*)malloc(len*sizeof(struct S));
        for(int i=0;i<len;i++){
            arr1[i]=arr[i];
        }
        int len1=len;
        for(int i=0;i<len;i++){
            printf("%d ",arr1[0].student_id);
            swap(arr1,0,len1-1);
            len1=len1-1;
            heapify(arr1,0,len1);
        }
        printf("\n");
    }
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
            arr=ENTER(arr,&len);
            break;
        case 'i':
            arr=INTERVIEW(arr,&len);
            break;
        case 'l':
            LIST(arr,len);
            break;
        case 't':
            break;
        }
    }
    return 0;
}