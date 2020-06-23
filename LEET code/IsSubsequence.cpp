class Solution {
public:
    /*
    bool isSubsequence(string small, string large) {
        if(small.length()==0) return true;
        else if (large.length()==0) return small.length()==0;

        if(small[0]==large[0])
            return isSubsequence(small.substr(1),large.substr(1));
        else
            return isSubsequence(small,large.substr(1));
    }*/

    bool isSubsequence(string small, string large) {
        // greedy approach would be to match a character at time and move forward
        int i=0,j=0,n=large.length(),m=small.length();
        for(;i<n and j<m;){
            if(small[j]==large[i]) {
                i++;j++;
            }else {
                i++;
            }
        }
        if(i==n){
            if(j==m) return true;
            else return false;
        }
        if(j==m) return true;
        return false;
    }
};