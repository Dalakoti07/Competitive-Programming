// buffer underflow
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0)
            return 0;
        vector<int> dp= vector<int>(s.length(),0);
        // fill the dp array, dp[i] stores the length of longest valid parantheses ending at index i, we have initialized it to all zeroes
        for(int i=1;i<dp.size();i++){ // ignoring first character iteration
            if(s[i]==')'){
                if(s[i-1]=='('){ // situation same as .....()
                    if(i<2) // to avoid dp[1-2] access
                        dp[i] = 2;
                    else 
                        dp[i] = dp[i-2]+2; // increment the count by 2, considering the length of valid paranths before last ()
                }else{// means we have ')' something like this ..........))
                    if((i-dp[i-1]-1)>=0 and (s[i-dp[i-1]-1]=='(')){
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;// considering the example () ((()), and everything will make sense
                    }
                }
            }
        }
        auto it = max_element(std::begin(dp), std::end(dp)); // c++11
        return *it;
    }
};