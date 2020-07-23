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
  FASTIO;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

int solve(){
	int n;
    cin>>n;
    vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    vi dp(n);
    for(int i=0;i<n;i++){
        dp[i]=1;
        // left trav
        for(int j=i;j>=1;j--){
            if(arr[j]-arr[j-1] <=2)
                dp[i]++;
            else
                break;
        }
        // right travser
        for(int j=i;j<n-1;j++){
            if(arr[j+1]-arr[j]<=2)
                dp[i]++;
            else
                break;
        }
    }
    int Max=INT_MIN,Min=INT_MAX;
    FOR(i,n){
        Max=max(Max,dp[i]);
        Min=min(Min,dp[i]);
    }
    cout<<Min<<" "<<Max<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}