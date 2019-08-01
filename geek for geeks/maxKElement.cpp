#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code was showing TLE when we did not used cin.tie
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int arr[1000000];
	int t,n,k;
	cin>>t;
	while(t--)
	{
	       cin>>n;
	       for(int i=0;i<n;i++)
	       cin>>arr[i];
	       cin>>k;
	       sort(arr,arr+n);
	       cout<<arr[k-1]<<endl;
	}
	return 0;
}