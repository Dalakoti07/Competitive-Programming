class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int OddCount=0,i=0,j=0,n=nums.size();
        int numberofSubArray=0;
        for(;j<n;j++){
            if(nums[j]%2){
                OddCount++;
            }
            cout<<"j: "<<j<<" count: "<<count<<endl;
            if(OddCount==k){
                cout<<"incr, at j:"<<j<<endl;
                numberofSubArray++;
            }
            while(OddCount>=k){
                if(nums[i]%2)
                    OddCount--;
                i++;
            }
        }
        return numberofSubArray;
    }
};