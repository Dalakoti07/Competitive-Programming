class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i=0,j=0;
        int n=A.size(),m=B.size();
        for(;i<n and j<m;){
            int olStart,olEnd;
            olStart=max(A[i][0],B[j][0]);
            olEnd=min(A[i][0],B[j][1]);
            if(olStart<=olEnd)
                ans.push_back(vector<int>{olStart,olEnd});
            // Remove the interval with the smallest endpoint
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};