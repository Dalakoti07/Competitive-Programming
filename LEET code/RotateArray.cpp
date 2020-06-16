class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        if(k==n) return ;
        for(int rotate=1;rotate<=k;rotate++){
            int lastElem =nums[n-1];
            for(int i=n-1;i>=1;i--)
                nums[i]=nums[i-1];
            nums[0]=lastElem;
        }
    }
};