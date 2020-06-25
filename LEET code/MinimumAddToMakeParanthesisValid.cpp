class Solution {
public:
    int minAddToMakeValid(string S) {
        // the one and only thing u should consider is that use stack when asking about parenths 
        int n =S.length();
        stack<char> stacky;
        for(int i=0;i<n;i++){
            if(S[i]==')'){
                if(! stacky.empty()){
                    if(stacky.top()=='(')
                        stacky.pop();
                    else stacky.push(S[i]);
                }
                else stacky.push(S[i]);
            }else
                stacky.push(S[i]);
        }
        return stacky.size();   
    }
    /*
    Other solution

    Basic idea :
    we need to count individual brackets which are not a part of a perfect pair.
    Solution :
    we maintain 2 variables - one for opening bracket and one for closing bracket
    For every open bracket we increase openbracket count.
    For every closing bracket, their can be 2 cases, either its a part of perfect pair or else its incomplete.
    so, if openbracket count is not 0 then decrease openBracket count by 1 as a perfect pair is formed, else increase closing bracket count.
    return open bracket count + closing bracket count

    int minAddToMakeValid(string S) {
	    int openBrac = 0, closingBrac = 0;
        for (char c : S) {
            if (c == '(') {
                openBrac++;
            } else if (openBrac) {
                openBrac--;
            } else {
                closingBrac++;
            }
        }
	    return openBrac + closingBrac;
    }
    */

};