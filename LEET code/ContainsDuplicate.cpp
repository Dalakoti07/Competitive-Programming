class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> counterForNumber;
        for(int i=0;i<nums.size();i++){
            if(counterForNumber.find(nums[i])!=counterForNumber.end())
                return true;
            else counterForNumber[nums[i]]=1;
        }
        return false;
    }
};