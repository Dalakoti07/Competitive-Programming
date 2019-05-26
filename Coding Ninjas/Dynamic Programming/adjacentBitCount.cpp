#include <bits/stdc++.h>
using namespace std;

//#define mody 1000000000+7;
int mody=pow(10,9)+7;
long long int dp[101][101][2];

long long int go(long long int n,long long int k,long long int first_bit)
{
  if(k<0)
    return 0;
  else if(n==1)
  {
    if(k==0)
      return 1;
    else
      return 0;
  }
  if(dp[n][k][first_bit]!=-1)
    return dp[n][k][first_bit];
  if(first_bit==0)
	{
    	long long int answer=(go(n-1,k,0)+go(n-1,k,1))%mody;
  		dp[n][k][0]=answer;//%mody;
    	return answer;  
  	}
  else
    {
		long long int answer=(go(n-1,k,0)+go(n-1,k-1,1))%mody;
  		dp[n][k][1]=answer;//%mody;
    	return answer;
  }
}

int main()
{
  	// filling the dp array with -1 
  	for(int i=0;i<101;i++)
      for(int j=0;j<101;j++)
        for(int k=0;k<2;k++)
          dp[i][j][k]=-1;
  
  	int test,i=1;
  	cin>>test;
  	// let us create a dp array for memoization
  	while(test--)
    {
      int x,y,z;
      cin>>x>>y>>z;
      cout<<i++<<" "<<(go(y,z,0)+go(y,z,1))%mody<<endl;
        // take the modulus here also, silly mistakes
    }
    return 0;
}
