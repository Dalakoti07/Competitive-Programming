// optimizing inner loop can avoid TLE
class Solution {
public:
    // beautiful dp, 
    // dp[i] means smallest ways in which u can make i with sum of squares
    // dp[20] = min(dp[19]+1  ,dp[16]+1 ,dp[11]+1 ,dp[4]+1 )
    int numSquares(int n) {
        if(n<=3) return n;
        int dp[n+1];
        // memset(dp,INT_MAX,sizeof(dp)); , causing overflow (INT_MAX +1 = -1)
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=INT_MAX;
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-(j*j)]+1); // +1 means we are taking one square which is j*j 
            }
        }
        // for(int i=0;i<=n;i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        return dp[n];
    }
    
};