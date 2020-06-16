class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n =digits.size();
        if(n==1){
            if(digits[0]==9) return vector<int>{1,0};
            else{
                vector<int> tempo=digits;
                tempo[0]=tempo[0]+1;
                return tempo;
            }
        }
        vector<int> ans(n);
        int carry=0;
        ans[n-1]=(digits[n-1]+1)%10;
        carry= (digits[n-1]+1)/10;
        for(int j=n-2;j>=0;j--){
            ans[j]=(digits[j]+carry)%10;
            carry=(digits[j]+carry)/10;
        }
        if(carry!=0){
            ans.insert(ans.begin(),carry);
        }
        return ans;
    }
};