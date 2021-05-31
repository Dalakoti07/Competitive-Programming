#include<bits/stdc++.h>
using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
	vector<vector<int>> dp=vector<vector<int>>(height,vector<int>(width,0));
	
	if(height==1 || width==1)
		return 1;
	
	//make dp array
	//last row
	for(int i=0;i<width;i++)
		dp[height-1][i]=1;
	//last col 
	for(int j=0;j<height;j++)
		dp[j][width-1]=1;
	dp[height-1][width-1]=0;
  //fill other dp cells
	for(int i=height-2;i>=0;i--){
		for(int j=width-2;j>=0;j--){
			//cout<<i<<":"<<j<<endl;
			dp[i][j]=dp[i+1][j]+dp[i][j+1];
		}
	}
	return dp[0][0];
}
