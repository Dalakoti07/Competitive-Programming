#include <bits/stdc++.h>
using namespace std;

int main()
{
  	int n;
  	cin>>n;
  	int arr[n];
  	int dp[n][101]={0};
    int mody=1000000000+7;

    // the brute force approach would be that see all the subsequences and decide and count them, bu counting all the increasing subsequence is exponential task thus we wont do that
  	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        dp[i][arr[i]]++;      
    }
  
	for(int i=1;i<n;i++)
    {
      for(int j=0;j<=i-1;j++)
      {
        if(arr[j]<arr[i])	// increasing ,assuming strictly increasing
        {
			for(int k=1;k<=100;k++)
            {
				int new_gcd=__gcd(arr[i],k);
                dp[i][new_gcd]=(dp[i][new_gcd]+dp[j][k])%mody;
                // hellest thing mod to be taken here also
            }
        }
      }	
    }
    long long ans=0;   

    for(long long i=0;i<n;i++)
    ans=(ans+dp[i][1])%mody; //add all whose gcd is 1
    cout<<ans<<endl;
  return 0;
}
