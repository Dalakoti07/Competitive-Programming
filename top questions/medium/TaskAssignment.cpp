#include <bits/stdc++.h>
using namespace std;

bool customComparator(pair<int,int>& one,pair<int,int>& two){
	if(one.first==two.first)
		return one.second<two.second;
	return one.first<two.first;
}

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
	vector<vector<int>> answer;
	vector<pair<int,int>> tasksWithIndex;
	int index=0;
	for(int t :tasks){
		tasksWithIndex.push_back({t,index});
		index++;
	}
	sort(tasksWithIndex.begin(),tasksWithIndex.end(),customComparator);
	for(int i=0;i<k;i++){
		answer.push_back({tasksWithIndex[i].second,tasksWithIndex[(2*k)-i-1].second});
	}
  return answer;
}
