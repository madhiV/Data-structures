#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int count=0;
struct node{//structure for tree node
    int data;
    struct node *left,*right;
}*head=NULL,*p,*n;
struct ll{
    struct node *data;
    struct ll *next,*prev;
}*head1=NULL,*p1,*n1,*p2,*n2;
struct node* newNode(int data){
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->right=n->left=NULL;
    return n;
}
struct ll* newLLNode(struct node* p){
    n1=(struct ll*)malloc(sizeof(struct ll));
    n1->data=p;
    n1->next=n1->prev=NULL;
    return n1;
}
struct ll* getLLNode(int d){
    //printf("%d ",d);
    n2=head1;
    if(d>count){
        return NULL;
    }
    int i=1;
    while(i!=d){
        n2=n2->next;
        i++;
    }
    //printf("%d->%d\n",d,n2->data->data);
    return n2;
}
void insert(int e){
    double i,pos;
    int t;
    p=head;
    p1=head1;
    if(head==NULL){
        head=newNode(e);
        head1=newLLNode(head);
        count++;
    }
    else{
        while(p1->next!=NULL){
            p1=p1->next;
        }
        n=newNode(e);
        count++;
        p1->next=newLLNode(n);
        p1=p1->next;
        pos=(floor(count/2));
        p1=getLLNode(pos);
        if(p1->data->left==NULL){
            p1->data->left=n;
        }
        else{
            p1->data->right=newNode(e);
        }
        i=count;
        while(pos>0){
            p1=getLLNode(pos);
            p2=getLLNode(i);
            if(p1->data->data>p2->data->data){
                p2->data->data=p1->data->data;
                p1->data->data=e;
            }
            else{
                //printf("%d %d",p1->data->data,p2->data->data);
                break;
            }
            if(pos==1){
                break;
            }
            i=pos;
            pos=floor(i/2);
        }
    }
    printf("%d insertion success...\n",e);
}
void delete_(){
    p1=head1;
    int pos,c,l,r,e,temp;
    c=head->data;
    if(p1->next==NULL){
        head=NULL;
        head1=NULL;
        count--;
    }
    else{
        count--;
        if(p1->next->next==NULL){
            head->data=p1->next->data->data;
            head->left=NULL;
            head1->data=head;
            head1->next=NULL;
        }
        else{
            while(p1->next!=NULL){
                p1=p1->next;
            }
            e=p1->data->data;
            p1=head;
            head->data=e;
            pos=1;
            p1=head1;
            while(p1->next->next!=NULL){
                p1=p1->next;
            }
            if(p1->data->right==p1->next->data){
                p1->data->right=NULL;
            }
            else{
                p1->data->left=NULL;
            }
            p1->next=NULL;
            traverse();
            while(pos*2 <=count){
                p1=getLLNode(pos);
                l=pos*2;
                r=pos*2+1;
                n1=getLLNode(l);
                p2=getLLNode(r);
                if(p2==NULL || (n1->data->data < p2->data->data)){
                    if(n1->data->data<e){
                        p1->data->data=n1->data->data;
                        n1->data->data=e;
                        pos=l;
                    }
                    else{
                        break;
                    }
                }
                else if(p2!=NULL){
                    if(p2->data->data<e){
                        p1->data->data=p2->data->data;
                        p2->data->data=e;
                        pos=r;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    printf("%d deletion success...\n",c);
}
void traverse(){
    p1=head1;
    if(head1==NULL){
        printf("The tree is empty...\n");
    }
    while(p1!=NULL){
        printf("%d ",p1->data->data);
        p1=p1->next;
    }
    printf("\n");
}
void min_(){
    if(head1==NULL){
        printf("Heap empty...\n");
    }
    else{
        printf("The minimum element in the heap is %d\n",head->data);
    }
}
int main()
{
    int f=1,c;
    while(f==1){
        printf("-----MENU-----\n");
        printf("1.Insert\n2.Delete\n3.Find minimum\n4.Traverse\n5.Exit");
        printf("\nEnter a choice : ");
        scanf("%d",&c);
        switch(c){
        case 1:
            printf("Enter the element to insert : ");
            scanf("%d",&c);
            insert(c);
            break;
        case 2:
            delete_(c);
            break;
        case 3:
            min_();
            break;
        case 4:
            traverse();
            break;
        case 5:
            f=0;
            break;
        default:
            printf("Invalid choice...\n");
        }
    }
    return 0;
}
