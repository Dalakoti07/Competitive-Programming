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

vi primes;
vi bucketOne,bucketTwo;
ll p1=1,p2=1;
int counter1 = 4;
int counter2 = 4;

inline bool isPrime(int i){
    for(int j=2;j<=sqrt(i);j++){
        if(i%j==0)
            return false;
    }
    return true;
}

void preCompute(){
    primes.pb(2);
    primes.pb(3);
    for(int i=4;i<100;i++){
        if(isPrime(i))
            primes.pb(i);
    }
    int x= primes.size();
    bool one=true;
    for(int i=0;i<x;i++,one=!one)
        if(one)
            {bucketOne.pb(primes[i]);p1*=(ll)primes[i];}
        else 
            {bucketTwo.pb(primes[i]);p2*=(ll)primes[i];}
}

// the line of thinking is this, since length of every path should divide product of the elems in path, thus this 'product' 
// term give us the hint of factors, that size should be factor of product of all elem, and we have to find all the elems
// now what can be this elems, they should be multiples of size, what is size, size of path can be 1,2,3,  or ... even
//  n in worst case, so factors of these sizes would be primes number <=100 as nodes=n ,n<=100
//  now if product of all primes is kept at each node then we are done, as it divisible by each and every prime <=100
// but the problem is that sum of all primes<=100 would give no. >=2*(10^19) and thus we can do that
// so what we can does is following
/*
Let all the primes less than 100 be denoted by the set P. Choose A and B such that A U B = Pa and A U B =ϕ. Let
pa be the product of all primes in A and pb	be product of all primes in BB.
Root the tree at some node, and do a dfs. Set the value of all nodes at even depths to be pa 
and set the value of all nodes at odd depths to be pb​	
*/ 

// no cycle in tree thus no visited concept here
void dfs(int node,int parent,vector<ll>& output,int depth,vector<int> adj[]){
    if(depth%2==0)
        output[node]=p1/bucketOne[counter1++];
    else
        output[node]=p2/bucketTwo[counter2++];
    if(counter1==12) counter1 = 4;
    if(counter2==12) counter2 = 4;
    for(int i=0;i<adj[node].size();i++)
        if(adj[node][i]!=parent)
            dfs(adj[node][i],node,output,depth+1,adj);
}

void solve(){
	int n,a,b;
    cin>>n;
    vi adj[n+1];
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> output(n+1);
    dfs(1,1,output,0,adj);
    for(int i=1;i<=n;i++){
        assert(output[i]<2000000000000000000);
        cout<<output[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    preCompute();
    // cout<<" one "<<bucketOne.size()<<" two "<<bucketTwo.size()<<endl;
    // cout<<" p1 is "<<p1<<" and p2 is "<<p2<<endl;
    while(t--){
        solve();
    }
    return 0 ;
}