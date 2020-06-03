class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp =nums;
        for(int i=1;i<dp.size();i++){
            dp[i] = max(dp[i],dp[i-1]+dp[i]);
        }
        auto maximum =max_element(std::begin(dp),std::end(dp));
        return *maximum;
    }
};