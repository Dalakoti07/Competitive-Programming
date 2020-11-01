class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        // create vector
        int idx=0,freq,val;
        vector<int> ans;
        for(;idx<nums.size();){
            freq=nums[idx++];
            val=nums[idx++];
            if(freq!=0){
                vector<int> temp(freq,val);
                ans.insert(ans.end(),temp.begin(),temp.end());
            }
        }
        return ans;
    }
};