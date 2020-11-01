class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        if(n==0)
            return ans;
        int firstHalf=0,secondHalf=n;
        while(firstHalf<n){
            ans.push_back(nums[firstHalf]);
            ans.push_back(nums[secondHalf]);
            firstHalf++;
            secondHalf++;
        }
        return ans;
    }
};