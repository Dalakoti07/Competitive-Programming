class Solution {
public:
    // https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/discuss/504453/cpp-solution
    int minimumSwap(string s1, string s2) {
        int n=s1.length();
        int xWithA=0,xWithB=0,yWithA=0,yWithB=0;
        for(int i=0;i<n;i++)
            if(s1[i]=='x') xWithA++;
            else yWithA++;
        for(int i=0;i<n;i++)
            if(s2[i]=='x') xWithB++;
            else yWithB++;
        if((xWithA+xWithB)%2)
            return -1;
        if((yWithA+yWithB)%2)
            return -1;
        return (abs(xWithB-xWithA)+abs(yWithA-yWithB))/2;
    }
};