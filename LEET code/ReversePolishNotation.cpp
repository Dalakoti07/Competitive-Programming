class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calculationStack;
        int a,b;
        for(string t:tokens){
            if(t=="+" or t=="-" or t=="*" or t=="/"){
                b=calculationStack.top();
                calculationStack.pop();
                a=calculationStack.top();
                calculationStack.pop();
                if(t=="+")
                    calculationStack.push(a+b);
                else if(t=="-")
                    calculationStack.push(a-b);
                else if(t=="*")
                    calculationStack.push(a*b);
                else
                    calculationStack.push(a/b);
            }else{
                calculationStack.push(stoi(t));
            }
        }
        return calculationStack.top();
    }
};