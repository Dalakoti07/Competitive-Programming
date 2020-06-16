class Solution {
public:
    bool isValid(string s) {
        stack<char> bracesStack;
        int n= s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                bracesStack.push(s[i]);
            }else{
                if(s[i]==')'){
                    if(bracesStack.empty()) return false;
                    if(bracesStack.top()!='(') return false;
                    else bracesStack.pop();
                }else if(s[i]=='}'){
                    if(bracesStack.empty()) return false;
                    if(bracesStack.top()!='{') return false;
                    else bracesStack.pop();
                }else if(s[i]==']'){
                    if(bracesStack.empty()) return false;
                    if(bracesStack.top()!='[') return false;
                    else bracesStack.pop();
                }
            }
        }
        return bracesStack.empty();
    }
};