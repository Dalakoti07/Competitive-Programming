#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllPermutes(vector<vector<int>>& ans,vector<int>& nums,int start, int end){
        if(start==end){
            vector<int> vec=vector<int>{nums[start]};
            ans.push_back(vec);
            return;
        }
        getAllPermutes(ans,nums,start+1,end);
        int boundOuter=ans.size();
        for(int i=0;i<boundOuter;i++){
            int bound =ans[i].size()+1;
            for(int j=0;j<bound;j++){
                vector<int> copyVec=ans[i];
                copyVec.insert(copyVec.begin()+j, nums[start]);
                ans.push_back(copyVec);
            }
        }
        ans.erase(ans.begin(),ans.begin()+boundOuter);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return vector<vector<int>>(1,vector<int>());
        getAllPermutes(ans,nums,0,nums.size()-1);
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    Solution* solution= new Solution();
    while(t--){
        vector<int> vec=vector<int>{1,2,3};
        vector<vector<int>> ans=solution->permute(vec);
    }
}