#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*p,*temp,*head,*par;
struct Gnode{
    struct node* data;
    struct Gnode *next;
}*p1,*Head1=NULL,*graph=NULL,*n1;
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
void traverse(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void enqueue(struct node *p){
    if(Head1==NULL){
        Head1=newGNode(p);
    }
    else{
        n1=Head1;
        while(n1->next!=NULL){
            n1=n1->next;
        }
        n1->next=newGNode(p);
    }
    //printf("Enqueued %d \n",p->data);
}
void dequeue(){
    Head1=Head1->next;
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
void BFS(int n,int visited[n]){
    p1=graph;
    while(p1!=NULL){
        if(visited[p1->data->data]==0){
            visited[p1->data->data]=1;
            enqueue(p1->data);
            while(Head1!=NULL){
                p=Head1->data;
                while(p!=NULL){
                    if(visited[p->data]==0){
                        enqueue(p);
                        visited[p->data]=1;
                    }
                    p=p->next;
                }
                printf("%d ",Head1->data->data);
                dequeue();
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
    printf("1.Directed graph\n2.Undirect graph\nEnter a choice : ");
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
    printf("The BFS Traversal of the graph is : \n");
    BFS(m,visited);
}
