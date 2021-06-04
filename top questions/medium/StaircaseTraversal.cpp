#include<bits/stdc++.h>
using namespace std;

int staircaseTraversal(int height, int maxSteps) {
	// brute force solution uses recursion, 
	// like ways to climbs 5 steps, when maxSteps is 2 would be 
	// ways to (climbs[4] + climbs[3])	
	// remember we are not doing ways to (climbs[4]*climb[1] + climbs[3]*climb[2])	
	// as this above approach would do over-couting, do take pen paper and realise
	
	// we should create DP solution for above rec solution as we have lots of subproblems
	
	// but DP solution would also have n*k complexity and 
	// to avoid that we can use sliding window approach
	
	int currentNumberOfWays=0;//currentWindowSum
	//dp[i] stores the window size 
	vector<int> dp(height+1);
	dp[0]=1;
	for(int currentHeight=1;currentHeight<height+1;currentHeight++){
		int startOfWindow=currentHeight - maxSteps -1;
		int endOfWindow=currentHeight -1;
		if(startOfWindow>=0){
			currentNumberOfWays-=dp[startOfWindow];
		}
		currentNumberOfWays+=dp[endOfWindow];
		dp[currentHeight]=currentNumberOfWays;
	}
	
    return dp[height];
}
