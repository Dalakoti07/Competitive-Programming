class Solution {
public:
    void findAllSubsets(vector<vector<int>>& ans, vector<int> nums){
        if(nums.size()==1){
            ans.push_back(vector<int>{nums[0]});
            ans.push_back(vector<int>());
            return;
        }
        vector<int> vecPassed(nums.begin() + 1, nums.end());
        findAllSubsets(ans,vecPassed);
        int bound=ans.size();
        for(int i=0;i<bound;i++){
            vector<int> tempo=ans[i];
            tempo.insert(tempo.begin(),nums[0]);
            ans.push_back(tempo);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        findAllSubsets(ans,nums);
        return ans;
    }
};