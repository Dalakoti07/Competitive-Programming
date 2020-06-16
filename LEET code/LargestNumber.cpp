class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsString;
        for(int i:nums){
            numsString.push_back(to_string(i));
        }
        vector<string> dp(nums.size());
        dp[0]=numsString[0];
        for(int i=1;i<numsString.size();i++){
            // check if numsString[i] is greater or dp[i-1]
            // if(above true) then dp[i]=numsString[i]+dp[i-1];
            // else dp[i]=dp[i-1]+numsString[i];
            if(dp[i-1][0]<numsString[i][0]){
                dp[i]=numsString[i]+dp[i-1];
            }
            else{
                dp[i]=dp[i-1]+numsString[i];
            }
        }
        return dp[numsString.size()-1];
    }
};