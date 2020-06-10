#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        unsigned long long arr[n],dp[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        // find the practical capacity
        dp[0]=arr[0];
        unsigned long long ans=arr[0];
        for(int i=1;i<n;ans+=dp[i],i++)
            dp[i]=min(dp[i-1],arr[i]);
        cout<<ans<<endl;
	}
	return 0;
}