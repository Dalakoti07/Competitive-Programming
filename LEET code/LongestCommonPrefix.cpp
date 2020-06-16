class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size(),count=0;
        if(n==1) return strs[0];
        // find common suffix between first two words and check if that suffix exist in comming 
        string word1= strs[0];
        string word2= strs[1];
        int bound=min(word1.length(),word2.length());
        for(int a=0;a<bound;a++){
            if(word1[a]==word2[a])
                ans+=word1.substr(a,a+1);
        }
        if(ans=="") return "";
        for(int i=2;i<n;i++){
            string word= strs[i];
            int bound=min(word.length(),ans.length());
            string tempAns="";
            for(int i=0;i<bound;i++){
                if(word[i]==ans[i])
                    tempAns+=word.substr(i,i+1);
            }
            if(tempAns.length()<ans.length())
                ans=tempAns;
        }
        return ans;
    }
};