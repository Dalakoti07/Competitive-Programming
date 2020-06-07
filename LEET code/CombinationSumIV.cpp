// failing case [1,2,3,4,5] and target is 6
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector(target+1,0));

        // make first col as 1, when target is 0, and nums have some values of not, there is always a 1 way i.e {}
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    if(j-dp[i]>=0)
                        dp[i][j]=dp[i-1][j-dp[i]] + dp[i][j-dp[i]] + dp[i-1][j];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        for(int i=0;i<=n;i++,cout<<endl){
            for(int j=0;j<=target;j++){
                cout<<dp[i][j]<<" ";
            }
        }
        return dp[n][target]; 
    }
};