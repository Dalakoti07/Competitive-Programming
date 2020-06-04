#include<bits/stdc++.h>
using namespace std;
/*
    Recurive solution
    int minDistance(string word1, string word2) {
        if(word1.length()==0){
            return word2.length();
        }else if(word2.length()==0){
            return word1.length();
        }

        if(word2[0]==word1[0])
            return minDistance(word1.substr(1),word2.substr(1));
        else
            return 1 + min(minDistance(word2.substr(0,1)+word1,word2)
                    ,min(minDistance(word1.substr(1),word2),minDistance(word1.replace(0,1,word2.substr(0,1)),word2)));
        
    }
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1));
        int m=word1.length(),n=word2.length();
        // dp[i][j] denotes that min editDistance required if we take word1[last i chars] and word2[last j chars]
        // in tutorials and geek for geeks its given wrong
        // fill the base-cases
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0){
                    dp[i][j] = i==0 ? j : i;
                }
                else if(word1[m-i]==word2[n-j]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
                }
                // cout<<dp[i][j]<<" ";
            }
        }
        return dp[m][n];
    }
};

int main(){
    int t;
    cin>>t;
    Solution* solution = new Solution(); 
    while(t--){
        string a,b;
        cin>>a>>b;
        cout<<solution->minDistance(a,b)<<"\n";
    }
}