#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // simple resursive solution
        if(s.length()==0 or wordDict.size()==0)
            return true;
        string firstWord=wordDict[0];
        // find all the occurences of firstWord and make recursive call
        int count=0;
        size_t index = s.find(firstWord,index+count);
        vector<int> validIndexes;
        while(index!=string::npos){
            validIndexes.push_back(index);
        }
        for(int idx: validIndexes){
            return wordBreak(s.substr(idx,idx+firstWord.length()),wordDict);
        }

    }
};


int main(){
    int t;
    cin>>t;
    string s;
    vector<string> list{"leet","code"};
    Solution* solution = new Solution();
    while(t--){
        cin>>s;
        cout<<solution->wordBreak(s,list)<<endl;
    }
}