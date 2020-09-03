class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // rec functions
        map<int,int> mappy;
        for(int i:nums1)
            mappy[i]++;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            auto itr=mappy.find(nums2[i]);
            if(itr!=mappy.end() and (mappy[nums2[i]])!=0){
                ans.push_back(nums2[i]);
                mappy[nums2[i]]-=1;
            }
        }
        return ans;
    }
};