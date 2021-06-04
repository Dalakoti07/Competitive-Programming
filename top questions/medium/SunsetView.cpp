#include<bits/stdc++.h>
using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
	vector<int> indexes;
	int n =buildings.size();
	if(n==0) return {};
	if(n==1)
		return {0};
	if(direction=="WEST"){
		//from left to right
		int maxSoFar=buildings[0];
		indexes.push_back(0);
		for(int i=1;i<n;i++){
			if(buildings[i]>maxSoFar){
				maxSoFar=buildings[i];
				indexes.push_back(i);
			}
		}
	}else{
		//from right to left
		int maxSoFar=buildings[n-1];
		indexes.push_back(n-1);
		for(int i=n-2;i>=0;i--){
			if(buildings[i]>maxSoFar){
				maxSoFar=buildings[i];
				indexes.push_back(i);
			}
		}
		reverse(indexes.begin(),indexes.end());
	}
	return indexes;
}
