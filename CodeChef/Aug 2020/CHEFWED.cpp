#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
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
	int n,k;
    cin>>n>>k;
    vi arr(n+1);
    vi dp(n+1);
    // dp[i] tells min cost of seating people from 0 to i
    FOR(i,n)
        cin>>arr[i+1];
    dp[0]=0;
    // dp[1]=k;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+k;
        map<int,int> peopleCount;
        int clashes=0;
        for(int j=i;j>=1;j--){
            peopleCount[arr[j]]++;
            if (peopleCount[arr[j]] == 2)
                clashes += 2;
            else if (peopleCount[arr[j]] > 2)
                clashes += 1;
            dp[i]=min(dp[i], k+ clashes+dp[j-1]);
        }
    }
    // for(int d: dp)
    //     cout<<d<<" ";
    // cout<<endl;
    cout<<dp[n]<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}