
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
	int dp[numDenominations+1][value+1];
  	for(int i=0;i<=numDenominations;i++)
      for(int j=0;j<=value;j++)
        dp[i][j]=-1;
  	
  	//fill the dp array- now dp array has 
  	for(int i=0;i<=value;i++)
      dp[0][i]=0;// if donot have any denominations at all then count of doing the changes is zero
  	for(int i=1;i<=numDenominations;i++)
      dp[i][0]=1;// if we have value as zero then ways to give change is 1,that is by giving nothing 

  	//answer would be at dp[n][m] becoz we have maximum value and we have used all the denomination available to us
  	for(int i=1;i<=numDenominations;i++)
      for(int j=1;j<=value;j++)
        {
        if(j-denominations[i-1]>=0)
        	dp[i][j]=dp[i-1][j]+dp[i][j-denominations[i-1]];//denominations[i-1] becoz elements in denominations are from zero  
		else
	          dp[i][j]=dp[i-1][j];
    	}
  /*for(int i=0;i<=numDenominations;i++,cout<<endl)
    for(int j=0;j<=value;j++)
      cout<<dp[i][j]<<" ";*/
  return dp[numDenominations][value];
}
