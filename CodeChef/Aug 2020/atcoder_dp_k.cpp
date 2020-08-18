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
// its a game theory question where make states based upon who will win if we have game state as

void solve(){
    int n,k;
    cin>>n>>k;
    vi arr(n);
    vector<bool> dp(k+1);
    // dp[i] means who will win if k stones are remaining , true if first player wins
    // we have formulazid the problem in a better way
    // we dont care how we reached a particular state and then we have to calculate which player can win with this state
    // who win if we have 0 stones, who win if we have 1 stones, if we have 2 stones,....   ... k stones
    FOR(i,n)
        cin>>arr[i];
    for(int i=0;i<=k;i++){
        for(int x:arr){
            // if first player has not won with i-x stones then it will win by i stones, because players would win 
            // alternatively, because they are playing alternatively
            if(i>=x and !dp[i-x])
                dp[i]=true;
        }
    }
    dp[k]? cout<<"First\n":cout<<"Second\n";
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}