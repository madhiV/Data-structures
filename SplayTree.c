#include <stdio.h>
#include <stdlib.h>
//Structure for tree node
struct node{
    int data;
    struct node *right,*left;
}*head=NULL,*p,*temp,*n,*cz,*pz,*old,*gz,*succ;
//Structure for linked list of tree nodes
struct ll{
    struct node *data;
    struct ll *next,*prev;
}*head1=NULL,*p1,*n1;
struct node *newNode(int data){
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->right=n->left=NULL;
    return n;
}
struct ll *newLLNode(struct node *p){
    n1=(struct ll*)malloc(sizeof(struct ll));
    n1->data=p;
    n1->next=n1->prev=NULL;
    return n1;
}
struct node *zag(struct node *pz){//L Rotation
    temp=pz->right;
    p=temp;
    while(p->left!=NULL){
        p=p->left;
    }
    p->left=pz;
    pz->right=NULL;
    return temp;
}
struct node *zig(struct node *pz){//R rotation
    temp=pz->left;
    //temp->right=pz;
    p=temp;
    while(p->right!=NULL){
        p=p->right;
    }
    p->right=pz;
    pz->left=NULL;
    return temp;
}
struct node* splay(struct ll *p1,int c){
    while(c>=2){
        cz=p1->data;
        pz=p1->prev->data;
        n1=p1->prev->prev;
        gz=NULL;
        if(n1!=NULL){
            gz=n1->data;
        }
        if(cz==pz->right){
            temp=zag(pz);
        }
        else{
            temp=zig(pz);
        }
        c--;
        if(c==1){
            return temp;
        }
        else{
            if(pz==gz->right){
                gz->right=temp;
            }
            else{
                gz->left=temp;
            }
        }
        p1->prev->data=temp;
        p1=p1->prev;
    }
}
void splay_(int val){
    p=head;
    p1=head1;
    int c=0;
    while(p!=NULL){
            old=p;
            c++;
            if(p1==NULL){
                p1=newLLNode(p);
            }
            else{
                n1=newLLNode(p);
                p1->next=n1;
                n1->prev=p1;
                p1=n1;
            }
            if(p->data>val){
                p=p->left;
                if(p==NULL){
                    head=splay(p1,c);
                }
            }
            else if(p->data<val){
                p=p->right;
                if(p==NULL){
                    head=splay(p1,c);
                }
            }
            else if(p->data==val){
                if(p!=head){
                head=splay(p1,c);
                }
                p=NULL;
            }
    }
    p1=NULL;
}
void search(int val){
    p=head;
    int c=0;
    p1=head1;
    if(head==NULL){
        printf("Tree is empty...\n");
    }
    while(p!=NULL){
            c++;
        if(p1==NULL){
            p1=newLLNode(p);
        }
        else{
            n1=newLLNode(p);
            p1->next=n1;
            n1->prev=p1;
            p1=n1;
        }
        old=p;
        if(p->data>val){
            p=p->left;
            if(p==NULL){
                splay_(old->data);
                printf("Element not present in the tree...\n");
            }
        }
        else if(p->data<val){
            p=p->right;
            if(p==NULL){
                splay_(old->data);
                printf("Element not present in the tree...\n");
            }
        }
        else if(p->data==val){
            splay_(val);
            printf("Element present in the tree...\n");
            p=NULL;
        }
    }
    p1=NULL;
}
void delete(int val){
    p=head;
    int c=0;
    p1=head1;
    if(p==NULL){
        printf("No element in the tree...\n");
    }
    else{
    while(p!=NULL){
            c++;
            if(p1==NULL){
                p1=newLLNode(p);
            }
            else{
                n1=newLLNode(p);
                n1->prev=p1;
                p1->next=n1;
                p1=n1;
            }
        if(p->data>val){
            old=p;
            p=p->left;
        }
        else if(p->data<val){
            old=p;
            p=p->right;
        }
        else if(p->data==val){
            break;
        }
        else{
            printf("%d not found in the tree...\n");
            return;
            }
        }
        pz=old;
        //Leaf node deletion
        if(p->right==NULL && p->left==NULL){
            if(p==head){
                head=NULL;
                return;
            }
            else if(p==pz->right){
                pz->right=NULL;
            }
            else{
                pz->left=NULL;
            }
            splay_(pz->data);
        }
        //Node with one child
        else if(p->right==NULL && p->left!=NULL){
            if(p==head){
                head=head->left;
                return;
            }
            else if(p==pz->left){
                pz->left=p->left;
            }
            else{
                pz->left=pz->right;
            }
            splay_(pz->data);
        }
        else if(p->right!=NULL && p->left==NULL){
            if(p==head){
                head=head->right;
                return;
            }
            if(p==pz->right){
                pz->right=p->right;
            }
            else{
                pz->left=p->left;
            }
            splay_(pz->data);
        }
        //Node with 2 children
        else if(p->right!=NULL && p->left!=NULL){
            pz=p;
            succ=p->right;
            while(succ->left!=NULL){
                pz=succ;
                succ=succ->left;
            }
            p->data=succ->data;
            if(succ==p->right){
                p->right=succ->right;
            }
            else{
                pz->left=succ->right;
            }
            splay_(p->data);
        }
    }
}
void insert(int val){
    int c=0;
    p=head;

    p1=head1;
    if(head==NULL){
        head=newNode(val);
    }
    else{
        while(p!=NULL){
        if(p1==NULL){
            p1=newLLNode(p);
            c++;
        }
        else{
            n1=newLLNode(p);
            p1->next=n1;
            n1->prev=p1;
            p1=n1;
            c++;
        }
        old=p;
        if(p->data>val){
            p=p->left;
            if(p==NULL){
                old->left=newNode(val);
                n1=newLLNode(old->left);
                p1->next=n1;
                p1->next->prev=p1;
                p1=p1->next;
                c++;
                head=splay(p1,c);
                p=NULL;
            }
        }
        else if(p->data<val){
            p=p->right;
            if(p==NULL){
                old->right=newNode(val);
                n1=newLLNode(old->right);
                p1->next=n1;
                p1->next->prev=p1;
                p1=p1->next;
                c++;
                head=splay(p1,c);
                p=NULL;
            }
        }
        else{
            printf("Cannot enter duplicate value in splay tree...\n");
            exit(0);
            }
        }
    }
    head1=NULL;
    printf("%d insertion success...\n",val);
}
void preorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    printf("%d ",p->data);
    preorderTraversal(p->left);
    preorderTraversal(p->right);
}
void inorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    inorderTraversal(p->left);
    printf("%d ",p->data);
    inorderTraversal(p->right);
}
void postorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    postorderTraversal(p->left);
    postorderTraversal(p->right);
    printf("%d ",p->data);
}
void smallest(){
    p=head;
    if(p==NULL){
        printf("The tree is empty...\n");
    }
    else{
        while(p->left!=NULL){
            p=p->left;
        }
        printf("The smallest element is %d\n",p->data);
    }
}
void largest(){
    p=head;
    if(p==NULL){
        printf("The tree is empty...\n");
    }
    else{
        while(p->right!=NULL){
            p=p->right;
        }
        printf("The largest element is %d\n",p->data);
    }
}
int main()
{
    int c,e,f=1;
    while(f==1){
    printf("-----MENU-----\n");
    printf("1.Insert\n2.Delete\n3.Search\n4.Splay\n5.Preorder Traversal\n6.Inorder Traversal\n7.Postorder Traversal\n8.Display largest element\n9.Display smallest element\n10.Exit\n");
    printf("Enter the choice : ");
    scanf("%d",&c);
    switch(c){
    case 1:
        printf("Enter the element to insert : ");
        scanf("%d",&e);
        insert(e);
        break;
    case 2:
        printf("Enter the element to delete : ");
        scanf("%d",&e);
        delete(e);
        break;
    case 3:
        printf("Enter the element to search : ");
        scanf("%d",&e);
        search(e);
        break;
    case 4:
        printf("Enter the element to splay : ");
        scanf("%d",&e);
        splay_(e);
        printf("Splay success...\n");
        break;
    case 5:
        if(head==NULL){
            printf("The tree is empty...");
        }
        else{
            preorderTraversal(head);
        }
        printf("\n");
        break;
    case 6:
        if(head==NULL){
            printf("The tree is empty...");
        }
        else{
            inorderTraversal(head);
        }
        printf("\n");
        break;
    case 7:
        if(head==NULL){
            printf("The tree is empty...");
        }
        else{
            postorderTraversal(head);
        }
        printf("\n");
        break;
    case 8:
        largest();
        break;
    case 9:
        smallest();
        break;
    case 10:
        f=0;
        break;
    default:
        printf("Invalid choice...\n");
        }
    }
    return 0;
}
