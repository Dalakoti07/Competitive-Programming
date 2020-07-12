class Solution {
    public:
    // https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/discuss/504453/cpp-solution
    int minimumSwap(string s1, string s2) {
        int ans=0,xy=0,yx=0;
        int n =s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i])
                continue;
            else if(s1[i]=='x')
                xy++;
            else
                yx++;
        }
        if((yx+xy)%2==1)
            return -1;
        if(yx%2)
            ans+=2;
        ans+=xy/2 + yx/2;
        return ans;
    }
};