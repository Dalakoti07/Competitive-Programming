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
const int maxn=10001;
int arr[maxn];
ll pre[maxn];
ll ans=LONG_LONG_MIN;

ll rangeSum(int l,int r){
    return pre[r]- (l? pre[l-1]:0);
}
void solve(){
	int n;
    cin>>n;
    FOR(i,n)
        cin>>arr[i];
    pre[0]=arr[0];
    for(int i=1;i<n;i++)
        pre[i]=pre[i-1]+arr[i];
    for(int i=0;i<n-1;i++){
        int l=i;
        // arr[0 to l] and arr[l+1 to n-1]
        ans=max(ans,abs(rangeSum(0,l)-rangeSum(l+1,n-1)));
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}