class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // n*m log(n*m) will give tle

        // application of binary search
        int row=matrix.size(),col=row? matrix[0].size(): 0;
        int start=0,end=row,mid,startRow,endRow;
        if(row*col == 0) return false;
        // find the lower bound of startRow
        while(start<end){
            mid=(start+end)/2;
            if(matrix[mid][col-1]>=target){
                end=mid;
            }else{
                start=mid+1;
            }
        }
        startRow=start;

        // find the upper bound of 
        start=0;
        end=row;
        while(start<end){
            mid=(start+end)/2;
            if(matrix[mid][0]>target)
                end=mid;
            else
                start=mid+1;
        }
        endRow=start;

        // find the element from startRow to endRow
        for(int i=startRow;i<endRow;i++){
            start=0,end=col;
            while(start<end){
                mid=(start+end)/2;
                if(matrix[i][mid]>=target)
                    end=mid;
                else
                    start=mid+1;
            }
            if(start<col and matrix[i][start]==target)
                return true;
        }
        return false;
    }
};