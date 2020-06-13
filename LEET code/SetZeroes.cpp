class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return;
        int m =matrix[0].size();
        set<int> rowsSet,colSet;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rowsSet.insert(i);
                    colSet.insert(j);
                }
            }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rowsSet.find(i) != rowsSet.end() or colSet.find(j) != colSet.end()){
                    matrix[i][j]=0;
                }
            }
        }
        return;
    }
};