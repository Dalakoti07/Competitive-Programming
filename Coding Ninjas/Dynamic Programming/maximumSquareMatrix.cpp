#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col)
{    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int dp[row][col];
  //fill the 0th column
  for(int i=0;i<row;i++)
    dp[i][0]=(arr[i][0]==0)?1:0;
  //fill the 0th row
  for(int i=0;i<col;i++)
    dp[0][i]=(arr[0][i]==0)?1:0;
  
  //fill the remaining array
  for(int i=1;i<row;i++)
    for(int j=1;j<col;j++)
      {
      	if(arr[i][j]==0)
        	dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
    	else
          dp[i][j]=0;
      }
  int max_m=0;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(dp[i][j]>max_m)
        max_m=dp[i][j];
  return max_m;
}
