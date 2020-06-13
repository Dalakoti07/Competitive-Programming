class Solution {
public:
    int BSUpperBound(vector<int> nums,int n,int target){
        int left=0,right=n-1,mid=n/2,res=-1;
        while(left<=right){
            mid=(left+right)/2;
            // cout<<"mid: "<<mid;
            if(target==nums[mid]){
                res=mid;
                left=mid+1;
            }else if(target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return res;
    }
    
    int BSLowerBound(vector<int> nums,int n,int target){
        int left=0,right=n-1,mid=n/2,res=-1;
        while(left<=right){
            mid=(left+right)/2;
            // cout<<"mid: "<<mid;
            if(target==nums[mid]){
                res=mid;
                right=mid-1;
            }else if(target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1,-1};
        int n = nums.size();
        if(n==1){
            if(target==nums[0]){
                return vector<int>{0,0};
            }
        }
        ans[0]= BSLowerBound(nums,n,target);
        ans[1]= BSUpperBound(nums,n,target);
        return ans;
    }
};