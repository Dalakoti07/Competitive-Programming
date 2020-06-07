class Solution {
public:
    bool isSubsequence(string small, string large) {
        if(small.length()==0) return true;
        else if (large.length()==0) return small.length()==0;

        if(small[0]==large[0])
            return isSubsequence(small.substr(1),large.substr(1));
        else
            return isSubsequence(small,large.substr(1));
    }
};