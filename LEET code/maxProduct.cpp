class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxy=0;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                maxy=max((nums[i]-1)*(nums[j]-1),maxy);
        return maxy;
    }
};