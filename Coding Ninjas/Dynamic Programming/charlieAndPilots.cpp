#include <bits/stdc++.h>
using namespace std;

int go(int c[],int a[],int n,int x,int **dp)
{
    // x is assistant - captain
    if(n==0)
        return 0;
    if(x>=0)
    if(dp[n][x]!=-1)
        return dp[n][x];
    if(x==0)
    {
        if(x>=0)
        {dp[n][x]= a[0]+go(c+1,a+1,n-1,1,dp);// we have first piolt as assistant
        return dp[n][x];}
        else
            return a[0]+go(c+1,a+1,n-1,1,dp);
    }
    if(x==n)
    {
        if(x>=0)
        {dp[n][x]= c[0]+go(c+1,a+1,n-1,x-1,dp);// make it as the captain as we have no other choice
        return dp[n][x];}
        else
            return c[0]+go(c+1,a+1,n-1,x-1,dp);
    }
    else
    {
        if(x>=0)
        {dp[n][x]=min(a[0]+go(c+1,a+1,n-1,x+1,dp),c[0]+go(c+1,a+1,n-1,x-1,dp));return dp[n][x];}
        return min(a[0]+go(c+1,a+1,n-1,x+1,dp),c[0]+go(c+1,a+1,n-1,x-1,dp));// now a pilot can either be assistant or captain
    }
}

int main()
{
    int n;
    cin>>n;
    int c[n],a[n];
    for(int i=0;i<n;i++)
        cin>>c[i]>>a[i];
    // a pilot can be either captain or assistant
    int **dp =new int* [n+1];
    for(int i=0;i<=n;i++)
    {
            dp[i]=new int[n/2+1];
        for(int j=0;j<=n/2;j++)
            dp[i][j]=-1;
    }
    
    cout<<go(c,a,n,0,dp);
    return 0;
}
