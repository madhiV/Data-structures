#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
}*p,*n,*head=NULL,*par,*succ,*temp;
void delete(struct node* p,int val)
{
    if(p==NULL){
        printf("No element %d in the tree\n",val);
        return;
    }
    else if(p->data<val){
        par=p;
        delete(p->right,val);
    }
    else if(p->data>val){
        par=p;
        delete(p->left,val);
    }
    else if(p->data==val){
        //leaf node deletion...
        if(p->left==NULL && p->right==NULL){
            if(head==p){
                head=NULL;
                goto x;
            }
            if(par->left==p){
                par->left=NULL;
            }
            else{
                par->right=NULL;
            }
        }
        //node with one child deletion...
        else if(p->left==NULL && p->right!=NULL){
                if(p==head){
                    head=p->right;
                    goto x;
                }
            if(par->left==p){
                par->left=p->right;
            }
            else{
                par->right=p->right;
            }
        }
        else if(p->left!=NULL && p->right==NULL){
                if(p==head){
                    head=p->left;
                    goto x;
                }
            if(par->left==p){
                par->left=p->left;
            }
            else{
                par->right=p->left;
            }
        }
        //deletion of node with 2 children by replacement with preorder predecessor
        else if(p->left!=NULL && p->right!=NULL){
            succ=p->left;
            par=p;
            if(succ->right==NULL){
                p->data=succ->data;;
                p->left=succ->left;
                goto x;
            }
            while(succ->right!=NULL){
                par=succ;
                succ=succ->right;
            }
            p->data=succ->data;
            par->right=NULL;
        }
        x:
        printf("%d deletion success\n",val);
        return;
    }
}
struct node* insert(struct node* p,int val){
    if(p==NULL){
        n=(struct node*)malloc(sizeof(struct node));
        n->data=val;
        n->left=n->right=NULL;
        printf("Inserted %d ...\n",val);
        return n;
    }
    if(p->data>val){
        p->left=insert(p->left,val);
    }
    else if(p->data<val){
        p->right=insert(p->right,val);
    }
    else if(p->data==val){
        printf("Cannot enter  duplicate value ...");
        exit(0);
    }
    return p;
}
void largest(){
    p=head;
    if(p==NULL){
        printf("No elements in the tree...\n");
        return;
    }
    else{
        while(p->right!=NULL){
            p=p->right;
        }
        printf("The largest element : %d\n",p->data);
    }
}
void smallest(){
    p=head;
    if(p==NULL){
        printf("No elements in the tree...\n");
        return;
    }
    else{
        while(p->left!=NULL){
            p=p->left;
        }
        printf("The smallest element : %d\n",p->data);
    }
}
void inorder_traversal(struct node* p)
{
    if(head==NULL){
        printf("No elements in the tree...\n");
        return;
    }
    if(p==NULL){
        return;
    }
    inorder_traversal(p->left);
    printf("%d ",p->data);
    inorder_traversal(p->right);
}
void pre_order_traversal(struct node* p)
{
    if(p==NULL){
        return;
    }
    printf("%d ",p->data);
    inorder_traversal(p->left);
    inorder_traversal(p->right);
}
void post_order_traversal(struct node* p)
{
    if(p==NULL){
        return;
    }
    inorder_traversal(p->left);
    inorder_traversal(p->right);
    printf("%d ",p->data);
}
int main()
{
    int f=1,c,e;
    while(f){
    printf("-----MENU-----\n");
    printf("1.Insert 2.Delete 3.Traverse 4.Display smallest element 5.Display largest element 6.Exit\n");
    printf("Enter a choice : ");
    scanf("%d",&c);
    switch(c){
    case 1:
        printf("Enter the element : ");
        scanf("%d",&e);
        head=insert(head,e);
        break;
    case 2:
        printf("Enter the element : ");
        scanf("%d",&e);
        par=head;
        delete(head,e);
        break;
    case 3:
        printf("1.Preorder traversal 2.Inorder traversal 3.Postorder traversal\nEnter a choice : ");
        scanf("%d",&c);
        switch(c){
        case 1:
            pre_order_traversal(head);
            break;
        case 2:
            inorder_traversal(head);
            break;
        case 3:
            post_order_traversal(head);
            break;
        default:
            printf("Invalid choice...\n");
        }
        printf("\n");
        break;
    case 4:
        smallest(head);
        break;
    case 5:
        largest(head);
        break;
    case 6:
        f=0;
        break;
    defalt:
        printf("Invalid choice\n");
    }
    }
return 0;
}
