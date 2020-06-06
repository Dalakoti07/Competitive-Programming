// TLE, standard solution uses 2d dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0) return -1;
        vector<long> dp(amount+1,INT_MAX);
        // fill the base case
        for(int i:coins){
            if(i<=amount){
                dp[i]=1;
            }
        }
        dp[0]=0;
        // fill the dp array
        for(int i=1;i<=amount;i++){
            int limit= i/2;
            for(int j=1;j<=limit;j++){
                dp[i]=min(dp[i],dp[j]+dp[i-j]);
            }
        }
        for(int d:dp){cout<<d<<" ";}
        if(dp[amount]==INT_MAX){dp[amount]=-1;}
        return dp[amount];
    }
};