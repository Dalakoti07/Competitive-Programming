#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long arr[n], dp[n];
	for(int i=0;i<n;i++)
		{cin>>arr[i];dp[i]=1;}
	//filling the dp array
	for(int i=1;i<n;i++)
		if(arr[i]>=arr[i-1])
			dp[i]+=dp[i-1];
	//find the maximum length
	long long maxLength=INT_MIN;
	for(int i=0;i<n;i++)
		if(dp[i]>maxLength)
			maxLength=dp[i];
	cout<<maxLength;
}