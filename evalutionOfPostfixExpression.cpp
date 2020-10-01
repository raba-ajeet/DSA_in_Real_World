#include<bits/stdc++.h>
using namespace std;

//this function to check the character is operator or number
bool is_operator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
	return true;
	return false;
}

//this function solves the equation and returns answer as int 
int eval(char c,int n,int m)
{
	switch(c)
	{
		case '-':
			return n-m;
			break;
		case '*':
			return n*m;
				break;
		case '+':
			return n+m;
				break;
		case '/':
			return n/m;
				break;
		case '%':
			return n%m;
				break;
	}
}

//this is the function where we read the actual string
int solve(string s1)
{
	int i=0;
	stack<char> s;
	while(s1[i]!='\0')
	{
		if(isdigit(s1[i]))	s.push(s1[i]);
		if(is_operator(s1[i]))
		{
			int op2 = s.top( )-'0'; //To convert it into int we subtracted '0'
			s.pop();
			int op1 = s.top()-'0';
			s.pop();
			int ans = eval(s1[i],op1,op2);
			cout << ans << endl;
			s.push(char(ans+'0'));
		}
		i++;
	}
	cout << int(s.top()-'0');
}

int main()
{
	string str;
	cin >> str;
	
	solve(str);
	//cout << str;
	return 0;
 }
