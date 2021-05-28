#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*p,*temp,*head,*par;
struct Gnode{
    struct node* data;
    struct Gnode *next;
}*p1,*graph=NULL,*n1,*Head1=NULL,*temp1;
struct node* newNode(int data){
    p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}
struct Gnode *newGNode(struct node *p){
    n1=(struct Gnode*)malloc(sizeof(struct Gnode));
    n1->data=p;
    n1->next=NULL;
    return n1;
}
struct node* insertNode(struct node *par,struct node *p){
    if(par==NULL){
        return p;
    }
    temp=par;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    return par;
}
void insertGNode(struct Gnode *n1){
    if(graph==NULL){
        graph=n1;
    }
    else{
        p1=graph;
        while(p1->next!=NULL){
            p1=p1->next;
        }
        p1->next=n1;
    }
}
void display(){
    p1=graph;
    while(p1!=NULL){
        p=p1->data;
        temp=p;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
        p1=p1->next;
    }
}
void addEdge(int s,int d){
    int e;
    p1=graph;
    while(p1!=NULL){
        e=p1->data->data;
        if(e==s){
            p1->data=insertNode(p1->data,newNode(d));
            break;
        }
        p1=p1->next;
    }
}
void push(struct node *p){
    if(Head1==NULL){
        Head1=newGNode(p);
    }
    else{
        n1=newGNode(p);
        n1->next=Head1;
        Head1=n1;
    }
    printf("%d ",p->data);
}
struct GNode* pop(){
    if(Head1==NULL){
        return NULL;
    }
    temp1=Head1;
    Head1=Head1->next;
    return temp1;
}
void DFS(int n,int visited[n]){
    p1=graph;
    while(p1!=NULL){
        if(visited[p1->data->data]==0){
            push(p1->data);
            visited[p1->data->data]=1;
            n1=p1;
            while(n1!=NULL){
                p=n1->data;
                while(p!=NULL){
                    if(visited[p->data]==0){
                        push(p);
                        visited[p->data]=1;
                    }
                    p=p->next;
                }
                n1=pop();
            }
        }
        p1=p1->next;
    }
}
int main()
{
    int n,s,d,m,f;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int visited[n];
    m=n;
    printf("1.Directed graph\n2.Undirected graph\nEnter a choice : ");
    scanf("%d",&f);
    for(int i=0;i<n;i++){
        insertGNode(newGNode(newNode(i)));
        visited[i]=0;
    }
    if(f==2){
        printf("Enter the number of edges : ");
        scanf("%d",&n);
        printf("Enter the edges (Source & Destination): \n");
        for(int i=0;i<n;i++){
            scanf("%d",&s);
            scanf("%d",&d);
            addEdge(s,d);
            addEdge(d,s);
        }
    }
    else{
        printf("Enter the number of edges : ");
        scanf("%d",&n);
        printf("Enter the edges (Source & Destination): \n");
        for(int i=0;i<n;i++){
            scanf("%d",&s);
            scanf("%d",&d);
            addEdge(s,d);
        }
    }
    printf("Adjacency matrix is : \n");
    display(graph);
    printf("The DFS Traversal of the graph is : \n");
    DFS(m,visited);
}
