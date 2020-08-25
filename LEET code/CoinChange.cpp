class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int dp[amount+1];
        // memset(dp,-1,sizeof(dp));
        sort(begin(coins), end(coins));
        dp[0]=0;
        
        for(int i=1;i<=amount;i++){
            
            dp[i]=INT_MAX;
            for(int c:coins){
                if(i-c<0) break;
                // this dp equation does not make a much sense, so think that its somewhat overkill
                // dp[i]=min(dp[i],dp[j]+dp[i-j]);
                if(dp[i-c]!=-1){
                    dp[i]=min(dp[i],dp[i-c]+1);
                }
            }
            if(dp[i]==INT_MAX)
                dp[i]=-1;
            
        }
       
        return dp[amount];
    }
};