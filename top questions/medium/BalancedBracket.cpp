#include<bits/stdc++.h>
using namespace std;

bool balancedBrackets(string str) {
	stack<char> charStack;
	int n=str.size();
	for(int i=0;i<n;i++){
		char elem=str[i];
		if(elem=='(' or elem=='[' or elem=='{'){
			charStack.push(elem);
		}else if(elem==')' or elem==']' or elem=='}'){
			if(charStack.size()==0)
				return false;
			if(elem==')'){
				if(charStack.top()!='(')
					return false;
				charStack.pop();
			}
			else if(elem==']'){
				if(charStack.top()!='[')
					return false;
				charStack.pop();
			}
			else if(elem=='}'){
				if(charStack.top()!='{')
					return false;
				charStack.pop();
			}
		}
	}
    return charStack.empty();
}
