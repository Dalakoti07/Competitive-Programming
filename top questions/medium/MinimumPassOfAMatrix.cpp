#include <bits/stdc++.h>
using namespace std;

bool ifContainsNegative(vector<vector<int>>& matrix){
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			if(matrix[i][j]<0)
				return true;
		}
	}
	return false;
}

queue<pair<int,int>> getAllPositivesNos(vector<vector<int>>& matrix){
	queue<pair<int,int>> positives;
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			if(matrix[i][j]>0)
				positives.push({i,j});
		}
	}
	return positives;
}

vector<vector<int>> getAdjacentElemes(vector<vector<int>>& matrix
,pair<int,int> currentElem){
	vector<vector<int>> neighbours;
	int rows=matrix.size();
	int cols=matrix[0].size();
	
	int row=currentElem.first;
	int col=currentElem.second;
	if(col>0)//left
		neighbours.push_back({row,col-1});
	if(col<cols-1)//right
		neighbours.push_back({row,col+1});
	if(row>0)//top
		neighbours.push_back({row-1,col});
	if(row<rows-1)//bottom
		neighbours.push_back({row+1,col});
	return neighbours;
}

int removeAllNegatives(vector<vector<int>>& matrix){
	int passes=0;
	
	queue<pair<int,int>> currentQueue;
	queue<pair<int,int>> nextQueue;
	nextQueue=getAllPositivesNos(matrix);
	while(nextQueue.size()!=0){
		currentQueue=nextQueue;
		nextQueue=queue<pair<int,int>>();
		while(currentQueue.size()!=0){
			pair<int,int> currentElem=currentQueue.front();
			currentQueue.pop();
			vector<vector<int>> adjacentElements=getAdjacentElemes(matrix,currentElem);
			for(auto elem :adjacentElements){
				int row=elem[0];
				int col=elem[1];
				if(matrix[row][col]<0){
					matrix[row][col]*=-1;
					nextQueue.push({row,col});
				}
			}		
		}
		passes++;
	}
	return passes;
}

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
	int passes=removeAllNegatives(matrix);
	
  return ifContainsNegative(matrix)? -1: passes-1;
}
