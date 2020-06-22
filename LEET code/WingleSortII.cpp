class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> ans=nums;

        sort(ans.begin(),ans.end());
        // override nums
        int j=0;
        for(int i=0;i<nums.size();i+=2,j++){
            nums[i]=ans[j];
        }

        for(int i=1;i<nums.size();i+=2,j++){
            nums[i]=ans[j];
        }
        return ;
    }
};