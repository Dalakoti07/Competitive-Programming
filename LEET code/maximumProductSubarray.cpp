class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        vector<int> dpPositive(n,0);
        vector<int> dpNegative(n,0);

        dpNegative[0]=nums[0];
        dpPositive[0]=nums[0];

        for(int i=1;i<n;i++){
            dpPositive[i]=max(nums[i],dpPositive[i-1]*nums[i]);
            dpNegative[i]=nums[i]*dpPositive[i-1];
        }
        int a= *max_element(dpPositive.begin(),dpPositive.end());
        int b =*max_element(dpNegative.begin(),dpNegative.end());
        return max(a,b);
    }
};