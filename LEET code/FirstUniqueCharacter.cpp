class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charCount(27,0);
        int n =s.length();
        if(n==1) return 0;
        for(int i=0;i<n;i++)
            charCount[s[i]-'a'+1]+=1;
        
        // now check which is answer
        for(int i=0;i<n;i++)
            // cout<<char('a'+i-1)<<": "<<charCount[i]<<endl;
            if(charCount[s[i]-'a'+1]==1) return i;
        return -1;
    }
};