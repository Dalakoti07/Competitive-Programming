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
const int maxn=305;
double p[maxn][maxn][maxn],ev[maxn][maxn][maxn];
// p[a][b][c] denotes probability of going into state where we have a dishes with 1 sushi, b dishes with 2 shushi, c dishes with 3 shushi
// ev[a][b][c] - the expected number of operations so far to get to state (a,b,c)

void solve(){
	int n,x;
	cin>>n;
	vi sushi(4);
	FOR(i,n){
		cin>>x;
		sushi[x]++;
	}
	p[sushi[1]][sushi[2]][sushi[3]]=(double)1; // as we start from these much shushi
	// now we have to calculate p[0][0][0] from this above state, which states that what is prob to go there
	// we started with c as outer loop because c val is decreasing for sure, but 
	// a's value is increasing or either decreasing
	for(int c = n; c >= 0; --c) {
        for(int b = n; b >= 0; --b) {
            for(int a = n; a >= 0; --a) {
				// cout<<"loop ";
                if(a == 0 && b == 0 && c == 0) {
                    continue;
					// because we are not going anywhere from this state 
                }
                if(a + b + c > n) {
					// ignore non valid states
                    continue;
                }
                // dp[a][b][c]
                
                double p_waste = (double) (n - (a + b + c)) / n;
                // p_waste + p_waste^2 + ... = S
                // 1 + S = S / p_waste
                double ev_waste = p_waste / (1 - p_waste) + 1;
                // debug() << imie(a) imie(b) imie(c) imie(ev_waste);
                ev[a][b][c] += ev_waste * p[a][b][c];
                
                // remove 1 -> dp[a-1][b][c]
				// removing a sushi from plate which has 1 sushi then we decrease the count of plates containing 1 sushi
                // we will eventually choose one of a+b+c
                if(a != 0) {
                    double p_go = (double) a / (a + b + c);
                    p[a-1][b][c] += p[a][b][c] * p_go;
                    ev[a-1][b][c] += ev[a][b][c] * p_go;
                }
                
                // remove 2 -> dp[a+1][b-1][c]
				// removing a sushi from plate which has 2 sushi then we decrease the count of plates containing 2 sushi
				// but increase the count of plates having 1 sushi
                if(b != 0) {
                    double p_go = (double) b / (a + b + c);
                    p[a+1][b-1][c] += p[a][b][c] * p_go;
                    ev[a+1][b-1][c] += ev[a][b][c] * p_go;
                }
                
                // remove 3
                if(c != 0) {
                    double p_go = (double) c / (a + b + c);
                    p[a][b+1][c-1] += p[a][b][c] * p_go;
                    ev[a][b+1][c-1] += ev[a][b][c] * p_go;
                }
            }
        }
    }
	cout<<fixed << setprecision(11)<<ev[0][0][0]<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}