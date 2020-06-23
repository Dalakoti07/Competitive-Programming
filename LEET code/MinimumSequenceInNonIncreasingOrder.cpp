class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        // I greedy pick large elem such that subsequence is smallest and easily beats remaining sum
        sort(nums.begin(),nums.end(),greater<int>());
        int n =nums.size();
        // cummulative sum array
        vector<int> cummulativeArr=nums;
        for(int i=1;i<n;i++){
            cummulativeArr[i]+=cummulativeArr[i-1];
        }
        int idx=0,remainingSum;
        for(int i=0;i<n;i++){
            remainingSum=cummulativeArr[n-1] - cummulativeArr[i];
            if(cummulativeArr[i]>remainingSum){
                idx=i;break;
            }
        }
        // copy the array
        vector<int> ans(idx+1,0);
        for(int i=0;i<=idx;i++)
            ans[i]=nums[i];
        return ans;
    }
};