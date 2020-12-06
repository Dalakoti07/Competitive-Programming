int lcs(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
                continue;                
            }
            
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

/*    for(int i=0;i<=x;i++,cout<<endl)
        for(int j=0;j<=y;j++)
            cout<<dp[i][j]<<" ";*/
    
    return dp[x][y];
}