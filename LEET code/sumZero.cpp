class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n==0) return vector<int>();
        int count=0,nextInt=1;
        if(n%2){
            ans.push_back(0);
            count++;
        }
        while(count!=n){
            ans.push_back(nextInt);
            ans.push_back(-1*nextInt);
            nextInt++;
            count+=2;
        }
        return ans;
    }
};