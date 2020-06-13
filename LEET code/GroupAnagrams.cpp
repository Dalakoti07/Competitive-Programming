class Solution {
public:
    bool areTwoWordsEqual(vector<vector<int>>& arr, int a,int b){
        for(int i=1;i<=26;i++){
            if(arr[a][i]!=arr[b][i]) return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& words) {
        vector<vector<int>> arr(words.size(),vector<int>(27,0));
        int i=0;
        for(string w: words){
            for(int j=0;j<w.length();j++){
                arr[i][j]=1;
            }
            i++;
        }
        vector<vector<string>> ans;
        for( int i=0;i<words.size();i++){
            vector<string> tempo= vector<string>{words[i]};
            for(int j=i+1; j<words.size();j++){
                if(areTwoWordsEqual(arr,i,j)){
                    tempo.push_back(words[j]);
                    words.erase(words.begin()+j);
                }
            }
            ans.push_back(tempo);
        }
        return ans;
    }
};