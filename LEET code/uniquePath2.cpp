// avoiding overflow hack, line 40
// and moving one condition to logical and earned 8ms to 4ms

typedef unsigned long long ull;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));

        if(obstacleGrid.size()==0 or obstacleGrid[0].size()==0)
            return 0;
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)
            return 0; // if destination is obstacle then we cannot reach it in any way thus 0
        int rows=obstacleGrid.size();
        int columns=obstacleGrid[0].size();
        if(rows==1 and columns==1){
            if (obstacleGrid[rows-1][columns-1])
                return 0;
            else
                return 1;
        }
        dp[rows-1][columns-1]=1;
        // base cases are set to 1 i.e last row and last column if they are not obstacle
        // for last row
        for(int i=columns-2;i>=0;i--){
            if(obstacleGrid[rows-1][i]==0 and dp[rows-1][i+1]==1){
                dp[rows-1][i]=1;
            }
        }
        // for last column
        for(int i=rows-2;i>=0;i--){
            if(obstacleGrid[i][columns-1]==0 and dp[i+1][columns-1]==1){
                dp[i][columns-1]=1;
            }
        }
        // now all cells are marked as 0, except those which are base case and not obstacle
        for(int i=rows-2;i>=0;i--){
            for(int j=columns-2;j>=0;j--){
                if(obstacleGrid[i][j]==0){
                    dp[i][j]= int (dp[i+1][j] + ull(dp[i][j+1]));
                }// if dp[i][j] is obstacle let it remain 0
            }
        }
        /*
        for (int i = 0; i < dp.size(); i++,cout<<"\n"){
            for (int j = 0; j < dp[i].size(); j++){
                cout << dp[i][j]<<" ";
            }
        }*/
        return dp[0][0];
    }
};