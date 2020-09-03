class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        // S = "loveleetcode", C = 'e'
        // toLeft means short distance from 
        vector<int> toLeft(S.size());toRight(S.size());
        if(S[0]==C)
            toLeft[0]=0;
        else
            toLeft[0]=INT_MAX;
        for(int i=1;i<toLeft.size();i++){
            
        }
        for(int i=0;i<toRight.size();i++){

        }
    }
};