class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if(N==0)
            return;
        
		// Transpose of Matrix , it is inplace.
        for(int i=0; i<N; i++) 
        {
            for(int j=0; j<i; j++) 
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Reverse the Matrix Row-wise
        for(int i=0; i<N; i++) 
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        return;
    }
};