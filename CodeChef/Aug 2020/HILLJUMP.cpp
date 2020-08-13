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
int go(int start,int jumps,vector<ll>& arr,int n){
    int count=0,jumpsMadeSoFar=0;
    int last=arr[start],lastIdx=start;
    int i;
    for(i=start+1;i<n and jumpsMadeSoFar<jumps;i++){
        // cout<<" last was "<<last<<" and arr[i] is "<<arr[i]<<endl;
        if(arr[i]>last){
            jumpsMadeSoFar++;
            lastIdx=i+1;
            count=0;
            last=arr[i];
            // cout<<" making a jump to index : "<<i<<" and totals jumps are : "<<jumpsMadeSoFar<<endl;
        }
        if(count>100)
            return start+1;
        if(last==arr[i])
            count++;
    }
    // cout<<" idx is "<<i<<endl;
    return i;
}

void solve(){
	int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    FOR(i,n)
        cin>>arr[i];
    while(q--){
        int t,a,b,x;
        cin>>t;
        if(t==1){
            cin>>a>>b;
            cout<<go(a-1,b,arr,n)<<endl;
        }else{
            cin>>a>>b>>x;
            for(int i=a-1;i<=b-1;i++)
                arr[i]+=x;
        }
    }
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}