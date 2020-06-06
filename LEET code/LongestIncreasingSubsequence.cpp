class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // each dp[i] denote maxLIS by considering all elements with idx < i
            if(nums.size()==0) return 0;
            if(nums.size()==1) return 1;
            int n=nums.size();
            vector<int> dp(n,1);
            for(int i=0;i<nums.size()-1;i++){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]>nums[i]){
                        dp[j]=max(dp[j],dp[i]+1);
                    }

                }
            }
            return *max_element(dp.begin(),dp.end());
            // [1,3,6,7,9,4,10,5,6] would explain why max_elem() not dp[n-1]
    }
};