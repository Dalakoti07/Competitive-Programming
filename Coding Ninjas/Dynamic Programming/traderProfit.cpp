#include <bits/stdc++.h>
using namespace std;

int go(int arr[],int n,int k,int ongoing,int dp[][10][2])
{
    if(k==0 or n==0)// no transactions and no elements are remaining
        return 0;
    if(dp[n][k][ongoing]!=INT_MIN)
        return dp[n][k][ongoing];
    if(ongoing)
    {
        dp[n][k][ongoing]= max(go(arr+1,n-1,k,ongoing,dp),arr[0]+go(arr+1,n-1,k-1,false,dp));
        //cout<<dp[n][k][ongoing]<<" ";
        return dp[n][k][ongoing];
    }
    else
    {
        dp[n][k][ongoing]=max(go(arr+1,n-1,k,true,dp)-arr[0],go(arr+1,n-1,k,ongoing,dp));
        //cout<<dp[n][k][ongoing]<<" ";
        return dp[n][k][ongoing];
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int dp[31][10][2];// dp[n][k][2]
        for(int i=0;i<=1;i++)
            for(int j=0;j<=n;j++)
                for(int x=0;x<=k;x++)
                    dp[j][x][i]=INT_MIN;
        cout<<go(arr,n,k,false,dp)<<endl;
    }
    return 0;
}
