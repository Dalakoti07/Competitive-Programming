class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productAll=1;
        for(int i=0;i<nums.size();i++)
            productAll*=nums[i];
        
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                answer.push_back(productAll/nums[i]);
            else
                answer.push_back(0);
        }
        return answer;
    }
};