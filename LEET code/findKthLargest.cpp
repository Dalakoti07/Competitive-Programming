class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // make max heap of nums and perform deletion k times
        make_heap(nums.begin(),nums.end());
        k--;
        while(k!=0){
            // see the docs
            pop_heap(nums.begin(),nums.end());
            nums.pop_back();
            k--;
        }
        // for(int n:nums)
        //     cout<<n<<" ";
        return nums.front();
    }
};