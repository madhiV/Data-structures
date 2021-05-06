//Priority queue
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node *next;
}*n,*head=NULL,*p;
void enqueue(int e,int d,int c){
    n=(struct node*)malloc(sizeof(struct node));
    n->data=e;
    n->priority=d;
    n->next=NULL;
    if(head==NULL){
        head=n;
        printf("Insertion success...\n");
    }
    else{
        p=head;
        if(c==1){//ascending
            if(head->priority>=n->priority){
                n->next=head;
                head=n;
                printf("Insertion success...\n");
            }
            else if(head->next==NULL){
                if(n->priority<=head->priority){
                    n->next=head;
                    head=n;
                    printf("Insertion success...\n");
                }
                else{
                    head->next=n;
                    printf("Insertion success...\n");
                }
            }
            else{
                while(p->next!=NULL){
                    if(p->next->priority>=n->priority){
                        n->next=p->next;
                        p->next=n;
                        printf("Insertion success...\n");
                        break;
                    }
                    p=p->next;
                    if(p->next==NULL){
                        p->next=n;
                        printf("Insertion success...\n");
                        break;
                    }
                }
            }
        }
        else
        {//descending
            if(head->priority<=n->priority){
                n->next=head;
                head=n;
                printf("Insertion success...\n");
            }
            else if(head->next==NULL){
                if(n->priority>=head->priority){
                    n->next=head;
                    head=n;
                    printf("Insertion success...\n");
                }
                else{
                    head->next=n;
                    printf("Insertion success...\n");
                }
            }
            else{
                while(p->next!=NULL){
                    if(p->next->priority<=n->priority){
                        n->next=p->next;
                        p->next=n;
                        printf("Insertion success...\n");
                        break;
                    }
                    p=p->next;
                    if(p->next==NULL){
                        p->next=n;
                        printf("Insertion success...\n");
                        break;
                    }
                }
            }
        }
    }
}
void dequeue()
{
    if(head==NULL){
        printf("Queue underflow...\n");
    }
    else{
        printf("%d dequeued from the queue...\n",head->data);
        head=head->next;
    }
}
void traverse()
{
    p=head;
    if(p==NULL){
        printf("No elements in the queue...\n");
        return;
    }
    printf("The elements are : ");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void peek()
{
    if(head==NULL){
        printf("No elements in the queue...\n");
        return;
    }
    printf("The peek element is %d...\n",head->data);
}
void size()
{
    p=head;
    int count=0;
    while(p!=NULL){
        count+=1;
        p=p->next;
    }
    printf("Size of queue : %d\n",count);
}
int main()
{
    int c,e,p,flag=0,t=0,a;
    printf("Do you want to assign priority \n1-YES 0-NO Enter a choice : ");
    scanf("%d",&e);
    if(e==1){
        t=1;
    }
    printf("1-Ascending priority queue 2-Descending priority queue\nEnter a choice: ");
    scanf("%d",&a);
    while(flag==0){
        printf("-----MENU-----\n");
        printf("1.Enqueue 2.Dequeue 3.Traverse 4.Peek 5.Size 6.Exit\nEnter a choice : ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter the number : ");
                scanf("%d",&e);
                if(t==1){
                    printf("Enter the priority : ");
                    scanf("%d",&p);
                    enqueue(e,p,a);
                }
                else{
                    enqueue(e,e,a);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                peek();
                break;
            case 5:
                size();
                break;
            case 6:
                flag=1;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
