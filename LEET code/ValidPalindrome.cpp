class Solution {
public:
    bool isPalindrome(string s) {
        // convert to lowecase
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int i=0,j=s.length();
        for(;i<j;){
            if(!(s[i]>='a' and s[i]<='z')){
                i++;
            }else if(!(s[j]>='a' and s[j]<='z')){
                j--;
            }else{
                if(s[i]==s[j]) {
                    i++;
                    j--;
                }else return false;
            }
        }
        return true;
    }
};