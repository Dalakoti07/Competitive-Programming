#include <bits/stdc++.h>
using namespace std;

bool go(int arr[],int n,int k)
{
    bool **dp=new bool*[2];
    for(int i=0;i<=1;i++)
        dp[i]=new bool [k+1];
    
    for(int i=1;i<=k;i++)
        dp[0][i]=0;
    dp[0][0]=1;
    int flag=1;
    // see how a overlapping subsequence of recursion is made dp , in rec we give k and different array size to the rec , and this in rec causes TLE ,but as only array size and k value changes thus we mainatain a dp array
    for(int i=1;i<=n;i++,flag=flag^1)// change the flag after each iteration
        for(int j=1;j<=k;j++)
        {
            if(j-arr[i-1]>=0) // to escape form the base case in rec like if k<=0 then return 0, here we avoid such cases and change value if we have correct index
                dp[flag][j]=dp[flag^1][j-arr[i-1]] || dp[flag^1][j];                   
            else
                dp[flag][j]=dp[flag^1][j];
        }
    return dp[flag^1][k];// if we consider all the elements of the array and k
}

int main()
{
    // one more thing to take away from this questio is that ,if we have only two rows in dp then toogle them as per need by the help of the ^ operator
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    if(go(arr,n,k))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
