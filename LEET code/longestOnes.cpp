class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        /*
            The approach is of sliding window protocol which says that in each window (window of var size) find
            zeroes count, now zeroes count in each window must be <=k, and we have to find the maxLen of such window
            // The solution is beautiful 
        */

        int l=0,r=0,n=A.size(),maxLen=INT_MIN,count=0;
        for(;r<n;r++){
            if(A[r]==0)
                count++;
            while(count>k){
                if(A[l]==0)
                    count--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};