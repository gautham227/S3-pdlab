//done by gautham on 23/10
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct grap{
    int** arr;
};
typedef struct grap* graph;

//linked list
struct nod{
    int key1;
    int key2;
    struct nod* next;
};
typedef struct nod* node;

struct sl{
    node head;
};
typedef struct sl* sll;

node CREATE_NODE(int k1,int k2){
    node ne;
    ne=(node)malloc(sizeof(node));
    ne->key1=k1;
    ne->key2=k2;
    ne->next=NULL;
    return ne;
}

node LIST_SEARCH_LAST(sll ll,int k1,int k2){
    node present, ret;
    present=ll->head;
    int flag=0;
    while(present!=NULL){
        if(present->key1==k1 && present->key2==k2){
            flag=1;
            ret = present;
            present=present->next;
        }
        else{
            present=present->next;
        }
    }
    if(flag==0){
        return NULL;
    }
    else{
        return ret;
    }
}

node LIST_SEARCH_FRONT(sll ll,int k1,int k2){
    node present;
    present=ll->head;
    int flag=0;
    while(present!=NULL){
        if(present->key1==k1 && present->key2==k2){
            flag=1;
            return present;
            break;
        }
        else{
            present=present->next;
        }
    }
    if(flag==0){
        return NULL;
    }
    else{
        return present;
    }
}

node LIST_SEARCH_LOOPS(sll ll,int k1,int k2){
    node present;
    present=ll->head;
    int flag=0;
    while(present!=NULL){
        if((present->key1==k1 && present->key2==k2) && ( present->next==NULL||(present->next->key1!=k1 && present->next->key2!=k2))) {
            flag=1;
            return present;
            break;
        }
        else{
            present=present->next;
        }
    }
    if(flag==0){
        return NULL;
    }
    else{
        return present;
    }
}

void LIST_INSERT_FRONT(sll ll,int k1,int k2){
    node ne;
    ne=CREATE_NODE(k1,k2);
    ne->next=ll->head;
    ll->head=ne;
}

