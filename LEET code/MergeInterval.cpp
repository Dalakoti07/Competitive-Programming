class Solution {
public:
    bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end(),cmp);
        for(int i=0,j=1;i<arr.size() and j<arr.size(); ){
            vector<int> current=vector<int>{arr[i]};
            for(;j<arr.size();){
                if(arr[j][0]<=current[1]){
                    current[1]=arr[j][1];
                    j++;
                }else{
                    ans.push_back(current);
                    i=j;
                    j=i+1;
                }
            }
        }
        // ans.push_back() pushback last element if required
    }
};