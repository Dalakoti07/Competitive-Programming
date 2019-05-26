#include<bits/stdc++.h>
/*int minCount(int n,int dp[]){
    
    // the idea is simple and straight forward and simple and says that we use recursive definition 
  	if(n<=3)
      return n;// that is for n=0,1,2 we have 1^2+............. and that is all the answer possible and that is minimum too
	
  	int answer=n; //this is because we will have answer as 1^2+1^2+......... as the answer in the worst case
  	if(dp[n]!=-1)
      return dp[n];
  for(int i=1;i<=sqrt(n);i++)
    {
      //we will call the recursive fun that we ahve taken one step and next you tell what wold be the next answer
      // do not necessarily take the number which are divisible by the number n
      answer=min(answer,1+minCount(n-i*i,dp));// either current answer is minimum or if we take one step which is square of the current number which is divisible by the number, and let the rec find the minimum count for the number-(divisble)^2, and then we add 1 to it at last
    }
	  dp[n]=answer;
	return answer;
}*/
int minCount(int n)
{
  int arr[1001];
  arr[0]=0;
  arr[1]=1;
    arr[2]=2;
    arr[3]=3;
  for(int i=4;i<=n;i++)
  {
    // put the recursive equations here or do the magic here
    int local_answer=i;
    for(int j=1;j<=sqrt(i);j++)
    {
      local_answer=min(local_answer,1+arr[i-j*j]);
    }
    arr[i]=local_answer;
  }
    return arr[n];
}