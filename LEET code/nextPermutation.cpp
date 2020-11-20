class Solution {
public:
    void reverse(vector<int>& arr,int start){
        int n =arr.size();
        for(int i=start,j=n-1;i<j;i++,j--){
            swap(arr[i],arr[j]);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        bool found=false;
        int n =nums.size(),idx;
        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                found=true;
                idx=i;
                break;
            }
        }
        if(!found)
            reverse(nums,0);
        else{
            // cout<<"dip found at :"<<idx<<" elem is "<<nums[idx]<<endl;
            idx--;
            //find elem just great than idx
            int justGreatsIdx=-1,delta=INT_MAX;
            for(int i=idx+1;i<n;i++){
                if(delta>=nums[i]-nums[idx] and (nums[i]-nums[idx] >0 )){
                    delta=nums[i]-nums[idx];
                    justGreatsIdx=i;
                }
            }
            // cout<<"Just great found at "<<justGreatsIdx<<endl;
            swap(nums[idx],nums[justGreatsIdx]);
            reverse(nums,idx+1);
        }
    }
};