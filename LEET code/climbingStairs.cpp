// the brute force way is to take all possible steps and see if its valid step
// check out explanation in leet code its awesome
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp=vector<int>(n+1,0);
        if(n<=2)
            return n;
        dp[0]=0,dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i] =dp[i-1] + dp[i-2]; // take example of i=3 to get clraity why we didnot do dp[i] = dp[i-1] + 2*dp[i-2]
        }
        return dp[n];
    }
};