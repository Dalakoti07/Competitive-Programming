class Solution {
public:
    int helper(string word, int ans=0){
        int n =word.length();
        if(n==0) return ans;
        else if(n==1) return ans+(word[0]-'A'+1);
        return int(pow(26,word.substr(1).length())) * (word[0]-'A'+1) + helper(word.substr(1));
    }

    int titleToNumber(string word) {
        int n =word.length();
        if(n==0) return 0;
        return helper(word);
    }
};