class Solution {
public:
// failed on [0,2,3] ans is false
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n);
        if(n==0) return false;
        if(n==1) return true;
        dp[0]=nums[0];
        cout<<dp[0]<<" ";
        if(nums[0]==0) return false;
        for(int i=1;i<n-1;i++){
            if(dp[i-1]<i){
                dp[i]=0;
            }else
                dp[i]=max(dp[i-1],i+nums[i]);
            cout<<dp[i]<<" ";
        }
        if(dp[n-2]>=n-1) return true;
        return false;
    }
};