class Solution {
public:
    int findIfEqual(string haystack,string needle,int idx){
        if(haystack.length()< needle.length()) return -1;
        for(int i=0;i<needle.length();i++)
            if(haystack[i]!=needle[i]) return -1;
        return idx;
    }

    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        int needleSize =needle.length(), haystackSize=haystack.length();
        int a=0;
        while(a<haystackSize){
            if(haystack[a]==needle[0]){
                int ans= findIfEqual(haystack.substr(a),needle,a);
                if(ans!= -1) return ans;
            }
            a++;
        }
        return -1;
    }
};