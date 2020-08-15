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
ll dp[2][(int)1e9 + 1];

void solve(){
	int n,maxWeight;
    cin>>n>>maxWeight;
    vi values(n+1),weights(n+1);
    for(int i=1;i<=n;i++)
        cin>>weights[i]>>values[i];

    bool isFirst=false;
    for(int i=1;i<=n;i++){
        if(isFirst){
            for(int j=1;j<=maxWeight;j++)
                if(j-values[i]>=0)
                    dp[0][j]=max(values[i]+dp[1][j-values[i]],dp[1][j]);
                else
                    dp[0][j]=dp[1][j];
        }else{
            for(int j=1;j<=maxWeight;j++)
                if(j-values[i]>=0)
                    dp[1][j]=max(values[i]+dp[0][j-values[i]],dp[0][j]);
                else
                    dp[1][j]=dp[0][j];
        }
        isFirst=!isFirst;
    }

    // cout<<" dp array is \n";
    // for(int i=0;i<=n;i++,cout<<endl)
    //     for(int j=0;j<=maxWeight;j++)
    //         cout<<dp[i][j]<<" ";

    if(n%2==0)
        cout<<dp[0][maxWeight]<<endl;
    else
        cout<<dp[1][maxWeight]<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}