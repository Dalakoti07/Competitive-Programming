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
	int n;
    cin>>n;
    string str;
    char s;
    cin>>str>>s;
    vector<int> places={-1};
    for(int i=0;i<n;i++)
        if(str[i]==s)
            places.push_back(i);
    places.pb(n);
    // in this question we have to find the substrings which contain at least one appearance of character x,
    // so in this case we can do vice-versa instead of finding atleast one, we can find all- {which contains none}

    // we have placed the dummy data at the begin and end of the array
    ll ans=((ll)n*(n+1))/2;
    for(int i=1;i<places.size();i++){
        int len=places[i]-places[i-1]-1;
        ans-=((ll)len*(len+1))/2;
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