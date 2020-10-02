#include<bits/stdc++.h>
using namespace std;

int getid(char ch)
{
    if(ch=='-') return 1;
    if(ch=='+') return 2;
    if(ch=='*') return 3;
    if(ch=='/') return 4;
    if(ch=='(') return 0;
}

void give(string str)
{
	int i=0;
	stack<char> s;
	while(str[i])
	{
		if((isdigit(str[i])))	cout << str[i];
		else if(str[i]=='(')	s.push(str[i]);
		else if(str[i]==')')
			{
			while(str[i]!='(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
			}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(s.size()==0) s.push(str[i]);
			else if(getid(str[i])>getid(s.top()))	s.push(str[i]);
			else {
			while(s.top()!='('&&(getid(str[i])<=getid(s.top()))&&s.size()!=0)
			{
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
			}
			
		}
		i++;
		
	}
	while(s.size())
		{
			cout << s.top();
			s.pop();
		}
}

int main()
{
	string str;
	cin >> str;
	give(str);
	return 0;
}
