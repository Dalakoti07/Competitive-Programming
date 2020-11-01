class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),sum=0;
        // for primary diagonal row=col
        for(int i=0;i<n;i++){
            sum+=mat[i][i];
        }
        if(n%2)
            sum-=mat[n/2][n/2];
        //secondary diagonal row = total cols - col -1
        for(int j=n-1;j>=0;j--)
            sum+=mat[n-j-1][j];
        return sum;
    }
};