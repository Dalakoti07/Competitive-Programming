class Solution {
public:
    void go(int n,int leftParan,int rightParan,string str,vector<string>& ans){
        if(leftParan+rightParan ==2*n ){
            ans.push_back(str);
            return;
        }
        if(leftParan<n){
            go(n,leftParan+1,rightParan,str+"(",ans);
        }
        if(rightParan<leftParan){
            go(n,leftParan,rightParan+1,str+")",ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        go(n,0,0,"",ans);
        return ans;
    }
};