#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int t,n,k;
	int arr[100001];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>k;
		//calculate ,brute forces would take nk-kk time( and brute force would do it) because if k is large then n-k is small ,and if k is small then n dominates (thus brute force would do the trick), maybe segment tree can help
		//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0
		for(int i=0,j;i<=n-k;i++)
		{
			for(j=i;j<i+k;j++)
			{
				if(arr[j]<0)
					{cout<<arr[j]<<" ";break;}
			}
			if(j==i+k)
				cout<<"0 ";
		}
	cout<<endl;
	}
}