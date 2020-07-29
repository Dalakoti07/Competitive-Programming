#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll dp[62][10002];
ll arr[62];
ll gcd(ll a,ll b)
{
    ll c;
    if(b>a)
    {
        c=a;
        a=b;
        b=c;
    }
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
ll recurse(ll pos,ll num,ll n)
{
    cout<<"elemVisted: "<<pos<<" and n: "<<n<<" curent gcd: "<<num<<endl;
    if(pos==n+1)
    {
        /*if(num==arr[pos])
            dp[pos][num]=1;
        else
            dp[pos][num]=0;
        return dp[pos][num];*/
        if(num==1){
        	cout<<"returned 1\n";
			return 1;

		}
        else{
            cout<<"returned 0\n";
			return 0;

		}
    }
    else if(dp[pos][num]!=-1)
        return dp[pos][num];
    else
    {
        dp[pos][num]=recurse(pos+1,num,n)+recurse(pos+1,gcd(arr[pos],num),n);
        return dp[pos][num];
    }
}
int main(void)
{
    ll i,j,k,n,t;
    scanf("%lld",&t);
    while(t--)
    {
        for(i=0;i<=61;i++)
        {
            for(j=0;j<=10001;j++)
                dp[i][j]=-1;
        }
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        j=0;
        for(i=1;i<=n;i++)
            j+=recurse(i+1,arr[i],n);
        printf("%lld\n",j);
    }
    return 0;
}
