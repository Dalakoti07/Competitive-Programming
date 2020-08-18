#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// or refer codechef editorialist solution
ll dp[1001][1001], fmat[1001][1001];

ll minpart(ll arr[], ll i, ll j, ll cost){
    if (i==j){
        return 0;
    }
    if (dp[i][j] != 60000){
        return dp[i][j];
    }
    ll ans = 10000;
    for (ll k=i;k<j;k++)
    {
        ll total =fmat[i][k];
        dp[i][k]=total;
        ll count =(minpart(arr, k+1, j, cost)+total);
        ans =min(ans, count);
    }
    dp[i][j]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll i, j, t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for (i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for (i=0;i<1001;i++)
            for (j=0;j<1001;j++)
                dp[i][j]=60000;
        
        memset(fmat, -1, sizeof(fmat));
        
        for (i=0;i<n;i++)
        {
            unordered_map<ll, ll>dic;
            ll total =k;
            for (j=i;j<n;j++)
            {
                dic[arr[j]]+=1;
                if (dic[arr[j]]>1)
                {
                    if (dic[arr[j]]==2)
                    {
                        total+=2;
                    }
                    else
                    {
                        total+=1;
                    }
                }
                fmat[i][j]=total;
            }
        }
        cout<<minpart(arr, 0, n, k)<<"\n";
    }
    return 0;
}