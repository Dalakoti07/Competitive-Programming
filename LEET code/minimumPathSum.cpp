class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp=grid;
        int rows =grid.size(), cols=grid[0].size();

        for(int i=rows-2;i>=0;i--)
            dp[i][cols-1]+=dp[i+1][cols-1];
        for(int i=cols-2;i>=0;i--)
            dp[rows-1][i]+=dp[rows-1][i+1];
        
        for(int i=rows-2;i>=0;i--)
            for(int j=cols-2;j>=0;j--)
                dp[i][j] += min(dp[i+1][j],dp[i][j+1]);
        return dp[0][0];
    }
};