bool is_valid(int n,int row,int column,int board[][11])
{
	// see in the given row
	for(int i=0;i<n;i++)
		if(board[row][i]==1)
			return false;
	//see in the column
	for(int i=0;i<n;i++)
		if(board[i][column]==1)
			return false;
	//see the diagonal from bottom left to top right
	for(int a=row,b=column;a<=n-1 and b>=0 ;a++,b--)
		if(board[a][b]==1)
			return false;
	for(int a=row,b=column;a>=0 and b<=n-1 ;a--,b++)
		if(board[a][b]==1)
			return false;
	// see the diagonal from top left to bottom right
	for(int a=row,b=column;a<=n-1 and b<=n-1 ;a++,b++)
		if(board[a][b]==1)
			return false;
	for(int a=row,b=column;a>=0 and b>=0;a--,b--)
		if(board[a][b]==1)
			return false;
	return true;
}

bool get_config(int n,int row,int board[][11])
{
	if(row==n)
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					cout<<board[i][j]<<" ";
			cout<<endl;
			return true;
		}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(is_valid(n,row,i,board))
				{
					board[row][i]=1;
					get_config(n,row+1,board);
					// if the config was possible then it would have printed,we are not to return and explore the other answers
					board[row][i]=0;
					// clearing the mess that we created
				}
		}
	return false;
	}
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
  int board[11][11]={0};
	get_config(n,0,board);
}
