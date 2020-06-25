class Solution {
public:
    bool helperIfCanBreak(string s,vector<int>& vecy){
        for(int i=0;i<s.size();i++){
            // find a greater or equal char in vec
            int curr= s[i]-'a' +1;
            int pos=curr;
            for(;pos<=26;pos++){
                if(vecy[pos]!=0) {
                    vecy[pos]-=1;
                    break;
                }
            }
            if(pos==27) return false;
        }
        return true;
    }

    bool checkIfCanBreak(string s1, string s2) {
        // greedy, for each character of s1 we are seeing we are corresponding char >= in s2, and checking vice versa
        vector<int> countStringA=vector<int>(27,0);
        vector<int> countStringB=vector<int>(27,0);

        for(int i=0;i<s1.length();i++){
            countStringA[s1[i]-'a'+1]++;
        }

        for(int i=0;i<s2.size();i++)
            countStringB[s2[i]-'a'+1]++;

        if(helperIfCanBreak(s1,countStringB))
            return true;
        if(helperIfCanBreak(s2,countStringA))
            return true;
        return false;
    }
};