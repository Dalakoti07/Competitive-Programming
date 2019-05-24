#include<bits/stdc++.h>
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
	
  int dp[n]={0};
	dp[0]=arr[0];
  	dp[1]=(arr[0]>arr[1])?arr[0]:arr[1];
  for(int i=2;i<n;i++)
    dp[i]=((arr[i]+dp[i-2])>dp[i-1])?(arr[i]+dp[i-2]):dp[i-1];
  return dp[n-1];
}
