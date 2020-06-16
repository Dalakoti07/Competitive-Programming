class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> numbersMap;
        for(int i=0;i<nums.size();i++){
            if(numbersMap.count(nums[i])==1){
                numbersMap[nums[i]]++;
            }else{
                numbersMap[nums[i]]=1;
            }
        }
        int ans,n=nums.size()/2;
        for(auto iter: numbersMap){
            if(iter.second> n){
                ans=iter.first;break;
            }
        }
        return ans;
    }
};