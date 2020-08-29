class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // two pointer technique
        int endIdxElemNeg=0,startIdxElemPos=0;
        // considering 0 as positive
        int n =A.size();
        while(startIdxElemPos<n and A[startIdxElemPos]<0){
            startIdxElemPos++;
        }
        endIdxElemNeg=startIdxElemPos-1;
        vector<int> ans;
        while(startIdxElemPos<n and endIdxElemNeg>=0){
            if(pow(A[startIdxElemPos],2)<pow(A[endIdxElemNeg],2)){
                ans.push_back(pow(A[startIdxElemPos],2));
                startIdxElemPos++;
            }
            else {
                ans.push_back(pow(A[endIdxElemNeg],2));
                endIdxElemNeg--;
            }
        }
        while(startIdxElemPos<n)
            ans.push_back(pow(A[startIdxElemPos++],2));
        while(endIdxElemNeg>=0)
            ans.push_back(pow(A[endIdxElemNeg--],2));
        return ans;
    }
};