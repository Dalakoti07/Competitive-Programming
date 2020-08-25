#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
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

void solve(){
	int n,k;
    string str;
    cin>>n>>k;
    cin>>str;
    int oneCount=0,zeroCount=0;
    for(int i=0;i<n;i++)
        if(str[i]=='0')
            zeroCount++;
        else
            oneCount++;
    // if these zeroes and one can be distributed in all segs
    int segsCanBeMade=n/k;
    if((zeroCount%segsCanBeMade) or (oneCount%segsCanBeMade)){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    // calculating ones in each seg
    oneCount=oneCount/segsCanBeMade;
    zeroCount=zeroCount/segsCanBeMade;
    string ans="";
    for(int i=1;i<=segsCanBeMade;i++){
        if(i%2){
            // if seg is odd 0,0,,,,,,1,1,....,1  to maintain lowest lexical order
            for(int i=1;i<=zeroCount;i++)
                ans+="0";
            for(int i=1;i<=oneCount;i++)
                ans+="1";
        }else{
            // is seg is even then we have 1,1,...1,0,0,....0 to maintain the palindromic nature
            for(int i=1;i<=oneCount;i++)
                ans+="1";
            for(int i=1;i<=zeroCount;i++)
                ans+="0";
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}