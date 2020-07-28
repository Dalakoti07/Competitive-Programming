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

vector<int> allPrimeFactor(int(1e5 + 1),0);
int ans[int(1e5)+1][6];
void preCompute(){
    int Ibound=int(1e5 + 1); 
    for(int i=2;i<=Ibound;i++){
        if(allPrimeFactor[i]==0){
            // it means it prime and thus put prime factor in descendants as i 
            int innerBound=allPrimeFactor.size();
            for(int j=i;j<innerBound;j=j+i){
                allPrimeFactor[j]++;
            }
        }
    }

    // fill the ans array
    for(int i=2;i<=(int)1e5;i++){
        for(int j=1;j<=5;j++){
            // ans [i][j] denotes taking i numbers from 0 to i from which have exactly j primes
            // now if we want to calculate number from 0 to i+1 which have exactly have j primes, it good to know how many 
            // numbers were present from 0 to i which had exactly k primes and then if this number has also exaclty j primes
            // then we increase the counter by 1, this is what below rec fun says
            ans[i][j]=ans[i-1][j] + (allPrimeFactor[i]==j? 1:0);
        }
    }
}

int solve(){
    // we we will make vector<vec> for at which vec[i] denote all prime factors of i
    int a,b,k;
    cin>>a>>b>>k;
    int count =0;
    if(k==0)
        cout<<0<<endl;
    else{
        // for(int i=a;i<=b;i++){
        //     if(allPrimeFactor[i]==k)
        //         count++;
        // }
        cout<<ans[b][k]-ans[a-1][k]<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    preCompute();
    while(t--){
        solve();
    }
}