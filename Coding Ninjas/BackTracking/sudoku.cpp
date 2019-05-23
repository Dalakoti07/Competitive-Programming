bool is_possible(int board[][9],int x,int y,int n)// x and y are the row and column which contain 0 and we are to check if x can put in [x][y] coordinate or not
{
	//row wise
	for(int i=0;i<9;i++)
		if(board[x][i]==n)
			return false;
	//column wise
	for(int i=0;i<9;i++)
		if(board[i][y]==n)
			return false;
	//box wise
	int i=(x/3)*3,j=(y/3)*3,r_e=i+3,c_e=j+3;
	for(;i<r_e;i++)
		for(j=(y/3)*3;j<c_e;j++)
			if(board[i][j]==n)
				return false;
	return true;
}

bool sudokuSolver(int board[][9])
{
  	// traverse the whole sudoku board if u didnot get any empty space that means u are done return true
	int x=-1,y=-1;
	for(int i=0,j;i<9;i++)
		{for(j=0;j<9;j++)
					if(board[i][j]==0)
						{x=i,y=j;break;}
			if(j!=9)
				break;
		}
	if(x==-1 and y==-1)
			return true;// no empty element found so done
	for(int n=1;n<=9;n++)
	{
		if(is_possible(board,x,y,n))
			{
				board[x][y]=n;
				if(sudokuSolver(board))
					{//cout<<"We did right ";
                	  return true;
                	}
				else
					{//cout<<"backtracking ";
                  		board[x][y]=0;
                	}// what if no next comming n fts in ,then we have to backtrack by saying that this current n is not possible
			}
	}
	return false;
}
