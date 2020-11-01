class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0)
            return vector<int>();
        ans.push_back(nums[0]);
        int currSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currSum+=nums[i];
            ans.push_back(currSum);
        }
        return ans;
    }
};