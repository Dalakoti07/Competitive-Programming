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

int solve(){
    int n,q;
    cin>>n>>q;
    string virus;
    cin>>virus;
    map<char,int> virusMap;
    FOR(i,n)
        virusMap[virus[i]]++;
    
    int a,peopleRem=0;
    
    FOR(i,q){
        cin>>a;
        peopleRem=0;
        map<char,int> mapCopy=virusMap;
        // constant time for each query
        for(auto m: mapCopy){
            if(m.second>=a){
                mapCopy[m.first]-=a;
            }else{
                mapCopy[m.first]=0;
            }
        }
        for(auto m: mapCopy){
            peopleRem+=m.second;
        }
        cout<<peopleRem<<endl;
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