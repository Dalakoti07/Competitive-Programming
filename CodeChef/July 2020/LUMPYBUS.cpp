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
	ll n,p,q,one,two;
    cin>>n>>p>>q;
    vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll count=0,wanted,used;
    // the greed is that fully satisfy a person or else dont satisfy it 
    FOR(i,n){
        two=arr[i]/2;
        if(q>=two){
            one =arr[i]-(2*two);
            if(p>=one){
                q-=two;
                p-=one;
                count++;
            }
        }else{
            two=q;
            one=arr[i]-(2*two);
            if(p>=one){
                q-=two;
                p-=one;
                count++;
            }
        }
        if(p==0 and q==0)
            break;
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}