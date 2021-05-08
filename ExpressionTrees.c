#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//structure for stack of nodes
struct node2{
    struct treeNode *val;
    struct node2 *next;
}*head2=NULL,*p2,*n2;
//structure for treeNode
struct TreeNode{
    struct TreeNode *left,*right;
    char data;
}*n3,*root=NULL,*p3;
//Push for node stack
void push2(struct node2 *p2)
{
    n2=(struct node2*)malloc(sizeof(struct node2));
    n2->val=p2;
    n2->next=NULL;
    if(head2==NULL){
        head2=n2;
        return;
    }
    n2->next=head2;
    head2=n2;
}
//Pop for node stack
struct node2 *pop2()
{
    p2=head2;
    head2=head2->next;
    return p2->val;
}
//Structure to create a new Tree node
struct node* newNode(char c){
    n3=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    n3->data=c;
    n3->left=NULL;
    n3->right=NULL;
    return n3;
}

//structure for stack of character nodes
struct node{
    char data;
    struct node *next;
}*head=NULL,*p,*n;
//Push op for char stack
void push(char c){
    n=(struct node*)malloc(sizeof(struct node));
    n->data=c;
    n->next=NULL;
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
}
//Pop op for char stack
char pop()
{
    char e=head->data;
    head=head->next;
    return e;
}
//To check whether char is operator or not
int isoperator(char c){
    switch(c){
    case '-':
    case '+':
    case '*':
    case '/':
    case '^':
    case '%':
    case '(':
    case ')':
        return 1;
    default:
        return 0;
    }
}
//To find precedence of the character
int char_precedence(char c){
    switch(c){
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '%':
    case '/':
        return 2;
    case '^':
        return 3;
    }
}
void traverse(struct TreeNode *p3){
    if(p3==NULL){
        return;
    }
    traverse(p3->left);
    printf("%c ",p3->data);
    traverse(p3->right);
}
//infix to postfix
char* infix_to_postfix(char e[],char post[]){
    int j=0;
    char c;
    for(int i=0;i<strlen(e);i++){
        c=e[i];
        if(c=='('){
            push(c);
           }
        else if(isoperator(c)==0){
            post[j]=c;
            j++;
        }
        else{
            if(c==')'){
            while(head->data!='('){
                    post[j]=pop();
                    j++;
                  }
            pop();
            }
            else if(head==NULL || char_precedence(c)>char_precedence(head->data)){
                push(c);
            }
            else if(char_precedence(c)<=char_precedence(head->data)){
                while(char_precedence(c)<=char_precedence(head->data)){
                    post[j]=pop();
                    j++;
                    if(head==NULL){
                        break;
                    }
                }
                push(c);
            }
        }
    }
    while(head!=NULL){
        post[j]=pop();
        j++;
    }
    post[j]='\0';
    return post;
}
int main()
{
    char e[100],post[100]={},c;
    printf("Enter the infix expression : ");
    gets(e);
    printf("The postfix expression is : %s\n",infix_to_postfix(e,post));
    //expression Tree
    for(int i=0;i<strlen(post);i++){
        c=post[i];
        if(isoperator(c)==0){
            push2(newNode(c));
        }
        else{
            p3=newNode(c);
            p3->right=pop2();
            p3->left=pop2();
            push2(p3);
        }
    }
    root=pop2();//root will have the root of the treenode...
    traverse(root);
    return 0;
}
