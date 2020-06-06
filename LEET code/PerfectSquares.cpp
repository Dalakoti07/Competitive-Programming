// optimizing inner loop can avoid TLE
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1], inf = 0x3f3f3f3f;
        memset(dp, inf, sizeof dp);
        if(n<=3)
            return n;
        for(int i=0;i<=3;i++)
            dp[i]=i;
        // filling the dp array
        for(int i=4;i<=n;i++){
            if(i==pow((int)sqrt(i),2)){
                dp[i]=1;
            }else{
                int limit=i/2;
                for(int j=1;j<=limit;j++){
                    dp[i]=min(dp[i],dp[j]+dp[i-j]);
                }
            }
        }
        // display array
        /*for(int i:dp){
            cout<<i<<" ";
        }
        cout<<endl;*/
        return dp[n];
    }
};