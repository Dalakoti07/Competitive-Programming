class Solution {
public:
    bool allAreDone(vector<int>& characterCount){
        for(int f: characterCount)
            if(f>0)
                return false;
        return true;
    }

    void getTheNextChar(vector<int>& characterCount,vector<int> timeArr,int n,int currentTime){
        int idx=INT_MAX;
        for(int i=1;i<=26;i++){
            if(characterCount[i]!=0 and ( (timeArr[i]==-1) or (currentTime > timeArr[i]+n) )){
                idx=min(idx,i);
            }
        }
        timeArr[idx]=currentTime;
        characterCount[idx]--;
    }

    int leastInterval(vector<char>& tasks, int n) {
        // greedy in pick the last recently used element
        vector<int> characterCount(27,0),timeArr(27,-1);
        int len =tasks.size();
        for(int i=0;i<len;i++)
            characterCount[tasks[i]-'A'+1]+=1;
        int totalTime=0;
        while(!allAreDone(characterCount)){
            getTheNextChar(characterCount,timeArr,n,totalTime+1);
            totalTime++;
        }
        return totalTime;
    }
};