class Solution {
public:
    int rob(vector<int>& nums) {
        // problem is same as finding max sum, we can't use adjacent elements, and more over this is circular and caveat
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        vector<int> firstRemoved(nums.begin()+1,nums.end());
        vector<int> lastRemoved(nums.begin(),nums.end()-1);
        return max(houseRobbery(firstRemoved),houseRobbery(lastRemoved));
    }

    int houseRobbery(vector<int>& nums){
        // dp[i] in array tells max profit till index i,
        for(int val:nums){
            cout<<val<<" ";
        }
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]);

        nums[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            nums[i]= max(nums[i-2]+nums[i],nums[i-1]);
        }
        return nums[nums.size()-1];
    }
};