/*
Print operands as they arrive.
If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
If the incoming symbol is a left parenthesis, push it on the stack.
If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.
If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)
*/
#include<bits/stdc++.h>
using namespace std;
// WA a+(b*c)/d+d+e

bool firstCharHasHighPrecedence(char op1,char op2){
    if(op2=='(') return true;
    if(op1=='^' and (op2=='*' or op2=='/')) return true;
    if((op1=='*' or op1=='/') and op2=='^') return false;
    if( op1=='*' or op1=='/') return true;
    else{
        return false;
    }
}

void pushOperatorToStack(stack<char>& stacky,char chary){
    if(stacky.empty()){
        stacky.push(chary);
        return;
    }
    if(stacky.top()=='(')
        stacky.push(chary);
    else{
        while(!stacky.empty() and stacky.top()!='(' and !firstCharHasHighPrecedence(chary,stacky.top())){
            // cout<<"\nline 33\n";
            cout<<stacky.top();
            stacky.pop();
        }
        stacky.push(chary);
    }
    // cout<<"\npushed "<<chary<<"\n";
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        string expression;
        cin>>n>>expression;
        stack<char> stacky;
        for(int i=0;i<n;i++){
            // cout<<"\ni :"<<i<<" -> "<<expression[i]<<"\n";
            if(expression[i]=='('){
                stacky.push(expression[i]);
            }else if(expression[i]==')'){
                while(!stacky.empty() and stacky.top()!='('){
                    cout<<stacky.top();
                    stacky.pop();
                }
                if(!stacky.empty())
                    stacky.pop();
            }else if(expression[i]=='^' or expression[i]=='+' or expression[i]=='-' 
                or expression[i]=='*' or expression[i]=='/'){
                    pushOperatorToStack(stacky,expression[i]);
            }else{
                cout<<expression[i];
            }
        }
        while(!stacky.empty()){
            cout<<stacky.top();
            stacky.pop();
        }
        cout<<endl;
    }
}