#include<bits/stdc++.h>
	
using namespace std;
	
typedef complex<double> base;
typedef long double ld;
typedef long long ll;
	
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
	
const int maxn=(int)(505);
const ll mod=(ll)(1e9+7);
ll a[maxn],pre[maxn];
ll dp[maxn][maxn];
int n;
	
ll getSum(int l,int r)
{
	if(l<=r)
	{
		return pre[r]-(l==0?0:pre[l-1]);
	}
	
	return pre[n-1]-pre[l-1]+pre[r];
}
	
int main(){
    // same as atcoder problem
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;cin>>t;
	
	while(t>0)
	{
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	
		pre[0]=a[0];
	
		for(int i=1;i<n;i++)
		{
			pre[i]=pre[i-1]+a[i];
		}
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[i][j]=LONG_LONG_MAX;
			}
		}
	
		for(int i=0;i<n;i++)
		{
			dp[i][i]=0;
		}
	
		for(int size=2;size<=n;size++)
		{
			for(int i=0;i<n;i++)
			{
				int l=i,r=(i+size-1)%n;
	
				for(int j=l;j!=r;j=(j+1)%n)
				{
					dp[l][r]=min(dp[l][r],dp[l][j]+dp[(j+1)%n][r]+getSum(l,r));
				}
			}
		}
	
		ll res=LONG_LONG_MAX;
	
		for(int i=0;i<n;i++)
		{
			int l=i,r=(i-1+n)%n;
	
			res=min(res,dp[l][r]);
	
			//   cout<<l<<" "<<r<<" "<<dp[l][r]<<endl;
		}
	
		cout<<res<<endl;
	
		t--;
	}
	
	
	
	return 0;
}