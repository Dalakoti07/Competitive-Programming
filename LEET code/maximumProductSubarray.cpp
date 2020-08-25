class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];

        /* // O n^2 solution
        // this is brute force seeing all the subarray
        vector<int> dp(n);
        dp[0]=nums[0];
        // dp[i] denotes max product subarray ending at i
        for(int i=1;i<n;i++){
            // explore all the subarray from i to 0
            dp[i]=nums[i];
            int prod=nums[i];
            for(int j=i-1;j>=0;j--){
                prod*=nums[j];
                dp[i]=max(dp[i],prod);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        return ans;
        */
        // https://leetcode.com/problems/maximum-product-subarray/discuss/759813/C%2B%2B-easy-solution-O(1)-space-and-O(n)-time-complexity
        // r is answer, which is max product of subarray
        int r=nums[0];
        int maxi=r;
        int mini=r;
        // maxi means max till index i, mini means min till index i
        // if we get -ve number than max become min and min become max after multiplication, thus we swap these both
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(mini,maxi);
            }
            maxi=max(nums[i],nums[i]*maxi); // maxi will be  if we get nums[i] as 0, we take max and 0 is not included in 
            mini=min(nums[i],nums[i]*mini); // mini is maintained so that we can invert the smallest number to become greatest when multiplied with -ve number
            r=max(r,maxi); // r as earlier stated is answer
        }
        return r;
    }
};