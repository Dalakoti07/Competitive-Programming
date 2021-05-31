#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> dp(n+1);
	dp[0]=1;// no of ways to make coin changes when target is 0 is 1 only, that is no coin at all
	//this implementation is optimization as 2d dp is required, but we are using only one D array
	//this above dp array would store ways to make changes when index i target
	if(n==0)
		return 1;
	for(int i=0;i<denoms.size();i++){
		int current_denomination=denoms[i];
		for(int j=1;j<=n;j++){
			if(current_denomination<=j)
				dp[j]+=dp[j-current_denomination];
		}
	}
    return dp[n];
}
