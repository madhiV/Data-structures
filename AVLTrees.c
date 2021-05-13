#include <stdio.h>
#include <stdlib.h>
//structure for node
struct node{
    int data,height;
    struct node *left;
    struct node *right;
}*head=NULL,*p,*n,*succ,*old,*temp;
//height of the node
int height(struct node *p){
    if(p==NULL){
        return 0;
    }
    if(p->left==NULL && p->right==NULL){
        return 1;
    }
    return max(height(p->left),height(p->right))+1;
}
//create a node with value e
struct node* newNode(int e){
    n=(struct node*)malloc(sizeof(struct node));
    n->data=e;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}//RR Rotation
struct node* RR(struct node* p){
    temp=p->right;
    p->right=temp->left;
    temp->left=p;
    temp->height=height(temp);
    p->height=height(p);
    return temp;
}
//LL Rotation
struct node* LL(struct node* p){
    temp=p->left;
    p->left=temp->right;
    temp->right=p;
    temp->height=height(temp);
    p->height=height(p);
    return temp;
}
//LR Rotation
struct node *LR(struct node *p){
    temp=p->left->right;
    p->left->right=temp->left;
    temp->left=p->left;
    p->left=temp->right;
    temp->right=p;
    temp->height=height(temp);
    p->height=height(p);
    return temp;
}
//RL Rotation
struct node* RL(struct node* p){
    temp=p->right->left;
    p->right->left=temp->right;
    temp->right=p->right;
    p->right=temp->left;
    temp->left=p;
    temp->height=height(temp);
    p->height=height(p);
    return temp;
}
//node insertion
struct node* insert(struct node *p,int e){
    if(p==NULL){
        printf("Insertion of %d success...\n",e);
        return newNode(e);
    }
    if(p->data>e){
        p->left=insert(p->left,e);
        p->height=p->left->height+1;
    }
    else if(p->data<e){
        p->right=insert(p->right,e);
        p->height=p->right->height+1;
    }
    else if(p->data==e){
        printf("Duplicate element not allowed...\n");
        exit(0);
    }
    int b;
    if(p==NULL){
        return NULL;
    }
    p->height=height(p);
    b=(height(p->left)-height(p->right));
    if(b==2){
        if((height(p->left->left)-height(p->left->right))==1){
            p=LL(p);
        }
        else{
            p=LR(p);
        }
    }
    else if(b==-2){
        if((height(p->right->left)-height(p->right->right))==1){
            p=RL(p);
        }
        else{
            p=RR(p);
        }
    }
    p->height=height(p);
    return p;
}
//node deletion
struct node* delete_(struct node* p,struct node *par,int val)
{
    if(p==NULL){
        printf("Element not found...\n");
        return NULL;
    }
    if(p->data>val){
        return delete_(p->left,p,val);
    }
    else if(p->data<val){
        return delete_(p->right,p,val);
    }
    else if(p->data==val){
        if(p->left==NULL && p->right==NULL){
                if(p==head){
                    head=NULL;
                    goto x;
                }
            if(p==par->right){
                par->right=NULL;
            }
            else{
                par->left=NULL;
            }
        }
        else if(p->left!=NULL && p->right==NULL){
                if(p==head){
                    head=head->left;
                    goto x;
                }
            if(p==par->left){
                par->left=p->left;
            }
            else{
                par->right=p->left;
            }
        }
        else if(p->left==NULL && p->right!=NULL){
                if(p==head){
                    head=p->right;
                }
            if(p==par->left){
                par->left=p->right;
            }
            else{
                par->right=p->right;
            }
        }
        else if(p->left!=NULL && p->right!=NULL){
            old=p;
            succ=p->right;
            if(succ->left==NULL){
                p->data=succ->data;
                p->right=succ->right;
            }
            else{
            while(succ->left!=NULL){
                old=succ;
                succ=succ->left;
                }
                p->data=succ->data;
                old->left=succ->right;
            }
        }
        par->height=(height(par));

        x:
        printf("Deletion of %d success...\n",val);
        return head;
    }
    return head;
}
//maximum of 2 integers
int max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}
//preorder traversal of the tree
void preorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    printf("%d ",p->data);
    preorderTraversal(p->left);
    preorderTraversal(p->right);
}
//inorder traversal of the tree
void inorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    inorderTraversal(p->left);
    printf("Value : %d Height : %d\n",p->data,p->height);
    inorderTraversal(p->right);
}
//postorder traversal of the tree
void postorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    postorderTraversal(p->left);
    postorderTraversal(p->right);
    printf("%d ",p->data);
}
//largest element in the tree
void largest(struct node* p){
    if(p==NULL){
        printf("The tree is empty...\n");
    }
    while(p->right!=NULL){
        p=p->right;
    }
    printf("The largest element in the tree is %d\n",p->data);
}
//smallest element in the tree
void smallest(struct node* p){
    if(p==NULL){
        printf("The tree is empty...\n");
    }
    while(p->left!=NULL){
        p=p->left;
    }
    printf("The smallest element in the tree is %d\n",p->data);
}
/*Easy trick to find which rotation to perform
If height>0 go left
else goto right*/
int main()
{
    int f=1,c,e;
    while(f==1){
        printf("-----MENU-----\n");
        printf("1.Insert\n2.Delete\n3.Display largest element\n4.Display smallest element\n5.Preorder Traversal\n6.Postorder traversal\n");
        printf("7.Inorder traversal\n8.Exit\nEnter a choice : ");
        scanf("%d",&c);
        switch(c){
        case 1:
            printf("Enter the value : ");
            scanf("%d",&e);
            head=insert(head,e);
            break;
        case 2:
            printf("Enter the value : ");
            scanf("%d",&e);
            head=delete_(head,head,e);
            break;
        case 3:
            largest(head);
            break;
        case 4:
            smallest(head);
            break;
        case 5:
            if(head==NULL){
                printf("Tree is empty\n");
            }
            preorderTraversal(head);
            printf("\n");
            break;
        case 6:
            if(head==NULL){
                printf("Tree is empty\n");
            }
            postorderTraversal(head);
            printf("\n");
            break;
        case 7:
            if(head==NULL){
                printf("Tree is empty\n");
            }
            inorderTraversal(head);
            printf("\n");
            break;
        case 8:
            f=0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
