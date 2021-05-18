#include <stdio.h>
#include <stdlib.h>
//Tree node structure
struct node{
    int data;
    struct node *left,*right;
    char color;
}*head=NULL,*p,*n,*old,*par,*succ,*temp,*pz,*gz,*cz,*y,*ggz;
//Linked list for finding grand parent of a node
struct ll{
    struct node *data;
    struct ll *next,*prev;
}*head1=NULL,*p1,*n1,*temp1;
//new Tree node
struct node* newNode(int val){
    n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->left=n->right=NULL;
    n->color='R';
    return n;
}
//Creating new doubly linked list node
struct ll* newDLLNode(struct node* p){
    n1=(struct ll*)malloc(sizeof(struct ll));
    n1->data=p;
    n1->next=n1->prev=NULL;
    return n1;
}
//RR rotation
struct node* RR(struct node* p){
    temp=p->right;
    p->right=temp->left;
    temp->left=p;
    return temp;
}
//LL Rotation
struct node* LL(struct node* p){
    temp=p->left;
    p->left=temp->right;
    temp->right=p;
    return temp;
}
//RL Rotation
struct node* RL(struct node* p){
    temp=p->right->left;
    p->right->left=temp->right;
    temp->right=p->right;
    p->right=temp->left;
    temp->left=p;
    return temp;
}
//LR Rotation
struct node* LR(struct node *p){
    temp=p->left->right;
    p->left->right=temp->left;
    temp->left=p->left;
    p->left=temp->right;
    temp->right=p;
    return temp;
}
//uncle of a node
struct node* findUncle(struct node* gz,struct node *pz){
    if(pz==gz->right){
        return gz->left;
    }
    if(pz==gz->left){
        return gz->right;
    }
}
//insertion
void insert(int val){
    int c=0;//To count number of elments in the linked list of nodes
    if(head==NULL){
        head=newNode(val);
        head->color='B';
    }
    else{
        p=head;
        p1=head1;
        while(1){
            if(p1==NULL){
                p1=newDLLNode(p);
            }
            else{
                n1=newDLLNode(p);
                p1->next=n1;
                n1->prev=p1;
                p1=n1;
            }
            c++;
            old=p;
            if(p->data<val){//Go right
                p=p->right;
                if(p==NULL){
                    old->right=newNode(val);
                    n1=newDLLNode(old->right);
                    p1->next=n1;
                    n1->prev=p1;
                    p1=n1;
                    c++;
                    break;
                }
            }
            else if(p->data>val){//Go left
            p=p->left;
            if(p==NULL){
                    old->left=newNode(val);
                    n1=newDLLNode(old->left);
                    p1->next=n1;
                    n1->prev=p1;
                    p1=n1;
                    c++;
                break;
                }
            }
            else if(p->data==val){
                printf("Cannot enter duplicate value in a BST\n");
                exit(0);
            }
        }
        while(c>=3){
            gz=p1->prev->prev->data;
            pz=p1->prev->data;
            cz=p1->data;
            ggz=p1->prev->prev->prev;
            if(p1->prev->prev->prev!=NULL){
                ggz=ggz->data;
            }
            y=findUncle(gz,pz);
            if(y==NULL){//No uncle condition
                printf("No uncle condition\n");
                //Same side
                if(pz==gz->right && cz==pz->right){//RR Rotation
                    cz->color='R';
                    gz->color='R';
                    pz->color='B';
                    temp=RR(gz);
                    if(ggz!=NULL){
                        ggz->right=temp;
                    }
                }
                else if(pz->left==cz && gz->left==pz){//LL Rotation
                        printf("LL Rotation");
                    cz->color='R';
                    gz->color='R';
                    pz->color='B';
                    temp=LL(gz);
                    if(ggz!=NULL){
                        ggz->left=temp;
                    }
                }
                //Different condition
                else if(pz==gz->right && pz->left==cz){//RL Rotation
                    cz->color='B';
                    pz->color='R';
                    gz->color='R';
                    temp=RL(gz);
                    if(ggz!=NULL){
                            printf("RL Rotation\n");
                            if(gz==ggz->left){
                            ggz->left=temp;
                            }
                            else{
                                ggz->right=temp;
                            }
                    }
                }
                else{//LR Rotation
                    cz->color='B';
                    pz->color='R';
                    gz->color='R';
                    temp=LR(gz);
                    if(ggz!=NULL){
                            printf("LR Rotation\n");
                        if(gz==ggz->left){
                            ggz->left=temp;
                            }
                            else{
                                ggz->right=temp;
                            }
                    }
                }
            }
            else if(y->color=='R'){//Red Uncle Condition
                    printf("Red uncle condition\n");
                    if(gz!=head){
                        gz->color='R';
                    }
                    y->color='B';
                    pz->color='B';
                    temp=gz;
            }
            if(ggz==NULL){
                head=temp;
            }
            c-=3;
            p1=p1->prev->prev;
        }
    }
    head1=NULL;
    printf("%d insertion success\n",val);
}
//Deletion
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
    printf("%d - %c \n",p->data,p->color);
    preorderTraversal(p->left);
    preorderTraversal(p->right);
}
void postorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    postorderTraversal(p->left);
    postorderTraversal(p->right);
    printf("%d ",p->data);
}
void inorderTraversal(struct node *p){
    if(p==NULL){
        return;
    }
    inorderTraversal(p->left);
    printf("%d - %c \n",p->data,p->color);
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
