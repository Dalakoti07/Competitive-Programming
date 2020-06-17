class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =nums.size();
        for(int i=0,j=n-1;i<j;){
            if(nums[i]==0 and nums[j]!=0)
                swap(nums[i++],nums[j--]);
            else if(nums[i]!=0) i++;
            else if(nums[j]==0) j--;
        }
    }
};