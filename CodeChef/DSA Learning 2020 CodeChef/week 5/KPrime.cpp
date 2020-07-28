#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

using namespace std;

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

vector<int> allPrimeFactor(int(1e5 + 5),0);

void preCompute(){
    int Ibound=int(1e5 + 5); 
    for(int i=2;i<=Ibound;i++){
        if(allPrimeFactor[i]==0){// it means it prime and thus put prime factor in descendants as i 
            int innerBound=allPrimeFactor.size();
            for(int j=i;j<innerBound;j=j+i){
                allPrimeFactor[j]++;
            }
        }
        allPrimeFactor[i]++;
    }
}

int solve(){
    // we we will make vector<vec> for at which vec[i] denote all prime factors of i
    int a,b,k;
    cin>>a>>b>>k;
    int count =0;
    for(int i=a;i<=b;i++){
        if(allPrimeFactor[i]==k)
            count++;
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    preCompute();
    while(t--){
        solve();
    }
}