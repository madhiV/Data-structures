#include<stdio.h>
#include<string.h>
#include<math.h>
char stack[99];
int top=-1,stack2[99];
int isempty(){
	if(top==-1){
		return 1;
	}
	return 0;
}
void push2(int e){
    top++;
    stack2[top]=e;
}
int pop2(){
    int e=stack2[top];
    top--;
    return e;
}
int is_operator(char a){
	switch(a){
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '%':
			return 1;
		default:
			return 0;
	}
}
int postfix_evaluation(char* str){
    int a,b,res,t;
    char c;
    for(int i=0;i<strlen(str);i++){
        if(is_operator(str[i])!=1){
            c=str[i];
            t=str[i]-'0';
            push2(t);
        }
        else{
            switch(str[i]){
                case '+':
                    b=pop2();
                    a=pop2();
                    res=a+b;
                    break;
                case '-':
                    b=pop2();
                    a=pop2();
                    res=a-b;
                    break;
                case '/':
                    b=pop2();
                    a=pop2();
                    res=a/b;
                    break;
                case '*':
                    b=pop2();
                    a=pop2();
                    res=a*b;
                    break;
                case '%':
                    b=pop2();
                    a=pop2();
                    res=a%b;
                    break;
                case '^':
                    b=pop2();
                    a=pop2();
                    res=pow(a,b);
                    break;
            }
            push2(res);
        }
    }
    return pop2();
}
