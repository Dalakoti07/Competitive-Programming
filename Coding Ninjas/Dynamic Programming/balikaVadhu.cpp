#include <bits/stdc++.h>
using namespace std;

int go(string b1,string b2,int k)
{
    int m=b1.length(),n=b2.length();
    int dp[m+1][n+1][k+1]={0};
    
    for(int x=0;x<=k;x++)
        {
        for(int j=0;j<=m;j++)
            for(int i=0;i<=n;i++)
                dp[j][i][x]=0;
        }
    //set the base case ,means if we take last 0 chara of str1 and str2 of any k value
    // if k is zero then whole 2D array is zero
    // answer would be at dp[m][n][k], which is dependent on dp[m-1][n-1][k] or something else 
    
    //set all the 2D matrix's 1st row and col as INT_MIN
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=m;j++)
            dp[j][0][i]=INT_MIN;// col

        for(int j=0;j<=n;j++)
            dp[0][j][i]=INT_MIN;//row
    }
    
    for(int x=1;x<=k;x++)
    {
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(b1[m-i]==b2[n-j])
                {
                    dp[i][j][x]=max(int(b1[m-i])+dp[i-1][j-1][x-1],max(dp[i][j-1][x],dp[i-1][j][x]));
                    //if(dp[i][j][x]==INT_MIN)
                      //  dp[i][j][x]=0;
                }
                else
                {
                    dp[i][j][x]=max(0,max(dp[i-1][j][x],dp[i][j-1][x]));
                    //if(dp[i][j][x]==INT_MIN)
                      //  dp[i][j][x]=0;
                }
            }
    }
    /*for(int x=0;x<=k;x++,cout<<endl<<endl)
        for(int j=0;j<=m;j++,cout<<endl)
            for(int i=0;i<=n;i++)
                cout<<dp[j][i][x]<<" ";
    */
    return dp[m][n][k];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string b1,b2;
        cin>>b1>>b2;
        int k;
        cin>>k;
        int answer=go(b1,b2,k);
        cout<<"int min "<<INT_MIN<<"   ";
        if(answer==INT_MIN)
            cout<<0<<endl;
        else
            cout<<answer<<endl;
    }
    return 0;
}
