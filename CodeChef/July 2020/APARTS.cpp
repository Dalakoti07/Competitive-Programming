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
	int n,m;
    cin>>n>>m;
    int arr[n][m];
    int dp[n][m];

    FOR(i,n)
        FOR(j,m){
            cin>>arr[i][j];
        }

    /*
    cout<<"input arr\n";
    for(int i=0;i<n;i++,cout<<endl){
        for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
    }
    cout<<"\ndp array\n";
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                dp[i][j]=1;
            }
            else{
                int Max=0;
                if(j==0)
                    Max=max(arr[i-1][j],arr[i-1][j+1]);
                else if(j==m-1)
                    Max=max(arr[i-1][j],arr[i-1][j-1]);
                else
                    Max=max(arr[i-1][j],max(arr[i-1][j-1],arr[i-1][j+1]));
                if(Max>arr[i][j])
                    dp[i][j]=0;
                else
                    dp[i][j]=1;
                arr[i][j]=max(Max,arr[i][j]);
            }
            // cout<<dp[i][j]<<" ";
        }
    }
    // cout<<" ans arr \n";
    for(int i=0;i<n;i++,cout<<endl){
        for(int j=0;j<m;j++){
            cout<<dp[i][j];
        }
    }
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}