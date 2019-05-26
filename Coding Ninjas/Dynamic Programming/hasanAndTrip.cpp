#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  long long x[n],y[n],j[n];
  long double dp[n];
  for(int i=0;i<n;i++)
  {
        cin>>x[i]>>y[i]>>j[i];
  	  dp[i]=-DBL_MAX;
  }
  
    dp[0]=j[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
           dp[i]=max(dp[i],dp[j]-sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
        dp[i]=dp[i]+j[i];
    }
    
  cout<<fixed<<setprecision(6)<<dp[n-1];
  return 0;
}
