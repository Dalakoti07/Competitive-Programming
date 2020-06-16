class Solution {
public:
    int titleToNumber(string word) {
        int n =word.length();
        if(n==0) return 0;
        if(n==1) return word[0]-'A'+1;
        char first=word[0];
        int value =(first-'A'+1)*26 ;
        int forwardAns= titleToNumber(word.substr(1));
        return value+forwardAns;
    }
};