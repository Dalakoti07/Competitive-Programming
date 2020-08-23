class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> answer(nums.size());
        answer[0]=1;
        int n =nums.size();
        // calculate products from left
        for(int i=1;i<n;i++)
            answer[i]=answer[i-1]*nums[i-1];
        
        // calculate products from right
        int right=nums[n-1];
        for(int i=n-2;i>=0;i--){
            answer[i]*=right;
            right*=nums[i];
        }
        return answer;
    }
};