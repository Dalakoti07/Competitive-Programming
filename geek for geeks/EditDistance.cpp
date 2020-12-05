#include<bits/stdc++.h>
using namespace std;

// dbb fdfaccddfac seg fault
int go(string s, string t){
    int n=s.length(),m=t.length();
    int dp[n+1][m+1];
    // dp[i][j] tells edit cost if we consider last i and j chars of string s and t
    memset(dp,0,sizeof(dp));
    // fill first row
    for(int i=0;i<=n;i++)
        dp[0][i]=i;
    // fill first col
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    //fillinf remaining array
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    return dp[n][m];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        cout<<go(s,t)<<endl;
    }
    return 0;
}