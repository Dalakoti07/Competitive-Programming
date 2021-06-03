#include <vector>
using namespace std;

vector<vector<int>> powersetHelper(vector<int> array,int idx,int size){
	vector<vector<int>> answer;
	if(size==0){
		//power set of empty array is empty array :)
		answer.push_back({});
		return answer;		
	}
	if(size==1){
		answer.push_back({});
		answer.push_back({array[idx]});
		return answer;
	}
	vector<vector<int>> rightPowerSet=powersetHelper(array,idx+1,size-1);
	answer=rightPowerSet;
	int len=rightPowerSet.size();
	for(int i=0;i<len;i++){
		auto _ans=rightPowerSet[i];
		_ans.push_back(array[idx]);
		answer.push_back(_ans);
	}
	return answer;
}

vector<vector<int>> powerset(vector<int> array) {
    return powersetHelper(array,0,array.size());
}
