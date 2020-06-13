class Solution {
public:
// TLE
    void sortColors(vector<int>& nums) {
        int ptr1=0,ptr2=nums.size();
        for(;ptr1<ptr2;){
            if(nums[ptr1]==0) ptr1++;
            else if(nums[ptr2]==2) ptr2--;
            else if(nums[ptr1]>nums[ptr2]){
                swap(nums[ptr2],nums[ptr1]);
                ptr1++;
                ptr2--;
            }
        }
    }
};