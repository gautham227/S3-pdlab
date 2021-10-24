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

void dfs(graph g,int pos,int list[],int n){
    list[pos]=1;
    for(int i=0;i<n;i++){
        if(list[i]==0 && g->arr[pos][i]==1){
            dfs(g,i,list,n);
        }
    }
}

bool grcon(graph g,int n){
    int list[n];
    for(int i=0;i<n;i++){
        list[i]=1;
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

void solve(graph g,int x,int n,int pos1[],int pos2[],int no){
    if (x==1){
        return;
    }
    int y=n-x;
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
    // new graph g' of adj matrix by removing first row and first column 
    solve(g,x-1,n,pos1,pos2,no);
    
}

int main(){
    int n;
    scanf("%d",&n);
    // making the adj matrix of size n by n
    graph g;
    g=(graph)malloc(sizeof(struct grap));
    g->arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        g->arr[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g->arr[i][j]=0;
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
    else{
        printf("yes");
    }
    int pos1[n];
    int pos2[n];
    solve(g,n,n,pos1,pos2,0);
}