#include<bits/stdc++.h>
using namespace std;

/*
    Solution giving TLE, on input "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"
    "a*******b"
    We should use DP
*/
class Solution {
public:
    bool isMatch(string text, string pattern) {
        if(pattern.empty())
            return text.empty();
        // because pattern can't be empty here
        bool firstCharacterMatching = (!text.empty() && (pattern[0] == text[0] || pattern[0] == '?' || pattern[0]=='*'));
        if(pattern[0]=='*'){
            return (isMatch(text,pattern.substr(1))) or (firstCharacterMatching and isMatch(text.substr(1),pattern));
        }else{
            return firstCharacterMatching and isMatch(text.substr(1),pattern.substr(1));
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