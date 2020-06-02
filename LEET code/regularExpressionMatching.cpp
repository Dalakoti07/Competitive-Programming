#include<bits/stdc++.h>
using namespace std;

class Solution {
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