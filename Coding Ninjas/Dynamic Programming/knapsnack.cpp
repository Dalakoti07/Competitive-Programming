int knapsack(int* weights, int* values, int n, int maxWeight)
{
    // make a dp solution and use toogling by the help of ^ to minimize the 
    int** dp=new int*[2];
    for(int i=0;i<=1;i++)
        dp[i]=new int[maxWeight];
    //dp of size n and maximum weight
    for (int j=0;j<=maxWeight;j++)
            dp[0][j]=0;
    
    int flag=1;
    for(int i=1;i<=n;i++,flag=flag^1)// update the flag in each iteration
        for(int j=1;j<=maxWeight;j++)
        {
            if(weights[i-1]<=j)
            {// add to the list 
                dp[flag][j]=max(values[i-1]+dp[flag^1][j-weights[i-1]],dp[flag^1][j]);
            }
            else
            {
                dp[flag][j]=dp[flag^1][j];                
            }
        }
    return dp[flag^1][maxWeight];
}