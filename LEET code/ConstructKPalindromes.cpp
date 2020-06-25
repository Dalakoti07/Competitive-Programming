class Solution {
public:
    // wa, for aaa , we need to count odd occurence count also
    /*
    bool canConstruct(string s, int k) {
        int evenCounts=0, oddCounts=0;
        unordered_map<char,int> mappy;
        for(int i=0;i<s.length();i++){
            if(mappy.count(s[i])==0)
                mappy[s[i]]=1;
            else 
                mappy[s[i]]+=1;
        }
        for(auto iter:mappy){
            if(iter.second %2 ==0) evenCounts++;
            else oddCounts++;
        }

        if(evenCounts>=oddCounts){
            if(k<oddCounts){
                return false;// not using all chars
            }else return true;
        }else{
            int remaining = oddCounts-evenCounts;
            k-=evenCounts;
            if(remaining==k) return true;
            return false
        }
    }
    */
    // valid solution https://leetcode.com/problems/construct-k-palindrome-strings/discuss/696013/share-my-easy-java-solution~~~!-(beating-97)
    bool canConstruct(string s, int k) {
        vector<int> counts=vector<int>(26,0);

        for(int i=0;i<s.length();i++)
            counts[s[i]-'a']++;
        
        if(k>s.length()) return false;
        // now even chars can be coupled to make any number of palindromes
        // but if we have odd nums of characters, like 3 a's or 5 a's then we must place them in middle or use as seprate plaindrome of length one
        // we count all chars which have odd counts, if allOddcount > k, it means we are not using all chars, otherwise true
        int county=0;
        for(int i=0;i<26;i++)
            if(counts[i]%2==1)
                county++;
        return k>= county;
    }
};