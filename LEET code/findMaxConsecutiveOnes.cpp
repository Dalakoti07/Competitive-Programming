class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,n=nums.size(),maxLen=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                maxLen=max(maxLen,count);
                count=0;
            }else{
                count++;
            }
        }
        maxLen=max(maxLen,count);
        return maxLen;
    }
};