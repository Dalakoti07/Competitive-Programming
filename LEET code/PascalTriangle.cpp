class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0) return ans;
        if(numRows==1) {
            ans.push_back(vector<int>{1});
            return ans;
        }
        if(numRows==2){
            ans.push_back(vector<int>{1});
            ans.push_back(vector<int>{1,1});
            return ans;
        }
        ans.push_back(vector<int>{1}    );
        ans.push_back(vector<int>{1,1});
        for(int i=2;i<numRows;i++){
            vector<int> tempo=vector<int>{1};
            for(int j=0;j<ans[i-1].size()-1;j++){
                tempo.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            tempo.push_back(1);
            ans.push_back(tempo);
        }
        return ans;
    }
};  