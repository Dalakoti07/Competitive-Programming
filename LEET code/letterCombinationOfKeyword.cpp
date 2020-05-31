#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<string> mappy{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            vector<string> answer= vector<string>();
            return answer;
        }else if(digits.length()==1){
            vector<string> answer= vector<string>();
            string keywords = mappy[digits[0]-'0'];
            for (char i: keywords){
                string s(1,i);
                answer.push_back(s);    
            }
            return answer;
        }else{
            vector<string> forwardAnswer = letterCombinations(digits.substr(1));
            vector<string> answer=  vector<string>();
            string keywords = mappy[digits[0]-'0'];
            
            for (string each: forwardAnswer){
                for(char i : keywords){
                    string s(1,i);
                    answer.push_back(s+each);    
                }
            }
            return answer;
        }
    }
};

int main(){
    int t;
    string str;
    cin>>t;
    Solution* solution = new Solution();
    while(t--){
        cin>>str;
        vector<string> answer= solution-> letterCombinations(str);
        cout<<"answer is :"<<endl;
        for(string stringy:answer){
            cout<<stringy<<endl;
        }
    }
}