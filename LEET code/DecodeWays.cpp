class Solution {
public:
    int numDecodings(string word) {
        int n =word.length();
        if(n<=1) return n;
        if(stoi(word.substr(0,2))<=26){
            return (numDecodings(word.substr(2)))+numDecodings(word.substr(1));
        }
        return numDecodings(word.substr(1));
    }
};