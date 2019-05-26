int solve(int n,vector<int>A)
{
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	
  int arr[100001]={0};
  for(int i=0;i<n;i++)
    arr[A[i]]+=1;
  // now traverse this frequency array, which we call the arr array
  //handling the arr[1] seprately
  //make a dp array
  int dp[100001]={0};
  dp[1]=1*arr[1];
  for(int i=2;i<=100000;i++)
    dp[i]=max(dp[i-1],i*arr[i]+dp[i-2]);
  return dp[100000];
}