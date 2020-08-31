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
map<int,int> findRanking(vector<int>& arr){
    sort(arr.begin(),arr.end());
    // vector<int> ratingVec(arr.size());
    map<int,int> ratingMap;
    ratingMap[arr[0]]=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1]){
            ratingMap[arr[i]]=i+1;
        }
    }
    return ratingMap;
}

void solve(){
	int n,m,x;
    cin>>n>>m;
    vector<vector<pair<int,int>>> matrix(n,vector<pair<int,int>>(m));
    vi initRating(n);
    FOR(i,n)
        cin>>initRating[i];
    // create matrix
    vi maxRankInWhichMatch(n);
    vi temp;
    for(int i=0;i<n;i++){
        for(int j=0;i<m;j++){
            cin>>x;
            initRating[i]=initRating[i]+x;
            matrix[i][j]={initRating[i],j+1};//rating and match number
        }
    }
    // vecs
    vi maxratingAchievedInWhichMatch(n);
    for(int i=0;i<n;i++){
        for(int )
    }
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}