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
ll arr[(int)1e3 +1][(int)1e3 +1];
ll city_count=0;
void startFromHere(ll i,ll j,ll n,ll m,ll x){
    if(arr[i][j]!=x) return;
    city_count++;
    arr[i][j]=-1;
    if(j+1 <m)
        startFromHere(i,j+1,n,m,x);
    if(j-1>=0)
        startFromHere(i,j-1,n,m,x);
    if(i-1>=0)
        startFromHere(i-1,j,n,m,x);
    if(i+1<n)
        startFromHere(i+1,j,n,m,x);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    FOR(i,n)
        FOR(j,n)
            cin>>arr[i][j];
    pair<ll,ll> each_and_city_count={INT_MIN,INT_MIN};
    FOR(i,n){
        FOR(j,m){
            if(arr[i][j]==-1) continue;
            ll x=arr[i][j];
            if(arr[i][j]!=-1){
                city_count=0;
                startFromHere(i,j,n,m,arr[i][j]);
            }
            if(city_count>each_and_city_count.second){
                each_and_city_count={x,city_count};
            }else if(city_count==each_and_city_count.second){
                if(x<each_and_city_count.first)
                    each_and_city_count={x,city_count};
            }
        }
    }
    cout<<each_and_city_count.first<<" "<<each_and_city_count.second<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}