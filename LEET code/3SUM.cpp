class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums,nums+size);
        vector<vector<int>> answer;
        for(int i=0;i<size;i++){
            for(int j=i+1 ;j<size;j++){
                for(int k= j+1;k<size;k++){
                    if(nums[i]+nums[j]+nums[k]  == 0 ){
                        vector<int> set = vector<int>{nums[i],nums[j],nums[k]};
                        answer.push_back(set);
                    }
                }
            }
        }
        return answer;
    }
};