class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int row,col,count=0;
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<indices.size();i++){
            row=indices[i][0];
            col=indices[i][1];
            // change array
            // row
            for(int i=0;i<m;i++)
                mat[row][i]++;
            // col
            for(int i=0;i<n;i++)
                mat[i][col]++;
        }
        // count odds, and traverse array
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[i].size();j++)
                if(mat[i][j]%2)
                    count++;
        return count;
    }
};