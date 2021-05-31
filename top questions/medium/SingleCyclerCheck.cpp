#include<bits/stdc++.h>
using namespace std;

int getNextIndex(int index,vector<int>& arr);

bool hasSingleCycle(vector<int> array) {
	//tricky question to solve
	//one way is to - make auxialiary array of size same as array and then make sure that 
	//while navigation/jumping around array you visit the node at least once
	
	//there is O(1) solution as well
	int visited=0;
	int currentIndex=0;
	if(array.size()==1 || array.size()==0)
		return true;
	int jump;
	int nextNode;
	while(visited<array.size()){
		if(visited>0 and currentIndex==0){
			return false;
		}
		visited++;
		currentIndex=getNextIndex(currentIndex,array);
	}
	
	return currentIndex==0;
}

int getNextIndex(int idx,vector<int>& arr){
	int jump=arr[idx];
	int nextIndex=(idx+jump) % (int)arr.size();
	return nextIndex>=0 ? nextIndex: nextIndex+arr.size();
}
