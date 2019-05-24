#include <bits/stdc++.h>
using namespace std;

int go(int arr[][500],int r,int c)
{
  	int dp[r][c];
  	//fill the dp array last row
  dp[r-1][c-1]=1;// dp array store the minimum health u should have in order to go from i,j to n,n
  //fill the last row
  for(int i=c-2;i>=0;i--)
    dp[r-1][i]=(dp[r-1][i+1]-arr[r-1][i+1]);
  //fill the last column
  for(int i=r-2;i>=0;i--)
    dp[i][c-1]=(dp[i+1][c-1]-arr[i+1][c-1]);
  
  //fill the remaining dp array
  for(int i=r-2;i>=0;i--)
    for(int j=c-2;j>=0;j--)
      {
      	dp[i][j]=min((dp[i][j+1]-arr[i][j+1]),(dp[i+1][j]-arr[i+1][j]));
    	if(dp[i][j]<=0)// if the minimum enrgy required drops to -ve or zero
          dp[i][j]=1;
    }
  
  /*for(int i=0;i<r;i++,cout<<endl)
    for(int j=0;j<c;j++)
      cout<<dp[i][j]<<" ";
  cout<<endl;*/
  return dp[0][0];
}

int main()
{
  	int test;
  	cin>>test;
  	int arr[500][500];
  	while(test--)
    {
      int r,c;
      cin>>r>>c;
      for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
          cin>>arr[i][j];
      cout<<go(arr,r,c)<<endl;
    }
    return 0;
}
