class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        if(arr.size()==0) return ans;
        sort(arr.begin(),arr.end(),cmp);

        int lastStart=arr[0][0],lastEnd=arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<=lastEnd){
                lastEnd=max(lastEnd,arr[i][1]);
            }else{
                ans.push_back(vector<int>{lastStart,lastEnd});
                lastStart=arr[i][0];
                lastEnd=arr[i][1];
            }

        }
        ans.push_back(vector<int>{lastStart,lastEnd});
        for(int i=0;i<ans.size();i++,cout<<endl){
            for(int j=0;j<ans[i].size();j++)
                cout<<ans[i][j]<<" ";
        }

        return ans;
    }
};