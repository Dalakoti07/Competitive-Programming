class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0,i=0,j=1;
        if(nums.size()==0)
            return count;
        for(;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                    count++;
            }
        }
        return count;
    }
};