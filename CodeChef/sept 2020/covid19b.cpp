#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define sz(s) (int)(s).size()
#define pb push_back
#define mp make_pairS
#define F first
#define endl "\n"
#define S second
const int inf = 1000000000;
const int MOD = 1000000007;
// TODO read this
void solve(){
    Int n;cin>>n;
	Int a[n];
	Int temp;
	FOR(i,0,n)cin>>a[i];
	Int minans=0,maxans=0;
	Int count[n]={0};
	FOR(i,0,n){
	    count[i]=1;
	    temp=*min_element(a+i, a+n);
	    FOR(j,0,i)
			if(a[j]>temp)
			    count[i]++;
		temp=*max_element(a, a+i+1);
		FOR(j,i+1,n)
	        if(temp>a[j])
			    count[i]++;

	}
	sort(count,count+n);
	minans=count[0];
	maxans=count[n-1];
	cout<<minans<<" "<<maxans<<endl;
}  

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	fastio;
	Int t=1;
	cin>>t;
	while(t--){
		solve();	
	}
}