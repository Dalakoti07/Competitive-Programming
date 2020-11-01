class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int count=0;
        count=accumulate(arr.begin(),arr.end(),0);
        // cout<<"all sum "<<count;
        int currLen=3,sum=0;
        for(int i=0;i<arr.size();i++){
            // find the sumOfSegment
            int n=arr.size();
            if(currLen>arr.size())
                break;

            // first sum
            sum=0;
            for(int j=0;j<currLen;j++){
                sum+=arr[j];
            }
            // cout<<"curlen: "<<currLen<<" first half "<<sum<<endl;
            count+=sum;
            // find subsequent sums
            for(int j=currLen,k=0;j<n;j++,k++){
                sum-=arr[k];
                sum+=arr[j];
                // cout<<" adding --> "<<sum<<endl;
                count+=sum;
            }
            // cout<<" end of len "<<currLen<<" and totoal sum is "<<count<<endl;
            currLen+=2;
        }
        return count;
    }
};