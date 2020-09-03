class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // algo is this :- startrange is min(nums[0][last],nums[1][last],..............,nums[nums.size()-1][last])
        // endrange is max(nums[0][last],nums[1][last],..............,nums[nums.size()-1][last])
        int n =nums.size();
        int startrange=INT_MAX,endrange=INT_MIN;
        for(int i=0;i<n;i++){
            startrange=min(startrange,nums[i][nums[i].size()-1]);
            endrange=min(endrange,nums[i][nums[i].size()-1]);
        }
        vector<int> ans;
        // now iterate from startrange to end range, 
        for(int x=startrange;x<)
    }
};