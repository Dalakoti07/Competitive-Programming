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
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below
const int mxN=1e5;
int arrX[mxN],arrY[mxN],greatestPrimeFactor[mxN];
int n,m,freqArr[2][mxN+1];
// freq array is 2d array freq[0][i] means neg count of i
// freq[1][i] means positive count of i
ll ans;

void generateAllFactors(vector<pair<int,int>> &primeFactors,vector<int>& f,int i=0,ll x=1){
    if(i>=primeFactors.size()||x*primeFactors[i].first>mxN){
        f.push_back(x);
        return;
    }
    // multiply x by p^j
    // it would have been j<=primefactors[i].second
    // but we are at the end want factors of square thus doing 2*()
    for(int j=0; j<=2*primeFactors[i].second&&x<=mxN; x*=primeFactors[i].first, ++j)
		generateAllFactors(primeFactors, f, i+1, x);
}

void solve2(int n,int x[mxN],int m,int y[mxN]){
    // store y in freq array
    memset(freqArr,0,sizeof(freqArr));
    for(int i=0;i<m;i++)
        freqArr[y[i]<0][abs(y[i])]++;

    for(int i=0;i<n;i++){
        // prime factorization x[i]
        // stored as pair(prime,exponent)
        vector<pair<int,int>> primeFactors;
        int x2=abs(x[i]);
        while(x2>1){
            int p=greatestPrimeFactor[x2],c=0;
            while(x2%p==0){
                x2/=p;
                ++c;
            }
            primeFactors.pb({p,c});
        }
        // make prime factors array in increasing order
        reverse(primeFactors.begin(),primeFactors.end());
        // generate all the factors of x[i]^2 <=mxN
        vector<int> f;
        generateAllFactors(primeFactors,f);

        // test each factor
        for(int j:f){
            if((ll)x[i]*x[j]/j<=mxN)
                ans+=freqArr[0][j]*freqArr[1][(ll)x[i]*x[i]/j];
            // why we are not counting other way round 
        }
    }
}

void solve(){
	int zero=0;
    cin>>n>>m;

    for(int i=0; i<n; ++i) {
        cin>>arrX[i];
        if(!arrX[i]){
            zero=1;
            n--;
            i--;
        }
    }
   for(int i=0; i<m; ++i){
        cin>>arrY[i];
        if(!arrY[i]){
            m--;
            i--;
            zero=1;
        }
    }
    ans=(ll)zero*n*m;
    
    solve2(n,arrX,m,arrY); // find of type x,y,y
    solve2(m,arrY,n,arrX);  // find of tyoe y,x,x
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;

    // sieve that store the maxPrimeFactor of i
    // like for 3,6,9,12,15, we say its 3 then
    // after this 15th greatest prime factor become 5
    for(int i=2;i<=mxN;i++){
        if(!greatestPrimeFactor[i])
            for(int j=0;(j+=i)<=mxN;)
                greatestPrimeFactor[j]=i;
    }

    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}