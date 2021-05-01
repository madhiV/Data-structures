#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
}*head=NULL,*n,*p,*del,*par,*succ;
struct node* insert(struct node *p,int e)
{
    if(p==NULL){
        n=(struct node*)malloc(sizeof(struct node));
        n->data=e;
        n->left=n->right=NULL;
        return n;
    }
    else if(e>p->data){
         p->right=insert(p->right,e);
    }
    else if(e<p->data){
        p->left=insert(p->left,e);
    }
    else if(p->data==e){
        printf("Duplication not allowed\n");
    }
    return p;
}
void in_order_traversal(struct node *temp){
    if(temp==NULL){
        return;
    }
    else{
        in_order_traversal(temp->left);
        printf("%d\t",temp->data);
        in_order_traversal(temp->right);
    }
}
void pre_order_traversal(struct node *temp){
    if(temp==NULL){
        return;
    }
    else{
        printf("%d\t",temp->data);
        pre_order_traversal(temp->left);
        pre_order_traversal(temp->right);
    }
}
void post_order_traversal(struct node *temp){
    if(temp==NULL){
        return;
    }
    else{
        post_order_traversal(temp->left);
        post_order_traversal(temp->right);
        printf("%d\t",temp->data);
    }
}
void display_smallest(){
    p=head;
    while(p->left!=NULL){
        p=p->left;
    }
    printf("The smallest element is : %d\n",p->data);
}
void display_largest(){
    p=head;
    while(p->right!=NULL){
        p=p->right;
    }
    printf("The largest element is : %d\n",p->data);
}
void root()
{
    if(head==NULL){
        printf("The Tree doesnt have a root node\n");
    }
    else{
    printf("The element in the root is : %d\n",head->data);
    }
}
struct node *search(struct node* p,int e)
{
    if(p->data==e){
        return p;
    }
    else if(e<p->data){
        search(p->left,e);
    }
    else if(e>p->data){
        search(p->right,e);
    }
}
void delete(struct node *p,int e)
{
    int n=1;
    //root node deletion
    if(p->data==e){
        //root having no child
        if(p->left==NULL && p->right==NULL){
        head=NULL;
        }
        else if(p->right!=NULL && p->left==NULL){
            head=p->right;
        }
        else if(p->right==NULL && p->left!=NULL){
            head=p->left;
        }
        else if(p->right!=NULL && p->left!=NULL){
            succ=p->right;
            while(succ->left!=NULL){
                succ=succ->left;
            }
            head=succ;
        }
        printf("The element %d deleted from the tree...\n",e);
        return;
    }
    
    
    //finding parent of the node to be deleted
    while(n!=0){
        if(e>p->data){
            par=p;
            p=p->right;
            continue;
        }
        else if(e<p->data){
            par=p;
            p=p->left;
        }
        else if(e==p->data){
            printf("The element %d deleted from the tree...\n",e);
            del=p;
            break;
        }
        else{
            printf("The element %d not found in the tree...\n",e);
            // return head;
        }
    }
    
    //leaf node deletion
    if(p->left==NULL && p->right==NULL){
        if(par->left==NULL && par->right!=NULL){
            par->right=NULL;
        }
        else{
            par->left=NULL;
            return;
        }
    }
    
    //leaf node with one child
    if(p->left==NULL && p->right!=NULL){
        if(p==par->right){
            par->right=p->right;
        }
        if(p==par->left){
            par->left=p->right;
        }
        return;
    }
    else if(p->left!=NULL && p->right==NULL){
        if(par->right==p){
            par->right=p->left;
        }
        else{
            par->left=p->left;
        }
        return;
    }
    
    //internal node deletion
    if(p->left!=NULL && p->right!=NULL){
        succ=p->right;
        while(succ->left!=NULL){
            succ=succ->left;
        }
        if(p==par->left){
            par->left=succ;
        }
        else if(p==par->right){
            par->right=succ;
        }
    }
}
void main()
{
    int e,i,flag=0,j;
    while(flag==0){
    printf("*****MENU*****\n");
    printf("1.Insert 2.Search 3.Traverse 4.Display largest 5.Smallest element 6.Root node 7.Exit 8.Delete\n");
    printf("Enter your choice : ");
    scanf("%d",&e);
    switch(e){
        case 1:
            printf("Enter the element : ");
            scanf("%d",&i);
            head=insert(head,i);
            break;
        case 2:
            printf("Enter the element to search : ");
            scanf("%d",&i);
            if(search(head,i)!=NULL){
                printf("Element found...\n");
            }
            else{
                printf("Element not found...\n");
            }
            break;
        case 3:
            printf("1.Pre-order traversal 2.Inorder traversal 3.Post-order traversal\n");
            printf("Enter the type of traversal : ");
            scanf("%d",&j);
            switch(j){
            case 1:
                pre_order_traversal(head);
                printf("\n");
                break;
            case 2:
            printf("The elements in the tree are : ");
                in_order_traversal(head);
                printf("\n");
                break;
            case 3:
                post_order_traversal(head);
                printf("\n");
                break;
            default:
                printf("Invalid option...");
            }
            break;
        case 4:
            display_largest();
            break;
        case 5:
            display_smallest();
            break;
        case 6:
            root();
            break;
        case 7:
            flag=1;
            break;
        case 8:
            printf("Enter the element to delete : ");
            scanf("%d",&i);
            delete(head,i);
            break;
        default:
            printf("Invalid option...");
        }
    }
}
