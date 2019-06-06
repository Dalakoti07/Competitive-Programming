#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int dp[n][m];
    int arr[n][m];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {cin>>arr[i][j];dp[i][j]=arr[i][j];}
    
    // making the dp solution changing the arr itself
    // flaw in the previous algo was that we are pcking left and right and below elements but we are discontinuing that
    int answer=INT_MAX;
    for(int i=n-2;i>=0;i--)
        {
            //handling the first element of every row
            dp[i][0]+=min(dp[i+1][0],dp[i+1][1]);
             for(int j=1;j<m-1;j++)
            {
                dp[i][j]+=min(dp[i+1][j+1],min(dp[i+1][j],dp[i+1][j-1]))    ;                 
            }
            // handling the last col
            dp[i][m-1]+=min(dp[i+1][m-1],dp[i+1][m-2]);
        }
    for(int i=0;i<n;i++)
        if(answer>dp[0][i])
            answer=dp[0][i];
    /*for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        */
        cout<<answer;
    return 0;
}
