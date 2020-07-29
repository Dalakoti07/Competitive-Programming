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

bool comparator(pair<int,int>& p1,pair<int,int>& p2){
    return p1.second<p2.second;
}

void Precompute(vector<int>& sets,vector<pair<int,int>>& arr,int k){
    sets[arr[0].first]=1;
    int number=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i].second-arr[i-1].second<=k)
            sets[arr[i].first]=number;
        else{
            sets[arr[i].first]=++number;
        }
    }
}

void solve(){
	int n,k,p,x;
    cin>>n>>k>>p;
    vi frogs(n+1);
    vector<pair<int,int>> arr;
    FOR(i,n){
        cin>>x;
        frogs[i+1]=x;
        arr.pb({i+1,x});
    }
    sort(arr.begin(),arr.end(),comparator);
    vi dp(n+1);

    // try one more approach that is make sets of frogs which can communicate and then take a and b check if a anf b 
    // appear in same set, u can achieve this by the help of arr with integer as set name like set one as 1, set two as
    // 2, and thus we can make n set s
    /*
    vi sets(n+1);
    Precompute(sets,arr,k);
    int a,b;
    while(p--){
        cin>>a>>b;
        if(sets[a]==sets[b])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    */

    // dp solution
    /*  In this we have n states and each transition shows maximum x coordinate to which frog i can communicate
        to calculate each state what we have to do it do constant comparing thus overall complexity of DP solution
        is n*1 , and answer is  (given that frog i is before frog j in x coordinate , that is xi<xj)
        dp[i] tells given ith frog upto which distance or x coordinate on right it can coordinate
        frog i can communicate to frog j if and only if frog i has same communication length of frog j
    */
    dp[arr[n-1].first]=arr[n-1].second;
    for(int i=n-2;i>=0;i--){
        if(arr[i].second+k>=arr[i+1].second)
            dp[arr[i].first]=dp[arr[i+1].first];
        else
            dp[arr[i].first]=arr[i].second;
    }
    int a,b;
    while(p--){
        cin>>a>>b;
        if(frogs[a]>frogs[b])
            swap(a,b);
        if(dp[a]>=dp[b])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}

int main(){
    int t;
    // cin>>t;
    t=1;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}