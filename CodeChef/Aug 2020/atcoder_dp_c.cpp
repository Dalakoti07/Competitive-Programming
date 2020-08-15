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
int arr[int(1e5)+1][3];

void solve(){
	int n;
    cin>>n;
    FOR(i,n)
        FOR(j,3)
        cin>>arr[i][j];
    // find the answer, from bottom up

    // we have to do exaushtive search and take max from all possiblities and this
    // would be too intensive using recursion but using dp it would be easy
    for(int i=n-2;i>=0;i--){
        arr[i][0]+=max(arr[i+1][1],arr[i+1][2]);
        arr[i][1]+=max(arr[i+1][0],arr[i+1][2]);
        arr[i][2]+=max(arr[i+1][1],arr[i+1][0]);
    }

    // answer would be max at row 0
    cout<<max(arr[0][0],max(arr[0][1],arr[0][2]))<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}