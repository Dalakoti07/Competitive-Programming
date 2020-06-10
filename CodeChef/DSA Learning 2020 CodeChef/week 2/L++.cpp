#include <bits/stdc++.h>
using namespace std;
// >>>>><> is 0 as we are hunting for prefix of valid expression, fix this
int main() {
	int t;
	cin>>t;
	while(t--){
        string expression;
        cin>>expression;
        int dp[expression.length()];
        int maxy=INT_MIN;
        dp[0]=0;
        for(int i=1;i<expression.length();i++){
            if(expression[i]=='>'){
                if(expression[i-1]=='<'){
                    if(i-2>=0)
                        dp[i]=2+dp[i-2];
                    else
                        dp[i]=2;
                }else{
                    if(i-dp[i-1]-1 >=0){
                        if(expression[i-dp[i-1]-1]=='<'){
                            dp[i]=dp[i-1]+2;
                        }else{
                            dp[i]=0;
                        }
                    }
                    else
                        dp[i]=0;
                }
            }else{
                dp[i]=0;
            }
            maxy=max(maxy,dp[i]);
        }
        cout<<maxy<<endl;
	}
	return 0;
}