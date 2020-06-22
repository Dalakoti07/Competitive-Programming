class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find lower bound of target
        int row =-1;
        int a =0,b=matrix.size();
        while(a<=b){
            int mid = (a+b)/2;
            if(matrix[mid][0]==target){
                return true;
            }else if(matrix[mid][0]>target){
                row=b;
                b=mid-1;
            }else{
                row=a;
                a=mid;
            }
        }
        
        // now we have row
        // search col like bs
        if(row==-1) return false;
        a=0,b=matrix[0].size();
        while(a<=b){
            int mid =(a+b)/2;
            if(matrix[row][mid]==target) return true;
            else if (matrix[row][mid]>target) a=mid+1;
            else b =mid-1;
        }
        return false;
    }
};