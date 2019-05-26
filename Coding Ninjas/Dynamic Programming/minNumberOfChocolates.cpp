#include<bits/stdc++.h>
int getMin(int *arr, int n)
{
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */
	// wow it is dp problem, when we dependencies on left and right, first go to left to right, then right to left
  int dp[n];
  //setting things right from left to right
	dp[0]=1;
  for(int i=1;i<=n-1;i++)
      {
      if(arr[i]>arr[i-1])
        dp[i]=dp[i-1]+1;
      else
        dp[i]=1;
    	}
  	if(arr[n-1]>arr[n-2])
      dp[n-1]=dp[n-2]+1;
  	else
      dp[n-1]=1;
  //now settings things from right to left
  for(int i=n-2;i>=0;i--)
  {
    if(arr[i]>arr[i+1])
    { 
      if(dp[i]>dp[i+1])//silly mistake here
     	;
      else
        dp[i]=dp[i+1]+1;
     }
  }
  int count=0;
	for(int i=0;i<n;i++)
	count+=dp[i];
  return count;
  }