class Solution {
public:
    char maxFreq(vector<int>& freq,char lastChar='\0'){
        int idx=-1,maxy=INT_MIN;
        for(int i=0;i<26;i++){
            if(freq[i]>maxy and lastChar!=char('a'+i) and freq[i]!=0){
                maxy=freq[i];
                idx=i;
            }
        }
        if(idx!=-1){
            freq[idx]--;
            return char('a'+idx);
        }else{
            return 'X';
        }
    }

    string reorganizeString(string S) {
        vector<int> freq(26,0);
        for(int i=0;i<S.length();i++)
            freq[S[i]-'a']++;
        string ans="";
        string fun(1,maxFreq(freq));
        ans+=fun;
        char lastChar=ans[0];
        for(int i=1;i<S.length();i++){
            string funString (1,maxFreq(freq,lastChar));
            lastChar=funString[0];
            if(lastChar=='X')
                return "";
            ans+=funString;
        }
        return ans;
    }
};