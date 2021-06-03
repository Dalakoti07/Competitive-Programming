#include <bits/stdc++.h>
using namespace std;

void print2DArray(vector<vector<int>> array){
	for(auto a:array){
		for(int i :a)
			cout<<i<<" ";
		cout<<endl;
	}
}

vector<vector<int>> getPermuationsHelper(vector<int>  array,int start, int size){
	/*for(int i=start;i<array.size();i++)
		cout<<array[i]<<" ";
	cout<<endl;
	*/
	vector<vector<int>> answer=vector<vector<int>>();
	if(size==0)
		return {};
	if(size==1){
		answer.push_back({array[start]});		
		return answer;
	}
	vector<vector<int>> remainingPermutation=getPermuationsHelper(array,start+1,size-1);
	//print2DArray(remainingPermutation);
	for(auto perm : remainingPermutation){
		for(int insertAt=0;insertAt<=perm.size();insertAt++){
			vector<int> currentVec=perm;
			currentVec.insert(currentVec.begin()+insertAt,array[start]);
			answer.push_back(currentVec);
		}
	}
	return answer;
}

vector<vector<int>> getPermutations(vector<int> array) {
	return getPermuationsHelper(array,0,array.size());
}
