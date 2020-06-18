class Solution {
public:
    bool isPalindrome(string s) {
        // convert to lowecase
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int i=0,j=s.length();
        for(;i<j;){
            if(!(s[i]>='a' and s[i]<='z') and !(s[i]>='0' and s[i]<='9')){
                i++;
            }else if(!(s[j]>='a' and s[j]<='z') and !(s[j]>='0' and s[j]<='9')){
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