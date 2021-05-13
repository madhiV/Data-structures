#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
    char color;
}*head=NULL,*p,*n,*old,*par,*succ;
struct node* newNode(int val){
    n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->left=n->right=NULL;
    return n;
}
void insert(int val){
    p=old=head;
    if(p==NULL){
        head=newNode(val);
    }
    while(p!=NULL){
        old=p;
        if(p->data>val){
            if(old->left==NULL){
                old->left=newNode(val);
                return;
            }
            p=p->left;
        }
        else if(p->data<val){
            if(old->right==NULL){
                old->right=newNode(val);
                return;
            }
            p=p->right;
        }
        else if(p->data==val){
            printf("Cannot enter duplicate value in BST...\n");
            exit(0);
        }
    }
}
void delete(int e){
    p=head;
    while(p!=NULL){
        if(p->data<e){
            par=p;
            p=p->right;
        }
        else if(p->data>e){
            par=p;
            p=p->left;
        }
        else if(p->data==e){
            break;
        }
        if(p==NULL){
            printf("Element not found");
            return;
        }
    }
    //leaf node deletion
    if(p->right==NULL && p->left==NULL){
        if(p==head){
            head=NULL;
            return;
        }
        if(p==par->right){
            par->right=NULL;
        }
        else{
            par->left=NULL;
        }
    }
    //deletion of node with one child
    else if(p->right!=NULL && p->left==NULL){
        if(head==p){
            head=p->right;
            return;
        }
        if(p==par->right){
            par->right=p->right;
        }
        else{
            par->left=p->right;
        }
    }
    else if(p->right==NULL && p->left!=NULL){
            if(head==p){
                head=p->left;
                return;
            }
        if(p==par->right){
            par->right=p->left;
        }
        else{
            par->left=p->left;
        }
    }
    //deletion of node with two children
    else if(p->right!=NULL && p->left!=NULL){
        succ=p->right;
        if(succ->left==NULL){
            p->data=succ->data;
            p->right=succ->right;
            printf("%d deletion success...\n",e);
            return;
        }

        while(succ->left!=NULL){
            par=succ;
            succ=succ->left;
        }
        p->data=succ->data;
        par->left=succ->right;
    }
    printf("%d Deletion success...\n",e);
}
void preorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    printf("%d ",p->data);
    inorderTraversal(p->left);
    inorderTraversal(p->right);
}
void postorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    inorderTraversal(p->left);
    inorderTraversal(p->right);
    printf("%d ",p->data);
}
void inorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    inorderTraversal(p->left);
    printf("%d ",p->data);
    inorderTraversal(p->right);
}
void largest(){
    p=head;
    if(head==NULL){
        printf("No element in the tree...\n");
    }
    while(p->right!=NULL){
        p=p->right;
    }
    printf("The largest element in the tree is %d\n",p->data);
}
void smallest(){
    p=head;
    if(head==NULL){
        printf("No element in the tree...\n");
    }
    while(p->left!=NULL){
        p=p->left;
    }
    printf("The smallest element in the tree %d\n",p->data);
}
int main()
{
    int f=1,e,c;
    while(f==1){
    printf("-----MENU-----\n");
    printf("1.Insert\n2.Delete\n3.Find largest element\n4.Find smallest element\n5.Pre order traversal\n6.Inorder Traversal\n");
    printf("7.Postorder traversal\n8.Exit\nEnter a choice : ");
    scanf("%d",&c);
    switch(c){
    case 1:
        printf("Enter the element : ");
        scanf("%d",&e);
        insert(e);
        break;
    case 2:
        printf("Enter the element : ");
        scanf("%d",&e);
        delete(e);
        break;
    case 3:
        largest();
        break;
    case 4:
        smallest();
        break;
    case 5:
        if(head==NULL){
            printf("Tree is empty...\n");
            break;
        }
        preorderTraversal(head);
        printf("\n");
        break;
    case 6:
        if(head==NULL){
            printf("Tree is empty...\n");
            break;
        }
        inorderTraversal(head);
        printf("\n");
        break;
    case 7:
        if(head==NULL){
            printf("Tree is empty...\n");
            break;
        }
        postorderTraversal(head);
        printf("\n");
        break;
    case 8:
        f=0;
        break;
    default:
        printf("Invalid choice...\n");
    }
    }
    return 0;
}
