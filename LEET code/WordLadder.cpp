class Solution {
public:
    bool distanceIsOne(string word1, string word2){
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        int count=0;
        for(int i=0;i<word1.length();i++){
            if(word1[i]!=word2[i]){
                if (count==1) return false;
                else count++;
            } 
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){
            return 0;
        }
        vector<string> ans;
        int mini=INT_MAX,i=0;
        for(string w : wordList){
            if(distanceIsOne(w,endWord)){
                mini=min(1,mini);
            }else if(distanceIsOne(w,beginWord)){
                vector<string> copyOfWordList=wordList;
                copyOfWordList.erase(copyOfWordList.begin()+i);
                mini=min(mini,1+ladderLength(w,endWord,copyOfWordList));
            }
            i++;
        }
        return mini;
    }
};