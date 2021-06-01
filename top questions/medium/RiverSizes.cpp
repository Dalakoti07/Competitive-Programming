#include <bits/stdc++.h>
using namespace std;

int exploreAllSurroundings(vector<vector<int>>& matrix,
		int i,int j,vector<vector<bool>>& visited,int rows, int cols){
	if(i==rows || j==cols || i==-1 || j==-1)
		return 0;
	if(visited[i][j])
		return 0;
	if(matrix[i][j]==0)
		return 0;
	visited[i][j]=true;
	return 1 + exploreAllSurroundings(matrix,i+1,j,visited,rows,cols) 
		+ exploreAllSurroundings(matrix,i,j+1,visited,rows,cols)
		+ exploreAllSurroundings(matrix,i-1,j,visited,rows,cols)
		+ exploreAllSurroundings(matrix,i,j-1,visited,rows,cols);
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	vector<int> answers=vector<int>();
	if(matrix.size()==0)
		return {};
	int rows=matrix.size();
	int cols=matrix[0].size();
	vector<vector<bool>> visited=vector(rows,vector<bool>(cols,false));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(!visited[i][j] and matrix[i][j]==1){
				answers.push_back(exploreAllSurroundings(matrix,i,j,visited,rows,cols));
			}
		}
	}
	
    return answers;
}
