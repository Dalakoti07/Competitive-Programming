class Solution {
public:
    int numDecodings(string word) {
        int n =word.length();
        if(n==0) return 0;
        if(n<=1){
            if(word[0]=='0') return 0;
            return 1;
        }else if(n==2){
            int nsma=stoi(word)>0;
            if (nsma==0) return 0;
            else if(nsma>0 and nsma<=10 ) return 1;
            else return 2;
        }
        
        if(stoi(word.substr(0,2))<=26){
            return (numDecodings(word.substr(2)))+numDecodings(word.substr(1));
        }
        return numDecodings(word.substr(1));
    }
};