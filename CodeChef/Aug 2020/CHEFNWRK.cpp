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
    int count=0;
    vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    if(arr[0]>k){
        cout<<-1<<"\n";return;}
    count++;
    int currWt=arr[0];
    for(int i=1;i<n;i++){
        if(currWt+arr[i]>k){
            currWt=arr[i];
            count++;
        }else{
            currWt+=arr[i];
        }
        if(currWt>k){
            cout<<-1<<endl;
            return;
        }
    }
    if(currWt>k)
        count++;
    cout<<count<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}