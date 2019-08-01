#include <bits/stdc++.h>
using namespace std;
// this is not a complete solution and thus it is being in debug phase
int go(int o,int c,int n,int** dp,bool places[])
{
    int a,b;
    cout<<"o = "<<o<<" c = "<<c<<" n = "<<n<<endl;
    if(o>n or c>n)
        return 0;
    if(o==n and c==n)
        return 1;
    if(o==c and places[o+c])
        {a= go(o+1,c,n,dp,places);return a;}
    else if(o==n)
        {b= go(o,c+1,n,dp,places);return b;}
    else
        return go(o,c+1,n,dp,places)+go(o+1,c,n,dp,places);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k;
        bool places[2*n];
        for(int i=0;i<2*n;i++)
            places[i]=false;
        for(int i=0;i<k;i++)
        {
            cin>>x;
            places[x-1]=true;
        }
        int** dp=new int*[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        cout<<go(0,0,n,dp,places)<<endl;
    }
    return 0;
}
