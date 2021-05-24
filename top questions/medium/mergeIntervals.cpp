#include <bits/stdc++.h>
using namespace std;

bool customComp(vector<int> a,vector<int> b){
	if(a[0]==b[0])
		return a[1]<b[1];
	return a[0]<b[0];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
	sort(intervals.begin(),intervals.end(),customComp);
    vector<vector<int>> answers;
	if(intervals.size()==0)
		return answers;
	int endPoint=intervals[0][1];
	int startPoint=intervals[0][0];
	for(int idx=1;idx<intervals.size();idx++){
		if(endPoint>=intervals[idx][0]){
			endPoint=max(intervals[idx][1],endPoint);
		}else{
			answers.push_back(vector<int>{startPoint,endPoint});
			startPoint=intervals[idx][0];
			endPoint=intervals[idx][1];
		}
	}
	answers.push_back(vector<int>{startPoint,endPoint});
	return answers;
}
