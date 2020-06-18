class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =nums.size();
        if(n<=1) return ;
        int i=0,j=i+1;
        // all elements before i are good and i hold zeros and j hold non zero
        for(;i<n and j<n;){
            if(nums[i]!=0){
                 i++;j++;
            }
            else{
                if(nums[j]==0){
                    j++;
                }else{
                    swap(nums[i],nums[j]);
                    i=i+1;
                    j++;
                }
            }
        }
    }
};