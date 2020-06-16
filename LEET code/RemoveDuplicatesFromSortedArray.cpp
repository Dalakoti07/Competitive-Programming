class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int i=0,j=1,currentElem=nums[0];
        while(j<n){
            if(nums[j]!=currentElem){
                nums[i+1]=nums[j];
                currentElem=nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};