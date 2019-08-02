#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		// when given 1 based indexing, implement it that way
		int n,m,a,b,c,d,sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>arr[i][j];
		cin>>a>>b>>c>>d;
		for(int i=a;i<=c;i++)
			for(int j=b;j<=d;j++)
				sum+=arr[i][j];
		cout<<sum<<endl;
	}
}