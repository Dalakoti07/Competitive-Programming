class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,1));

        // fill the dp array from bottom to top, base cases which is last row and last column are already made 1
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=dp[i+1][j] + dp[i][j+1];
            }
        }
        for (int i = 0; i < dp.size(); i++,cout<<"\n"){
            for (int j = 0; j < dp[i].size(); j++){
                cout << dp[i][j]<<" ";
            }
        }

        return dp[0][0];
    }
};