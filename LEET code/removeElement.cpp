class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0,n=nums.size();
        int l=0,r=n-1;
        // if we get the val at any index, than swap it to last
        while(l<=r){
            if(l==r){
                if(nums[l]==val)
                    count++;
                break;
            }
            if(nums[l]==val){
                // swap it by not val value
                while(nums[r]==val and r>l){
                    r--;
                    count++;
                }
                swap(nums[l],nums[r]);
                r--;
                count++;
            }
            l++;
        }
        return n-count;
    }
};