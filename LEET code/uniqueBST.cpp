/*
recursive solution TLE
class Solution {
public:
    int numTrees(int n) {
        return numTrees(1,n);
    }

    int numTrees(int start,int end){
        if(start>end){
            return 1; // for null to counted as one valid node 
        }else if(start==end){
            return 1;
        }else{
            int answer=0;
            for(int i=start;i<=end;i++){
                int noOfLeftTreesPossible = numTrees(start,i-1);
                int noOfRightTreesPossible = numTrees(i+1,end);
                answer+= noOfLeftTreesPossible* noOfRightTreesPossible;
            }
            return answer;
        }
    }
};*/

