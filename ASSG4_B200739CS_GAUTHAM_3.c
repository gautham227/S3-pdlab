//done by gautham on 30/9
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct amoeba{
    char amoeba_Name[21];
    int amoeba_size;
};

void swap(struct amoeba* arr,int a,int b){
    struct amoeba temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify(struct amoeba* arr,int i,int larr){
    int largest=i;
    int lele=2*i+1;
    int rele=2*i+2;
    if(lele<larr && arr[lele].amoeba_size>arr[largest].amoeba_size){
        largest=lele;
    }
    if (rele<larr && arr[rele].amoeba_size>arr[largest].amoeba_size){
        largest=rele;
    }
    if (largest!=i){
        swap(arr,i,largest);
        heapify(arr,largest,larr);
    }
}

void mhp(struct amoeba* arr,int n){
    for (int i = (n)/2-1; i >= 0; i--)
    {
        heapify(arr,i,n);
    }
}

struct amoeba* srtname(struct amoeba* arr,int n){
    for(int i=1;i<n;i++){
        if (arr[0].amoeba_size==arr[i].amoeba_size && arr[i].amoeba_Name<arr[0].amoeba_Name){
            swap(arr,0,i);
        }
    }
    return arr;
}

struct amoeba READ(struct amoeba ele){
    scanf("%s ",&ele.amoeba_Name);
    int k;
    scanf("%d",&k);
    ele.amoeba_size=k*(-1);
    return ele;
}

struct amoeba* INSERT(struct amoeba* arr,struct amoeba ele,int n){
    strcpy(arr[n].amoeba_Name,ele.amoeba_Name);
    arr[n].amoeba_size=ele.amoeba_size;
    return arr;
}

struct amoeba* hpinsert(struct amoeba* arr,struct amoeba ele,int len){
    strcpy(arr[len].amoeba_Name,ele.amoeba_Name);
    arr[len].amoeba_size=ele.amoeba_size;
    int i=len;
    while(i>0 && arr[i/2].amoeba_size<arr[i].amoeba_size){
        swap(arr,i,i/2);
        i=i/2;
    }
    return arr;
}

struct amoeba* hpdelete(struct amoeba* arr,int len){
    swap(arr,0,len-1);
    heapify(arr,0,len-1);
    srtname(arr,len-1);
    return arr;
}

struct amoeba* COMBINE(struct amoeba* arr,int n){
    struct amoeba ans;
    while(n!=1){
        strcpy(ans.amoeba_Name,arr[0].amoeba_Name);
        ans.amoeba_size=arr[0].amoeba_size;
        printf("%s ",arr[0].amoeba_Name);
        hpdelete(arr,n);
        n--;
        ans.amoeba_size=ans.amoeba_size+arr[0].amoeba_size;
        printf("%s ",arr[0].amoeba_Name);
        hpdelete(arr,n);
        n--;
        hpinsert(arr,ans,n);
        n++;
        printf("%d",ans.amoeba_size*(-1));
        printf("\n");
    }
    printf("%s ",arr[0].amoeba_Name);
    printf("%d\n",arr[0].amoeba_size*(-1));
}
int main(){
    struct amoeba* arr;
    struct amoeba ele;
    int n;
    scanf("%d",&n);
    arr=(struct amoeba*)malloc(n*sizeof(struct amoeba));
    for(int i=0;i<n;i++){
        ele=READ(ele);
        arr=INSERT(arr,ele,i);
    }
    mhp(arr,n);
    arr=srtname(arr,n);
    COMBINE(arr,n);
    return 0;
}