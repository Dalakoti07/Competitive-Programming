class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        if(n==0)
            return ans;
        ans[n-1]=-1;
        int maxy=-1;
        for(int i=n-2;i>=0;i--){
            maxy=max(maxy,arr[i+1]);
            ans[i]=maxy;
        }
        return ans;
    }
};