class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1-nums[0];
        int sum = ((n+1)*n)/2;
        for(auto i:nums){
            sum-=i;
        }
        return sum;
    }
};