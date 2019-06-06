#include <bits/stdc++.h>
using namespace std;

pair<int,int> go(int cost[],int fun[],int n,int budget)
{
    int** dp=new int*[n+1];//[][budget+1];
	for(int i=0;i<=n;i++)
		dp[i]=new int[budget+1];
    // in dp[i][j] if we include i parties and j budget then what would be the cost
    // if we have 0 parties then no cost, and if we have 0 budget then no parties
    for(int i=0;i<=n;i++)
        dp[i][0]=0;// furst col made zero
    for(int i=0;i<=budget;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {       
        for(int j=1;j<=budget;j++)
        {
            if(cost[i-1]<=j)
                dp[i][j]=max(fun[i-1]+dp[i-1][j-cost[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    } 
    // search or traverse only the last row ,which says that you have taken all the events into consideration and search which budget give the maximum joy
    int max=INT_MIN,index=-1;
        for(int j=0;j<=budget;j++)
            if(dp[n][j]>max)
                {max=dp[n][j];index=j;}
     for(int i=0;i<=n;i++)
		delete[] dp[i];
    //cout<<dp[i][j]<<" ";
    return make_pair(max,index);
}

int main()
{
    int n,k;
    cin>>n>>k;
    while(n!=0 and k!=0)
    {
        int cost[k],fun[k];
       // memset(cost,0,sizeof(cost));
       // memset(fun,0,sizeof(fun));
        
        for(int i=0;i<k;i++)
            cin>>cost[i]>>fun[i];
        pair<int,int >answer=go(cost,fun,k,n);
        cout<<answer.second<<" "<<answer.first<<endl;
        cin>>n>>k;
    }
    return 0;
}
