class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        if(rows==0)
            return false;
        int cols=matrix[0].size();
        // finding row and then col seems right but, the whole matrix is like a sorted array if we see it row-wise 
        // thus a simple binary search in whole matrix would work
        // so this problem is bonary search in ordered array
        int midIdx,start=0,end=rows*cols-1;
        while(start<=end){
            midIdx=(start+end)/2;
            if(matrix[midIdx/cols][midIdx%cols]==target)
                return true;
            else if(matrix[midIdx/cols][midIdx%cols]<target)
                start=midIdx+1;
            else
                end=midIdx-1;
        }
        return false;
    }
};