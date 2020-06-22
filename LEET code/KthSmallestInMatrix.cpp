class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int totalCols = matrix[0].size();
        int totalRows = matrix.size();
        if(totalRows==1){
            return matrix[0][k-1];
        }
        if(totalCols==1){
            return matrix[0][k-1];
        } 
        int row =(k-1)/ matrix[0].size();
        int col =k- row*(matrix[0].size())-1;
        return matrix[row][col];
    }
};