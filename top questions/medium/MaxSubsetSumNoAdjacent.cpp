#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	vector<int> dp(array.size());
	if(array.size()==0)
		return 0;
	if(array.size()==1)
		return array[0];
	dp[0]=array[0];
	dp[1]=max(array[1],array[0]);
	for(int i=2;i<array.size();i++){
		dp[i]=max(dp[i-1],dp[i-2]+array[i]);
	}
	
    return dp[array.size()-1];
}
