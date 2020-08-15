#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

void solve(){
	string str1,str2;
    cin>>str1>>str2;
    int n=str1.size()+1,m=str2.size()+1;
    int dp[n][m];
    for(int i=0;i<n;i++)
        dp[i][0]=0;
    for(int i=0;i<m;i++)
        dp[0][i]=0;
    
    string ans="";
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(str1[n-i-1]==str2[m-j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    if(dp[n-1][m-1]>0){
        // travel bottom up
        int i=n-1,j=m-1;
        while(i>0 and j>0 ){
            if(str1[n-i-1]==str2[m-j-1]){
                ans+=str2[m-j-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
            // cout<<endl;
        }
    }

    cout<<ans<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}