int LIST_INSERT_AFTER(sll ll,int k1,int k2, int n1,int n2){
    node y,x;
    y=LIST_SEARCH_FRONT(ll,k1,k2);
    if(y!=NULL){
        x=CREATE_NODE(n1,n2);
        x->next=y->next;
        y->next=x;
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}

int LIST_INSERT_AFTER_LOOPS(sll ll,int k1,int k2, int n1,int n2){
    node y,x;
    y=LIST_SEARCH_LOOPS(ll,k1,k2);
    if(y!=NULL){
        x=CREATE_NODE(n1,n2);
        x->next=y->next;
        y->next=x;
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}


void PRINT_LIST(sll ll){
    node present;
    present=ll->head;
    if(ll->head==NULL){
        printf("NULL\n");
        return;
    }
    while(present!=NULL){
        int ans1,ans2;
        ans1=present->key1;
        ans2=present->key2;
        printf("%d %d\n",ans1,ans2);
        present=present->next;
    }
    printf("\n");
}

void swap(int arr[],int a,int b){
    int temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void dfs(graph g,int pos,int list[],int n){
    list[pos]=1;
    for(int i=0;i<n;i++){
        if(list[i]==0 && g->arr[pos][i]>=1){
            dfs(g,i,list,n);
        }
    }
}

void dfs1(graph g,int inpos,int pos,int list[],int n,int arr1[]){
    list[pos]=1;
    for(int i=inpos;i<n+inpos;i++){
        if(list[i-inpos]==0 && g->arr[arr1[pos+inpos]][i]>=1){
            dfs1(g,inpos,i-inpos,list,n,arr1);
        }
    }
}

bool conmid(graph g,int inpos,int n,int arr1[]){
    int list[n-inpos];
    for(int i=0;i<n-inpos;i++){
        list[i]=0;
    }
    dfs1(g,inpos,0,list,n-inpos,arr1);
    int flag=0;
    for(int i=0;i<n-inpos;i++){
        if(list[i]==0){
            flag=1;
            break;
        }
    }
    if (flag==0){
        return true;
    }
    else{
        return false;
    }
}

bool grcon(graph g,int n){
    int list[n];
    for(int i=0;i<n;i++){
        list[i]=0;
    }
    dfs(g,0,list,n);
    int flag=0;
    for(int i=0;i<n;i++){
        if(list[i]==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        return true;
    }
    else{
        return false;
    }
}

bool euler(graph g,int n){
    if(n==1){
        return true;
    }
    if (grcon(g,n)){
        int flag=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(g->arr[i][j]==1){
                    cnt++;
                }
            }
            if(cnt%2==1){
                flag=1;
                break;
            }
        }
        if (flag==0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void solve1(graph g,graph temp,int x,int n,int no,int arr1[],int ed[]){
    int y=arr1[n-x];
    int u=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<ed[i];j++){
            if(i==y){
                continue;
            }
            if(u==-1){
                u=i;
            }
            else{
                g->arr[i][u]--;
                g->arr[u][i]--;
                u=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        g->arr[y][i]=ed[i];
        if(g->arr[y][i]>=1){
            g->arr[i][y]=ed[i];
        }
    }
    for(int i=n-x+1;i<n;i++){
        if(conmid(g,n-x+1,n,arr1)==true){
            break;
        }
        else{
            swap(arr1,n-x,i);
        }
    }
    y=arr1[n-x];
    //we go again
    for(int i=0;i<n;i++){
        ed[i]=0;
    }
    // removing the edges connected with y
    // all the elemnts corresponding to x will be 0
    for(int i=0;i<n;i++){
        ed[i]=g->arr[y][i];
        if(g->arr[y][i]>=1){
            g->arr[y][i]=0;
            g->arr[i][y]=0;
        }
    }
    for(int i=0;i<n;i++){
        temp->arr[y][i]=ed[i];
    }
    // adding required edges
    u=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<ed[i];j++){
            if(i==y){
                continue;
            }
            if(u==-1){
                u=i;
            }
            else{
                g->arr[i][u]++;
                g->arr[u][i]++;
                u=-1;
            }
        }
    }
    return;
}

void solve(graph g,graph temp,int x,int n,sll ll,int no,int arr1[]){
    if (x==1){
        int q=g->arr[arr1[n-1]][arr1[n-1]];
        for(int i=0;i<q/2;i++){
            if (i==0){
                LIST_INSERT_FRONT(ll,arr1[n-1],arr1[n-1]);
            }
            else{
                LIST_INSERT_AFTER(ll,arr1[n-1],arr1[n-1],arr1[n-1],arr1[n-1]);
            }
        }
        return;
    }
    int y=arr1[n-x];
    int ed[n];
    for(int i=0;i<n;i++){
        ed[i]=0;
    }
    // removing the edges connected with y
    // all the elemnts corresponding to x will be 0
    for(int i=0;i<n;i++){
        ed[i]=g->arr[y][i];
        if(g->arr[y][i]>=1){
            g->arr[y][i]=0;
            g->arr[i][y]=0;
        }
    }
    for(int i=0;i<n;i++){
        temp->arr[y][i]=ed[i];
    }
    // adding required edges
    int u=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<ed[i];j++){
            if(i==y){
                continue;
            }
            if(u==-1){
                u=i;
            }
            else{
                g->arr[i][u]++;
                g->arr[u][i]++;
                u=-1;
            }
        }
    }
    if(conmid(g,n-x+1,n,arr1)==false){
        solve1(g,temp,x,n,no,arr1,ed);
    }
    // new graph g' of adj matrix by removing first row and first column 
    solve(g,temp,x-1,n,ll,no,arr1);
    y=arr1[n-x];
    int newarr[n];
    for(int i=0;i<n;i++){
        newarr[i]=0;
    }
    for(int i=0;i<n;i++){
        newarr[i]=temp->arr[y][i];
    }
    u=-1;
    int v=-1;
    for(int i=0;i<n;i++){
        if(i==y){
            continue;
        }
        for(int j=0;j<newarr[i];j++){
            if(u==-1){
                u=i;
            }
            else{
                v=i;
                g->arr[u][v]--;
                g->arr[v][u]--;
                g->arr[u][y]++;
                g->arr[y][u]++;
                g->arr[v][y]++;
                g->arr[y][v]++;
                node p=LIST_SEARCH_LAST(ll,u,v);
                if (p!=NULL){
                    p->key1=u;
                    p->key2=y;
                    if(newarr[y]>0){
                        for(int i=0;i<newarr[y]/2;i++){
                            node qw=CREATE_NODE(y,y);
                            qw->next=p->next;
                            p->next=qw;
                            p=qw;
                        }
                        newarr[y]=0;
                        node rw=CREATE_NODE(y,v);
                        rw->next=p->next;
                        p->next=rw;
                    }
                    else{
                        node uv=CREATE_NODE(y,v);
                        uv->next=p->next;
                        p->next=uv;
                    }
                }
                else{
                    p=LIST_SEARCH_LAST(ll,v,u);
                    p->key1=v;
                    p->key2=y;
                    if(newarr[y]>0){
                        for(int i=0;i<newarr[y]/2;i++){
                            node qw=CREATE_NODE(y,y);
                            qw->next=p->next;
                            p->next=qw;
                            p=qw;
                        }
                        newarr[y]=0;
                        node rw=CREATE_NODE(y,u);
                        rw->next=p->next;
                        p->next=rw;
                    }
                    else{
                        node uv=CREATE_NODE(y,u);
                        uv->next=p->next;
                        p->next=uv;
                    }
                }
                u=-1;
                v=-1;
            }
        }
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    // making the adj matrix of size n by n
    graph g,temp;
    g=(graph)malloc(sizeof(struct grap));
    g->arr=(int**)malloc(n*sizeof(int*));
    temp=(graph)malloc(sizeof(struct grap));
    temp->arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        g->arr[i]=(int*)malloc(n*sizeof(int));
        temp->arr[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g->arr[i][j]=0;
            temp->arr[i][j]=0;
        }
    }

    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        g->arr[x][y]++;
        g->arr[y][x]++;
        // as graph is undirected the adj matrix will be symmetrical
    }
    bool res=euler(g,n);
    if(res==false){
        printf("Not Eulerian\n");
        return 0;
    }
    int arr1[n];
    for(int i=0;i<n;i++){
        arr1[i]=i;
    }
    sll ll=(sll)malloc(sizeof(sll));
    solve(g,temp,n,n,ll,0,arr1);
    PRINT_LIST(ll);
    return 0;
}