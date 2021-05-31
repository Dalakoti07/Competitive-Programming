#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
	//it uses dp as solution dp[i] means max sum when subset ends at index i, 
	//it may have started at another other index
	vector<int> dp(array.size());
	dp[0]=array[0];
	int answer=dp[0];
	for(int i=1;i<array.size();i++){
		dp[i]=max(array[i],dp[i-1]+array[i]);
		answer=max(answer,dp[i]);
	}
    return answer;
}