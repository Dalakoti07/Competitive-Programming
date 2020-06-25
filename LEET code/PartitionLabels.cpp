class Solution {
public:
    bool ifAllCharsHaveAlsoOccured(int i,set<char>& allCharsInThisPartition, vector<int>& lastIndexOfCharacter){
        for(char c: allCharsInThisPartition){
            if(lastIndexOfCharacter[c-'a'+1]>i) return false;
        }
        return true;
    }

    vector<int> partitionLabels(string word) {
        vector<int> lastIndexOfCharacter= vector<int>(27);
        int n =word.length();
        for(int i=0;i<n;i++){
            lastIndexOfCharacter[word[i]-'a'+1]=i;
        }
        int i=0,start=0,length=0;
        vector<string> ansString;
        set<char> allCharsInThisPartition;
        for(;i<n;i++){
            allCharsInThisPartition.insert(word[i]);
            if(lastIndexOfCharacter[word[i]-'a'+1]==i and ifAllCharsHaveAlsoOccured(i,allCharsInThisPartition,lastIndexOfCharacter)){
                ansString.push_back(word.substr(start,length+1));
                length=0;
                start=i+1;
            }else{
                length++;
            }
        }
        vector<int> ans;
        for(int i=0;i<ansString.size();i++){
            ans.push_back(ansString[i].length());
        }
        return ans;
    }
};