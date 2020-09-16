#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7
#define deb(x) cout<< #x << " = "<<x<<endl;

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

void solve(){
	int n;
    cin>>n;
    int matrix[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    int count=0;
    // calculate from last
    for(int i=n-1;i>0;i--){
        if(matrix[i][i]!=matrix[i][i-1]+1){// if diagonal is not equal to element on its left
            count++;
            // doing the transpose
            for(int a=0;a<i+1;a++)
                for(int b=a;b<i+1;b++)
                    swap(matrix[a][b],matrix[b][a]);

            // see the matrix
            // for(int i=0;i<n;i++,cout<<"\n")
            //     for(int j=0;j<n;j++)
            //         cout<<matrix[i][j]<<" ";
        }else
            continue;
    }
    cout<<count<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}