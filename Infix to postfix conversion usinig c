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
void push(char e){
    top++;
	stack[top]=e;
	//printf("pushed %c\n",e);
}
char pop(){
    char e;
	if(isempty()==1){
		printf("E");
		return -1;
	}
	e=stack[top];
	top--;
	//printf("poped %c\n",e);
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
int operator_precedence(char a){
	switch(a){
		case ')':
		case '(':
			return 0;
		case '^':
			return 3;
		case '*':
		case '/':
		case '%':
			return 2;
		case '+':
		case '-':
			return 1;
	}
}
char* infix_to_postfix(char *str,char* ans){
	char t[1];
	int i,j=0;
	for(i=0;i<strlen(str);i++){
		if(is_operator(str[i])==1){
			if(str[i]=='('){
				push(str[i]);
				continue;
			}
			else if(str[i]==')'){
					while(stack[top]!='('){
						ans[j]=pop();
						j++;
					}//6+4/2-3*2+5// 6 4 2 / + 3 2 * - 5 +
					pop();
					continue;
			    }
			else{
				if(top==-1){
				    push(str[i]);
				}
				else if(operator_precedence(str[i])>operator_precedence(stack[top])){
					push(str[i]);
				}
				else{
					while(operator_precedence(str[i])<=operator_precedence(stack[top]) && top!=-1){
						ans[j]=pop();
						j++;
					}
					push(str[i]);
				}
			}
		}
		else{
			ans[j]=str[i];
			j++;
		}
	}
	while(isempty()==0){
	    ans[j]=pop();
		j++;
	}
	return ans;
}
