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

// print vector
// print vector of pair int
// print hashmap

int solve(){
	int n;
    cin>>n;
    vector<int> arr(n);
    FOR(i,n)
        cin>>arr[i];
    int runningGCD;
    if(n==1)
        cout<<arr[0]<<endl;
    else{
        runningGCD=__gcd(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            runningGCD=__gcd(runningGCD,arr[i]);
        }
        cout<<runningGCD<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}