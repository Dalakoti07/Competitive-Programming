#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below
int arr[(3*(int)1e5) + 1];
void solve(){
	int n,x;
    cin>>n;
    vi zeroSegs;
    for(int i=0;i<n;i++){
        // cout<<"i: "<<i<<" and curLen: "<<currLen<<endl;
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i])
            continue;
        int ptr=i;
        while((ptr+1)<n and arr[ptr+1]==0){
            ptr++;
        }
        zeroSegs.pb(ptr-i+1);
        i=ptr;
    }
    // sort the segs
    sort(zeroSegs.begin(),zeroSegs.end());
    if(zeroSegs.size()==0){
        cout<<"No\n";
        return;
    }
    if(zeroSegs.size()==1){
        if(zeroSegs[0]%2)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        return;
    }
    if((zeroSegs[0]%2) and (zeroSegs[1]<=((zeroSegs[0]-1)/2))){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
}

int main(){
    // init();
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}