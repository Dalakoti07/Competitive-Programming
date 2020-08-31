class Solution {
public:
    // https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window
    int subarraysWithKDistinct(vector<int>& A, int k) {
        // we have to find the subarrays with exact K distinct number, which is very hard so we do other way round that is 
        // this would have been typical sliding window problem if we have subarray with atmost K distinct number
        // we can say exact k = atmost(k) - atmost(k=1)
        return atMost(A,k) - atMost(A,k-1); 
    }
    int atMost(vector<int>& A,int k){
        // find the maxsubarray count with atmax k distinct elements
        map<int,int> temp; // helpful for checking unique elements till now
        int ans=0;
        int l=0,r=0;
        while(r<n){
            temp[A[r]]++;

            while(temp.size()>k){
                temp[A[l]]--;
                if(temp[A[l]]==0)
                    temp.erase(A[l]); // delete if elem freq is 0
                l++;
            }
            ans+=r-l+1; // adding subarray possible when end is r, and start is l, then subarray possible is r-l+1
            r++;
        }
    }
};