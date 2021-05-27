#include<bits/stdc++.h>
using namespace std;

//approach is perimeter approach 
vector<int> spiralTraverse(vector<vector<int>> array) {
	if(array.size()==0)
		return {};
	
	vector<int> answer=vector<int>();
	int startRow=0,endRow=array.size()-1;
	int startColumn=0,endColumn=array[0].size()-1;
	
	while(startRow<=endRow && startColumn<=endColumn){
		// traverse top perimeter
		for(int col=startColumn;col<=endColumn;col++){
			answer.push_back(array[startRow][col]);
		}
		//then right col
		for(int row=startRow+1;row<=endRow;row++){
			answer.push_back(array[row][endColumn]);
		}
		//then bottom row
		for(int col=endColumn-1;col>=startColumn;col--){
			// handling the edge case whee there is single row 
			// in middle of matrix. In this code we dont want to
			// double count the values in this row, which we're already counted 
			// in first for loop above
			if(startRow==endRow)
					break;
			answer.push_back(array[endRow][col]);
		}
		//then left col
		for(int i=endRow-1;i>=startRow+1;i--){
			//handling same as above edge case
			if(startColumn==endColumn)
					break;
			answer.push_back(array[i][startColumn]);
		}
		// push coordinates inside
		startRow++;
		endRow--;
		startColumn++;
		endColumn--;
	}
	
  return answer;
}
