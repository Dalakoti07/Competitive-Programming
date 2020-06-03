#include<bits/stdc++.h>
using namespace std;

// failing 412th case of 430 cases, and then after seeing a solution I relaised a mistake that would have reduced the codebase very effeciently.
// If I take both possiblities that ignore x* or either take x* and return the OR answer respectively
/*class Solution {
public:
    bool isMatch(string s, string pattern) {
        cout<<" string: "<<s<<" pattern: "<<pattern<<"\n";
        
        if(s.length()==0){
            if(pattern.length()==0)
                return true;
            else{
                if(pattern.length()>=1)
                if (pattern.find('*') != std::string::npos){
                    return true;
                }else{
                    return false;
                }
            }
        }
        
        // check for the ending character
        if(pattern.length()>=1)
        if(pattern[pattern.length()-1]!='*' and pattern[pattern.length()-1]!='.'){
            if(pattern[pattern.length()-1]!=s[s.length()-1])
                return false;
        }

        if(pattern.length()>=2)
        if(pattern[1]=='*'){
            if(pattern[0]=='.'){
                if(s[0]>='a' and s[0]<='z'){// always true
                    return isMatch(s.substr(1),pattern);
                }
            }else{
                if(s[0]==pattern[0]){
                    return isMatch(s.substr(1),pattern);
                }else{// ignoring first character 
                    return isMatch(s,pattern.substr(2));
                }
            }
        }
        
        if(pattern[0]=='.'){
            return isMatch(s.substr(1),pattern.substr(1));
        }
        else {
            if(s[0]!=pattern[0]){
                return false;
            }else{
                return isMatch(s.substr(1),pattern.substr(1));
            }
        }
    }
};*/

// this solution is short and better
class Solution {
public:
    bool isMatch(string text, string pattern) {
        if (pattern.empty()) return text.empty();
        bool first_match = (!text.empty() &&
                                    (pattern[0] == text[0] || pattern[0] == '.'));

        if (pattern.length() >= 2 && pattern[1] == '*'){
            return (isMatch(text, pattern.substr(2)) ||
                    (first_match && isMatch(text.substr(1), pattern)));
        } else {
            return first_match && isMatch(text.substr(1), pattern.substr(1));
        }
    }
};

int main(){
    int t;
    cin>>t;
	Solution* s=new Solution();
    while(t){
        string input,pattern;
        cin>>input>>pattern;
        cout<<s->isMatch(input,pattern)<<endl;        
        t--;
    }
}