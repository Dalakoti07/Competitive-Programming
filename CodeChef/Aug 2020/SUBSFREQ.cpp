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
int catalanNumber(int n){
    if(n<=1) return 0;
    return pow(2,n)-n-1;
}

void solve(){
	int n;
    cin>>n;
    vi arr(n);
    vi dp(n+1,0);
    FOR(i,n)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    
    // make a 2d array which is n*n size where thisArr[i][j] means ways to make a group of i of size j
    // for example we have arr as ..,2,2,2,.., then thisArr[2][1] means ways to make a group of 2 of size 1 is 3
    // group of size 2 is 3C2 and group of size 3 is 1 (i.e 3C3), and else others are zero

    // since nCr is involved thus precompute factorial till 11 and then each nCr is constant time

    // lets take an example we have, 1,1,2,2,2,3,3


    for(int i=n;i>=1;i--){
        dp[i]= (freqOfElem+ catalanNumber(freqOfElem) + ((ll)freqOfElem*(ll)freqOfElemGreater)%MOD)%MOD;
    }
    FORE(i,1,n){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}