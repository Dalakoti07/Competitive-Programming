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
set<vi> SOUA;
int const MAXN=111;
int const shift=50;
int arr[MAXN];
int memo[MAXN][MAXN][MAXN];

// dp solution
/*
    the problem was solved by seeing the problem from new perceptive, unique arrays formed would be 
    equal to unique operations set we can perform on the array, as each new opeartion would give new unique array

    counting problems are usually dp problems
*/
int dp(int idx,int delta,int nextDelta){
    if(idx==101) return 1;

    // if idx or idx+1 <0 then we cannot make further operations
    if(delta+arr[idx]<0 or nextDelta+arr[idx+1]<0) return 0;

    int &res=memo[idx][delta+shift][nextDelta+shift];
    if(res!=-1)
        return res;
    res=0;
    for(int i=0;i<=min(delta+arr[idx],nextDelta+arr[idx+1]);i++){
        res+=dp(idx+1,nextDelta-i,i);
        res%=MOD;
    }
    return res;
}

// simple brute force solution
void recursion(vi vec){
    SOUA.insert(vec);
    for(int i=0;i<vec.size()-1;i++){
        vi eachy=vec;
        if(vec[i]>0 and vec[i+1]>0){
            eachy[i]--;
            eachy[i+1]--;
            if(i+2<eachy.size()){
                eachy[i+2]++;
            }else{
                eachy.push_back(1);
            }
            if(SOUA.find(eachy)==SOUA.end()){
                // we got a new unique array
                recursion(eachy);
            }
        }
    }
}

void solve(){
	SOUA.clear();
    int n;
    cin>>n;
    memset(arr,0,sizeof(arr));
    memset(memo,-1,sizeof(memo));
    FOR(i,n)
        cin>>arr[i];
    int ans=dp(0,0,0);
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}