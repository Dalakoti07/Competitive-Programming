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


void solve(){
	int n,k,x;
    cin>>n>>k;
    vi freq(8001,0),unique;
    FOR(i,n){
        cin>>x;
        freq[x]++;
        if(freq[x]==1)
            unique.pb(x);
    }
    // we will make a dp of size 10^5 * 10^5 (n*k) which is impossible, where dp[i][j] would tell using all the elements from
    // 0 to i how many subsequence of size exact j can be made from it
    // but this will not work as making such large 2d array is not possible thus we need to reduce the size of dp array
    /* we can see the following things in questions that there are 10^5 elems but their range is from 1 to 8000 thus we 
    have many repetitions thus we have 8000*k  which is 10^8 approx which is also seems infeasible,
    10^8 array size would be 10^8 * 8 bytes and 10^6 bytes is 1 MB
    so we have 800 MB space that is too much https://www.codechef.com/viewsolution/36075391 implementation
    we can further reduce it based upon the fact that but we can also notice that 
    we can further reduce it to 1007 as there are uniqye 1007 primes till 8k
    https://www.codechef.com/viewsolution/36075552
    */
    k=min(k,1008);
    ll dp[unique.size()+1][k+1];
    int uniqueN=unique.size()+1,m=k+1;
    // for 0th row
    for(int i=0;i<m;i++)
        dp[0][i]=0;
    // for 0th col
    for(int i=0;i<uniqueN;i++)
        dp[i][0]=1;
    for(int i=1;i<uniqueN;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=((dp[i-1][j-1]*freq[unique[i-1]])%MOD + (dp[i-1][j])%MOD)%MOD;
        }
    }
    // answer is last row

    ll count=0;
    for(int i=0;i<m;i++)
        count=(count+ dp[uniqueN-1][i])%MOD;
    // cout<<endl;
    cout<<count<<endl;
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