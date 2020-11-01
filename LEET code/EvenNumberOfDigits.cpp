class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        string s;
        for(int n:nums){
            s=to_string(n);
            if(s.size()%2==0)
                count++;
        }
        return count;
    }
};