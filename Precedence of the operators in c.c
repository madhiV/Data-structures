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
