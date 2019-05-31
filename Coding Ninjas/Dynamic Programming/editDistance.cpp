#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    /*One most important catch in this algo is that if we made string 1 and string 2 to some intermediate string, or made string1 to string 2 or vice versa the cost is going to be same*/
    int m=s1.length(),n=s2.length();
    int **dp= new int*[m+1];
    for(int i=0;i<m+1;i++)
        dp[i]=new int[n+1];
    // dp[i][j] means edit distance of last i and j characters of the strings
    for(int i=0;i<=n;i++)
        dp[0][i]=i;
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(s1[m-i]==s2[n-j])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                int a,b,c;
                a=dp[i-1][j-1];
                b=dp[i-1][j];
                c=dp[i][j-1];
                dp[i][j]=1+min(a,min(b,c));
            }
        }
    return dp[m][n];
}
