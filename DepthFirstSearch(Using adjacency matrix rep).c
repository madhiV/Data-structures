#include <stdio.h>
#include <stdlib.h>
int visited[1000],ans[1000],k=0;
void DFS(int n,int graph[][n],int u){
    if(visited[u]==0){
        ans[k]=u;
        k++;
        visited[u]=1;
        for(int i=0;i<n;i++){
            if(graph[u][i]==1 && visited[i]==0){
                DFS(n,graph,i);
            }
        }
    }
}
int main()
{
    static int n;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the adjacency matrix representation of the graph : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        DFS(n,graph,i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]+1);
    }
    return 0;
}
