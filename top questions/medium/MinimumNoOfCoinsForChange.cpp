#include<bits/stdc++.h>
#include <vector>
using namespace std;

//doubt - Will this algorithm work if denomination array is not sorted in ascending
int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	// this is an optimization over using 2D array
	vector<int> dp(n+1,INT_MAX);
	dp[0]=0;// min coins for target 0 is 0
	for(int denom:denoms){
		int current_denomination=denom;
		for(int j=1;j<=n;j++){
			if(current_denomination<=j){
				if( dp[j-current_denomination] !=INT_MAX)
					dp[j]=min(dp[j],dp[j-current_denomination]+1);
				else
					dp[j]=min(dp[j],dp[j-current_denomination]);
			}
		}
	}
    return dp[n] !=INT_MAX ? dp[n]:-1;
}
