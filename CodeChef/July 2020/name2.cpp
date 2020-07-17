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

// print vector
// print vector of pair int
// print hashmap

bool isASub(string a,string b){// tells if b is subseq of a
    if(b.length()<a.length())
        return false;
    int j=0,i=0;
    for(;i<a.length();){
        char c=a[i];
        for(;j<b.length();){
            if(a[i]==b[j]){
                i++,j++;
                break;
            }
            else
                j++;
        }
        if(j==b.length())
            break;
    }
    if(i==a.length()){
        return true;
    }else
        return false;
}

int solve(){
	string bride,groom;
    cin>>bride>>groom;
    if(isASub(bride,groom) or isASub(groom,bride)){
        cout<<"YES\n";
    }else
        cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}