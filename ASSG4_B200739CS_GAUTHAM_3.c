#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
    struct amoeba{
        char amoeba_name[25];
        int amoeba_size;
    };


    
    void Compare(struct amoeba* A, int n){
    struct amoeba temp;
        for(int i=1;i<=n;i++)
        {
        if(A[0].amoeba_size==A[i].amoeba_size && (strcmp(A[0].amoeba_name,A[i].amoeba_name))>0){
        temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        }
    }
    }

    void max_heapify(struct amoeba* A,int i,int n){
    int l,r;
    int lex_check=0;
    int lex_check1=0;
    int smallest=i;
    l=(2*i)+1;
    r=(2*i)+2;
    
    if(l<=n && A[l].amoeba_size>A[i].amoeba_size) 
    {
    smallest=l;

    }
    if(r<=n && A[r].amoeba_size>A[smallest].amoeba_size)  
    {
        smallest=r;
    }
    
    struct amoeba temp;

    if(smallest!=i){
        temp=A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        max_heapify(A,smallest,n);
        }

    }
    
    void build_heap(struct amoeba*A,int n)
    {
    for(int i=(n/2);i>=0;i--)
    {
        max_heapify(A,i,n);
    }
    }
    
    void heap_sort(struct amoeba*A, int n){
        int n1=n;
        int heapsize=n;
        build_heap(A,n);
        
        struct amoeba temp;
        int j;
        for(j=n1;j>=1;j--)
        {
        temp=A[j];
        A[j]=A[0];
        A[0]=temp;
        heapsize--;
        max_heapify(A,0,heapsize);
        }

    }

    void insert(struct amoeba* A,int count){
        heap_sort(A,count);
        Compare(A,count);
        
    }

    void read(struct amoeba* A,int count){
        for(int i=0;i<=count;i++)
        {
            scanf("%s",(A+i)->amoeba_name);
            scanf("%d",&(A+i)->amoeba_size);
            
        }
    }

    void deleteelement(struct amoeba* A,int len){
        struct amoeba temp;
        temp=A[0];
        A[0]=A[len];
        A[len]=temp;
        heap_sort(A,len-1);
        Compare(A,len-1);
    } 
    
    void appendelement(struct amoeba* A,struct amoeba xyz, int len){
        strcpy(A[len].amoeba_name,xyz.amoeba_name);
        A[len].amoeba_size=xyz.amoeba_size;
        heap_sort(A,len);
        Compare(A,len);
    }

    void combine(struct amoeba* A, int n)
    {   
        while(n>0){
            struct amoeba rithika;
            strcpy(rithika.amoeba_name,A[0].amoeba_name);
            rithika.amoeba_size=A[0].amoeba_size;
            printf("%s ",A[0]);
            deleteelement(A,n);
            n--;
            printf("%s ",A[0]);
            rithika.amoeba_size=rithika.amoeba_size+A[0].amoeba_size;
            deleteelement(A,n);
            n--;
            appendelement(A,rithika,n+1);
            n++;
            heap_sort(A,n);
            Compare(A,n);
            printf("%d",rithika.amoeba_size);
            printf("\n");
        }
        printf("%s ",A[0].amoeba_name);
        printf("%d\n",A[0].amoeba_size);
    }
    int main()
    {
        int n;
        scanf("%d",&n);
        struct amoeba* Array_of_amoeba;
        Array_of_amoeba = (struct amoeba*)malloc(n * sizeof(struct amoeba));
        read(Array_of_amoeba,n-1);
        heap_sort(Array_of_amoeba,n-1);
        Compare(Array_of_amoeba,n-1);
        combine(Array_of_amoeba,n-1);
        return 0;
    }