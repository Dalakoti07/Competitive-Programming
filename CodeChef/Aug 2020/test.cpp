#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=1e5;
//greatest prime factor
int gp[mxN+1];
int n, m, x[mxN], y[mxN];
int c[2][mxN+1];
ll ans;

void dfs(vector<array<int, 2>> &pf, vector<int> &f, int i=0, ll x=1) {
	if(i>=pf.size()||x*pf[i][0]>mxN) {
		f.push_back(x);
		return;
	}
	//multiply x by p^j
	for(int j=0; j<=2*pf[i][1]&&x<=mxN; x*=pf[i][0], ++j)
		dfs(pf, f, i+1, x);
}

void solve2(int n, int x[mxN], int m, int y[mxN]) {
	//store y in frequency array
	memset(c, 0, sizeof(c));
	for(int i=0; i<m; ++i)
		++c[y[i]<0][abs(y[i])];
	for(int i=0; i<n; ++i) {
		//prime factorize x[i]
		//stored as pairs (prime, exponent)
		vector<array<int, 2>> pf;
		int x2=abs(x[i]);
		while(x2>1) {
			int p=gp[x2], c=0;
			while(x2%p==0) {
				x2/=p;
				++c;
			}
			pf.push_back({p, c});
		}
		//make pf in increasing order
		reverse(pf.begin(), pf.end());
		//generate all factors of x[i]^2 <= mxN
		vector<int> f;
		dfs(pf, f);
		//test each factor
		for(int j : f)
			if((ll)x[i]*x[i]/j<=mxN)
				ans+=c[0][j]*c[1][(ll)x[i]*x[i]/j];
	}
}

void solve() {
	//input
	cin >> n >> m;
	bool zero=0;
	for(int i=0; i<n; ++i) {
		cin >> x[i];
		if(!x[i]) {
			zero=1;
			--i;
			--n;
		}
	}
	for(int i=0; i<m; ++i) {
		cin >> y[i];
		if(!y[i]) {
			zero=1;
			--i;
			--m;
		}
	}
 
	ans=(ll)zero*n*m;
	//count triples (x, y, y)
	solve2(n, x, m, y);
	//count triples (y, x, x)
	solve2(m, y, n, x);
 
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	//sieve
	for(int i=2; i<=mxN; ++i)
		if(!gp[i])
			for(int j=0; (j+=i)<=mxN; )
				gp[j]=i;
	
	int t;
	cin >> t;
	while(t--)
		solve();
}