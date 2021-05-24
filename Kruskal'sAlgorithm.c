#include <stdio.h>
#include <stdlib.h>
void union_(int n,int s[n],int u,int v){
    if(u<v){
        s[u]+=s[v];
        s[v]=u;
    }
    else{
        s[v]+=s[u];
        s[u]=v;
    }
}
int find(int n,int s[n],int u){
    int x=u;
    while(s[x]>0){
        x=s[x];
    }
    return x;
}
int main()
{
    int n,t=0,k=0,min,m;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int graph[n][n],ans[n-1],s[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(i!=j && graph[i][j]>=1){
                t+=1;
            }
        }
        s[i]=-1;
    }
    t/=2;//Number of edjes with no self-loop edges
    int source[t],d[t],w[t],visited[t];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(graph[i][j]>0){
                source[k]=i;
                d[k]=j;
                w[k]=graph[i][j];
                k++;
            }
        }
    }
    k=0;
    for(int i=0;i<t;i++){
        visited[i]=0;
    }
    printf("Edges...\n");
    for(int i=0;i<t;i++){
        printf( "No.->%d S->%d D->%d W->%d\n",i,source[i],d[i],w[i]);
    }
    //Kruskal's core
    for(int i=0;i<t;i++){
        min=30000;
        for(int j=0;j<t;j++){//for getting minimum weight edge which is not yet visited
            if(visited[j]==0 && w[j]<min){
                min=w[j];
                m=j;
            }
        }
        visited[m]=1;
        if(find(n,s,source[m])!=find(n,s,d[m])){
            union_(n,s,source[m],d[m]);
            ans[k]=m;
            k++;
            if(k==n-1){
                break;
            }
        }
    }
    //Printing
    k=0;
    printf("Selected edges...\n");
    for(int i=0;i<n-1;i++){
        printf("S->%d D->%d W->%d\n",source[ans[i]],d[ans[i]],w[ans[i]]);
        k+=w[ans[i]];
    }
    printf("Min cost : %d",k);
    return 0;
}
