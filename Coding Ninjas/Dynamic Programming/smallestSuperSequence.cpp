
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int **dp=new int*[len1+1];
    for(int i=0;i<=len1;i++)
        dp[i]=new int[len2+1];
    //fill the last row and last column
    for(int i=len1,x=0;x<=len1;i--,x++)
        dp[x][len2]=i;
    for(int i=len2;i>=0;i--)
        dp[len1][len2-i]=i;
    dp[len1][len2]=0;
    // fill the other dp elements
    for(int i=len1-1;i>=0;i--)
        for(int j=len2-1;j>=0;j--)
        {
            if(str1[i]==str2[j])
                dp[i][j]=1+dp[i+1][j+1];
            else
                dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
        }
    return dp[0][0];
}