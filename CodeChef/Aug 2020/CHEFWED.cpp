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
    // the conjecture is either all in one table or all in seperate table

	// freq range is very less so I think we can exploit it
    ll freq[101]={0};
    // memset(freq,0,sizeof(freq));
    ll n,k,x;
    cin>>n>>k;
    vi arr(n);
    FOR(i,n){
        cin>>arr[i];
        freq[arr[i]]++;
    }

    set<ll> currTable;
    currTable.insert(arr[0]);
    ll tableCount=0;
    for(ll i=1;i<n;i++){
        if(currTable.find(arr[i])!=currTable.end()){
            tableCount++;
            currTable.clear();
            currTable.insert(arr[i]);
        }else{
            currTable.insert(arr[i]);
        }
    }
    tableCount++;
    ll oneWay=tableCount*k;
    ll count=0;
    for(ll i=0;i<=100;i++)
        if(freq[i]!=1)
            count+=freq[i];

    cout<<min(oneWay,k+count)<<endl;

}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}