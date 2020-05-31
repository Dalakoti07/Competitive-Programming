#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer =0;
        for(int i=0;i<s.length();i++){
            unordered_map<char, int> mappyCounter;
            // cout<<" index"<<i<<" and char is "<<s[i]<<endl;
            mappyCounter[s[i]]=1;
            for(int j=i+1;j<s.length();j++){
                if(mappyCounter.count(s[j])){
                    break;
                }else{
                    mappyCounter[s[j]]=1;
                }
            }
            if(mappyCounter.size()>answer){
                answer=mappyCounter.size();
            } 
        }
        return answer;
    }
};


int main()
{
    int t;
    cin>>t;
	Solution* s=new Solution();
    while(t){
        string input;
        cin>>input;
        cout<<s->lengthOfLongestSubstring(input)<<endl;        
        t--;
    }

}