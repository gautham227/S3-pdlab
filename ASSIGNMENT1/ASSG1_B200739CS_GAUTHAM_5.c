//coded by gautham on 23/8
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int merlist[n1+n2];
    int s=1;
    int *list1 = (int*)malloc(s*sizeof(int));
    for (int i=0;i<n1+n2;i++){ // creating a merged list
        int k=0;
        scanf("%d",&k);
        merlist[i]=k; 
    }
    for(int i=0;i<n1+n2;i++){
        int k=merlist[i];
        int cnt=1; // no of k in the list 
        merlist[i]=-10000; //assigning -10000<-1000 so that they will never be executed again
        if (k==-10000){ // skips already considerd values
            continue;
        }
        else{
            for(int j=i+1;j<n1+n2;j++){
                if (merlist[j]==k){
                    merlist[j]=-10000;
                    cnt++;
                }
            }
            if (cnt==1){
                list1[s-1]=k;
                s++;
                list1= (int*)realloc(list1,s); //increasing size of list1 by1
            }
            else{
                for(int j=0;j<cnt;j++){
                    printf("%d ",k);
                }
            }
        }
    }
    for(int i=0;i<s-1;i++){ //<s-1 because value of s is 1 greater than no of elements
        printf("%d ",list1[i]);
    }
    return 0;
}