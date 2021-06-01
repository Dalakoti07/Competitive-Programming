#include <vector>
using namespace std;

void DFS(vector<vector<int>>& matrix,int i,int j,int rows
	,int cols,vector<vector<int>>& visited){
	if(i==-1 or j==-1 or i==rows or j==cols)
		return;
	if(visited[i][j])
		return;
	if(matrix[i][j]==0){
		visited[i][j]=true;
		return;	
	}
	if(matrix[i][j]==1){
		matrix[i][j]=2;
		visited[i][j]=true;
		DFS(matrix,i+1,j,rows,cols,visited);
		DFS(matrix,i,j+1,rows,cols,visited);
		DFS(matrix,i-1,j,rows,cols,visited);
		DFS(matrix,i,j-1,rows,cols,visited);
	}
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
	int rows=matrix.size();
	if(rows==0)
		return matrix;
	int cols=matrix[0].size();
	auto visited=vector<vector<int>>(rows,vector<int>(cols,false));
	//first row and last row
	for(int i=0;i<cols;i++){
		DFS(matrix,0,i,rows,cols,visited);
		DFS(matrix,rows-1,i,rows,cols,visited);
	}
	//last col and first col
	for(int i=0;i<rows;i++){
		DFS(matrix,i,0,rows,cols,visited);
		DFS(matrix,i,cols-1,rows,cols,visited);
	}
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++){
			if(matrix[i][j]==1)
				matrix[i][j]=0;
			else if(matrix[i][j]==2)
				matrix[i][j]=1;			
		}
    return matrix;
}
