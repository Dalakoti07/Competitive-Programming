class Solution {
public:
    bool validMatrix(vector<vector<char>>& matrix,int startI,int startJ,int n){
        for(int i=startI;i<=startI+n;i++){
            for(int j=startJ;j<=startJ+n;j++){
                if(matrix[i][j]=='0')
                    return false;
            }
        }
        return true;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        if(matrix.size()==1){
            for(int i=0;i<matrix[0].size();i++){
                if(matrix[0][i]=='1')
                    return 1;
            }    
            return 0;
        }
        // lets try brute force
        int maxArea=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                // cout<<"operating at i:"<<i<<"j: "<<j<<endl;
                if(matrix[i][j]=='1'){
                    maxArea=max(1,maxArea);
                    // traverse diagonally
                    int startI=i,startJ=j;
                    for(int k=1;startI+k<matrix.size() and startJ+k<matrix[i].size();){
                        if(matrix[startI+k][startJ+k]=='1'){
                            // check that all neighbours form matrix of 1
                            if(validMatrix(matrix,startI,startJ,k)){
                                // cout<<"valid matrix from "<<startI<<" "<<startJ<<" radius: "<<k<<endl;
                                if(pow(1+k,2) > maxArea){
                                    maxArea=pow(1+k,2);
                                }
                            }
                            k++;
                        }else{
                            // cout<<"0: at i:"<<startI+k<<" j:"<<startJ+k<<endl;
                            break;
                        }
                    }
                }
            }
        }
        return maxArea;
    }
};