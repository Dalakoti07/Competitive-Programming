class Solution 
{
public:
    int minDominoRotations(vector<int>& A, vector<int>& B){
        // greedy approach 
        int n=A.size();
        vector<int> freqA(6,0),freqB(6,0);
        for(int i:A){
            freqA[i-1]++;
        }
        for(int i:B){
            freqB[i-1]++;
        }
        int maxFreqA=INT_MIN,maxFreqB=INT_MIN,maxFreqAVal,maxFreqBVal;
        for(int i=0;i<n;i++){
            if(maxFreqA<freqA[i]){
                maxFreqA=freqA[i];
                maxFreqAVal=i;
            }
            if(maxFreqB<freqB[i]){
                maxFreqB=freqB[i];
                maxFreqBVal=i;
            }
        }
        int minStepToMakeBEqualToA=n-maxFreqA,minStepToChangeToB=n-maxFreqB;
        if(minStepToMakeBEqualToA<=minStepToChangeToB){
            for(int i=0;i<n;i++){
                if(A[i]==maxFreqAVal+1){
                    continue;
                }else{
                    if(B[i]!=maxFreqAVal+1)
                        return -1;
                }
            }
            return minStepToMakeBEqualToA;
        }else{
            for(int i=0;i<n;i++){
                if(B[i]==maxFreqBVal+1)
                    continue;
                else
                    if(A[i]!=maxFreqBVal+1)
                        return -1;
            }
            return minStepToChangeToB;
        }
        return -1;
    }
};