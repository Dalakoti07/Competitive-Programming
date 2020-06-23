class Solution {
public:
    int balancedStringSplit(string s) {
        // greedly making count+1 as soon as we have Ls=Rs count
        int countOfRs=0, countOfLs=0;
        int n = s.length(),count=0;
        s[0]=='L'? countOfLs++ : countOfRs++;
        for(int i=1;i<n;i++){
            if(s[i]=='L') countOfLs++;
            else countOfRs++;

            if(countOfRs==countOfLs){
                count++;
            }
        }
        return count;
    }
};