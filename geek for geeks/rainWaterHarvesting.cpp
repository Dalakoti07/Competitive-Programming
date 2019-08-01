#include<bits/stdc++.h>
using namespace std;
int arr[1000001];

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
		int left[n],right[n];
		left[0]=arr[0];
		for(int i=1;i<n;i++)
			left[i]=max(arr[i],left[i-1]);
		right[n-1]=arr[n-1];
		for(int i=n-2;i>=0;i--)
			right[i]=max(arr[i],right[i+1]);

		int answer=0;
		for(int i=0;i<n;i++)
		{
			answer+=min(left[i],right[i])-arr[i];
		}
		cout<<answer<<endl;
	}
	return 0;
}