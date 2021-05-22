#include <stdio.h>
#include <stdlib.h>
int queue[100],front=-1,rear=-1;
void enqueue(int e){
    if(front==-1){
        front++;
        rear++;
        queue[front]=e;
    }
    else{
        rear++;
        queue[rear]=e;
    }
}
int dequeue(){
    int e=queue[front];
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }
    return e;
}
int main()
{
    int n,k=0,v;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int graph[n][n],visited[n],ans[n];
    printf("Enter the adjacency matrix representation of the graph : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            enqueue(i);
            v=dequeue();
            visited[v]=1;
            for(int j=0;j<n;j++){
                if(graph[v][j]==1){
                    if(visited[j]==0){
                        enqueue(j);
                        visited[j]=1;
                    }
                }
            }
            ans[k]=v;
            k++;
        }
        else{
            v=dequeue();
            for(int j=0;j<n;j++){
                if(graph[v][j]==1){
                    if(visited[j]==0){
                        enqueue(j);
                        visited[j]=1;
                    }
                }
            }
            ans[k]=v;
            k++;
        }
    }
    printf("BFS of the given graph : ");
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]+1);
    }
    return 0;
}
